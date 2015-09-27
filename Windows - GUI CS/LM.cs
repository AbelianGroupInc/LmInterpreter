using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    abstract class LM
    {
        protected const int UNINITIALIZED_ADDRESS = -1;
        protected const int MAX_MEMORY_SIZE = 65536;
        protected bool endFlag;
        protected bool inputFlag;
        protected bool uInputFlag;

        public int currentAddress { get; set; }
        protected Memory ramMemory;

        public LM(){
            ramMemory = new Memory();
            currentAddress = UNINITIALIZED_ADDRESS;
            endFlag = false;
            inputFlag = false;
            uInputFlag = false;
        }

        #region main methods

        public void Init(string programText)
        {
            endFlag = false;
            inputFlag = false;
            uInputFlag = false;
            ClearMemory();
            currentAddress = UNINITIALIZED_ADDRESS;

            InitVariables(Parser.GetParsedInit(programText));
            InitCommands(Parser.GetParsedCode(programText));
        }

        public virtual List<string> GetVarInfo()
        {
            return ramMemory.GetVarInfo();
        }

        public virtual List<string> GetVarInfoInAdditionalCode()
        {
            return ramMemory.GetVarInfoInAdditionalCode();
        }

        public List<string> GetCmdInfo()
        {
            return ramMemory.GetCmdInfo();
        }

        public string GetCurrentCommand()
        {
            return string.Format("{0} {1}", TextFormat.addZeros(Convert.ToString(currentAddress, 16).ToUpper(), 4), ramMemory.GetCell(this.currentAddress).ToString());
        }

        public bool IsEnd()
        {
            return endFlag;
        }

        public bool IsInput()
        {
            return inputFlag;
        }

        public bool IsUnsignedInput()
        {
            return uInputFlag;
        }

        public virtual void DoOneStep(RichTextBox output)
        {
            if (inputFlag)
                return;

            if (uInputFlag)
                return;

            try
            {
                MasterSwitch(output);
            }
            catch (System.Exception exp)
            {
                throw new System.Exception("at address \"" + TextFormat.addZeros(
                    Convert.ToString(currentAddress, 16), 4) + "\" " + exp.Message);
            }
        }

        public virtual void Input(int value)
        {
            LMOperations.PerformInputOperation(this, value);
            inputFlag = false;
            GoToNextAddress();
        }

        public virtual void UnsignedInput(int value)
        {
            LMOperations.PerformInputOperation(this, (ushort)value);
            uInputFlag = false;
            GoToNextAddress();
        }

        public virtual int GetInOutOperand()
        {
            const int FIRST_OPERAND = 1;
            return FIRST_OPERAND;
        }

        public string GetName(int position)
        {
            return ramMemory.GetName(position);
        }

        #endregion

        #region auxiliary methods

        protected virtual void InitVariables(List<AddressValue> variables)
        {
            foreach (var variable in variables)
            {
                if (variable.Name != null)
                    ramMemory.SetName((int)variable.Address, variable.Name);

                if (variable.Value != null)
                    SetVariableInMemory((int)variable.Address, (int)variable.Value);
            }
        }

        protected virtual void InitCommands(List<List<int>> commands)
        {
            foreach (var command in commands)
                InitialiseCommand(command);
        }
        protected virtual void ClearMemory()
        {
            ramMemory.ClearMemory();
        }
        
        protected int GetCurrentCommandNumber()
        {
            return this.ramMemory.GetCell(this.currentAddress).GetValue();
        }

        #endregion

        #region abstract methods
        protected abstract void MasterSwitch(RichTextBox output);
        public abstract void SetVariableInMemory(int positionInMemory, int value);
        protected abstract void InitialiseCommand(List<int> command);
        public abstract void GoToNextAddress();
        protected abstract void CheckNumberOfOperand(int numberOfOperand);
        public abstract int GetValueOperand(int positionInMemory, int numberOfOperand);
        public abstract int GetAddressOperand(int positionInMemory, int numberOfOperand);
        public abstract void SetOperationResultInMemory(MemoryItem arithmeticResult);
        public abstract void SetOperationResultInMemory(MemoryItem divisionResult, MemoryItem module);

        #endregion

    }
}
