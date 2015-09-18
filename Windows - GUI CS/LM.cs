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
        protected const int MAX_MEMORY_SIZE = 65536;
        public int currentAddress { get; set; }
        protected Memory ramMemory;
        protected bool endFlag;
        protected bool inputFlag;

        public LM(){
            ramMemory = new Memory();
            currentAddress = 0;
            endFlag = false;
            inputFlag = false;
        }

        public void SetProgram(List<List<int>> parsedProgramText)
        {   
            // Method code
            InitialiseCommand(parsedProgramText[0]);
            // Method code
        }
        protected abstract void InitialiseCommand(List<int> command);
        public void ClearMemory()
        {
            ramMemory.ClearMemory();
        }
        public abstract void DoOneStep(RichTextBox output);
        protected abstract void GoToNextAddress();

        public abstract int GetValueOperand(int positionInMemory, int numberOfOperand);
        public abstract int GetAddressOperand(int positionInMemory, int numberOfOperand);

        public abstract void InitVariable(int position, string name);
        public abstract void InitVariable(int position, int value);
        public abstract void InitVariable(int position, string name, int value);

        protected int GetCurrentCommandNumber()
        {
            return this.ramMemory.GetCell(this.currentAddress).GetValue();
        }
    }
}
