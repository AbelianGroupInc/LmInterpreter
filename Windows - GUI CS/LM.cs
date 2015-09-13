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
        protected int currentAdress;
        protected Memory ramMemory;
        protected bool endFlag;
        protected bool inputFlag;

        public LM(){
            ramMemory = new Memory();
            currentAddress = 0;
            endFlag = false;
            inputFlag = false;
        }

        public abstract void DoOneStep(RichTextBox output);
        public abstract void SetProgram(List<List<int > > parsedProgramText);
        public abstract void ClearMemory();

        public abstract int GetValueOperand(int positionInMemory, int numberOfOperand);
        public abstract int GetAddressOperand(int positionInMemory, int numberOfOperand);

        public abstract void InitVariable(int position, string name);
        public abstract void InitVariable(int position, int value);
        public abstract void InitVariable(int position, string name, int value);

        protected int GetCurrentCommandNumber()
        {
            return this.ramMemory.GetCell(this.currentAddress).GetValue();
        }
        public int currentAddress { get; set; }
    }
}
