using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LM2: LM
    {
        #region Commands defines
            const int 
                CMD_COMPARE                   = 5,
	            CMD_INPUT                     = 6,
	            CMD_OUTPUT                    = 7,
	            CMD_UNSIGNED_INPUT            = 22,
	            CMD_UNSIGNED_OUTPUT           = 23,
	            CMD_ADD                       = 1,
	            CMD_SUBSTRACT                  = 2,
	            CMD_MULTIPLICATION            = 3,
	            CMD_DIVISION                  = 4,
	            CMD_UNSIGNED_MULTIPLICATION   = 19,
	            CMD_UNSIGNED_DIVISION         = 20,
	            CMD_ASSIGMENT                 = 0,
	            CMD_GOTO                      = 128,
	            CMD_LESS                      = 131,
	            CMD_GREATER                   = 133,
	            CMD_LESS_OR_EQUAL             = 134,
	            CMD_GREATER_OR_EQUAL          = 132,
	            CMD_EQUAL                     = 129,
	            CMD_NOT_EQUAL                 = 130,
	            CMD_UNSIGNED_LESS             = 147,
	            CMD_UNSIGNED_GREATER          = 149,
	            CMD_UNSIGNED_LESS_OR_EQUAL    = 150,
	            CMD_UNSIGNED_GREATER_OR_EQUAL = 148,
	            CMD_STOP                      = 153;
        #endregion

        public LM2():base(){ }

        #region Main methods
        protected override void InitialiseCommand(List<int> command)
        {
            try
            {
                CheckCommandFormat(command);

                if (currentAddress == UNINITIALIZED_ADDRESS)
                    currentAddress = command[0];

                ramMemory.SetCell(command[0],
                    new LM2Command(command[1], command[2], command[3]));
            }
            catch (Exception exp)
            {
                throw new System.Exception(exp.Message + ' ' +
                    TextFormat.addZeros(Convert.ToString(command[0], 16), 4));
            }
        }

        private void CheckCommandFormat(List<int> command)
        {
            if (command.Count < 4)
                throw new Exception("Too few fields");
            else if (command.Count > 4)
                throw new Exception("Too many fields");
        }

        protected override void MasterSwitch(RichTextBox textbox)
        {
            switch (GetCurrentCommandNumber())
            {
                case CMD_COMPARE:
                    LM2Operations.PerformFlagDetermination(this);
                    break;
                case CMD_OUTPUT:
                    LM2Operations.PerformOutputOperation(this, LMCommands.Output, textbox);
                    break;
                case CMD_INPUT:
                    LMCommands.InputMessage(textbox, GetName(GetAddressOperand(currentAddress, 1)));
                    inputFlag = true;
                    break;
                case CMD_UNSIGNED_OUTPUT:
                    LM2Operations.PerformOutputOperation(this, LMCommands.UnsignedOuput, textbox);
                    break;
                case CMD_UNSIGNED_INPUT:
                    LMCommands.InputMessage(textbox, GetName(GetAddressOperand(currentAddress, 1)));
                    this.uInputFlag = true;
                    break;
                case CMD_ADD:
                    LM2Operations.PerformArithmeticOperation(this, LMCommands.Add);
                    break;
                case CMD_SUBSTRACT:
                    LM2Operations.PerformArithmeticOperation(this, LMCommands.Substract);
                    break;
                case CMD_MULTIPLICATION:
                    LM2Operations.PerformArithmeticOperation(this, LMCommands.Multiplication);
                    break;
                case CMD_DIVISION:
                    LM2Operations.PerformDivisionOperation(this, LMCommands.Division, LMCommands.Module);
                    break;
                case CMD_UNSIGNED_MULTIPLICATION:
                    LM2Operations.PerformArithmeticOperation(this, LMCommands.UnsignedMultiplication);
                    break;
                case CMD_UNSIGNED_DIVISION:
                    LM2Operations.PerformDivisionOperation(this, LMCommands.UnsignedDivision, LMCommands.UnsignedModule);
                    break;
                case CMD_ASSIGMENT:
                    LM2Operations.PerformAssignmentOperation(this);
                    break;
                case CMD_GOTO:
                    LM2Operations.PerformGoToOperation(this);
                    break;
                case CMD_LESS:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.LESS);
                    break;
                case CMD_GREATER:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.GREATER);
                    break;
                case CMD_LESS_OR_EQUAL:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.LESS_OR_EQUAL);
                    break;
                case CMD_GREATER_OR_EQUAL:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.GREATER_OR_EQUAL);
                    break;
                case CMD_EQUAL:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.EQUAL);
                    break;
                case CMD_NOT_EQUAL:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.N_EQUAL);
                    break;
                case CMD_UNSIGNED_LESS:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.INS_LESS);
                    break;
                case CMD_UNSIGNED_GREATER:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.INS_GREATER);
                    break;
                case CMD_UNSIGNED_LESS_OR_EQUAL:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.INS_LESS_OR_EQUAL);
                    break;
                case CMD_UNSIGNED_GREATER_OR_EQUAL:
                    LM2Operations.PerformComparisonOperation(this, LM2Operations.ComparisonFlag.INS_GREATER_OR_EQUAL);
                    break;
                case CMD_STOP:
                    this.endFlag = true;
                    break;
                default:
                    break;
            }
        }

        #endregion

        #region Axuiliary methods
        public override void GoToNextAddress()
        {
            currentAddress++;
        }
        public override int GetValueOperand(int positionInMemory, int numberOfOperand)
        {
            CheckNumberOfOperand(numberOfOperand);

            return ramMemory.GetCell(ramMemory.GetCell(positionInMemory).GetItem()[numberOfOperand]).GetValue();
        }
        public override int GetAddressOperand(int positionInMemory, int numberOfOperand)
        {
            CheckNumberOfOperand(numberOfOperand);

            return ramMemory.GetCell(positionInMemory).GetItem()[numberOfOperand];
        }
        protected override void CheckNumberOfOperand(int numberOfOperand)
        {
            if (numberOfOperand < 0 || numberOfOperand > 2)
                throw new Exception("invalid number of operand!");
        }
        public override void SetOperationResultInMemory(MemoryItem arithmeticResult)
        {
            ramMemory.SetCell(GetAddressOperand(currentAddress, 1), arithmeticResult);
        }
        public override void SetOperationResultInMemory(MemoryItem divisionResult, MemoryItem module)
        {
            ramMemory.SetCell(GetAddressOperand(currentAddress, 1), divisionResult);
            ramMemory.SetCell(GetAddressOperand(currentAddress, 1) + 1, module);
        }

        public override void SetVariableInMemory(int positionInMemory, int value)
        {
            MemoryItem var = new Variable(value);
            ramMemory.SetCell(positionInMemory, var);
        }
        #endregion
    }
}
