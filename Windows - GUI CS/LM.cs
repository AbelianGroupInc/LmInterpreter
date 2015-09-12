using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    abstract class LM
    {
        protected int current_adress;
        protected Memory ram_memory;

        protected bool end_flag;
        protected bool input_flag;

        public LM(){
            end_flag = false;
            input_flag = false;
            ram_memory = null;
            current_adress = 0;
        }

        public abstract void DoOneStep();
        public abstract void SetProgram(System.Collections.ArrayList parsedProgramText);

        public abstract int GetValueOperand(int positionInMemory, int numberOfOperands);
        public abstract int GetAddresOperand(int positionInMemory, int numberOfOperands);

        public abstract void InitVariable(int position, string name);
        public abstract void InitVariable(int position, int value);
        public abstract void InitVariable(int position, string name, int value);
        public abstract void ClearMemory();

    }
}
