using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LM3: LM
    {
        public LM3():base() { }

        #region Main methods
        protected override void InitialiseCommand(List<int > command){
            try
            {
                CheckCommandFormat(command);
                ramMemory.SetCell(command[0], new LM3Command(command[1], command[2], command[3], command[4]));
            }
           catch(Exception exp){
			/*	char* temp = new char[strlen(exp.what()) + 1];
				strcpy(temp, exp.what());
				throw InterpreterException(temp, program[i].front());
            */
            }
        }
        private void CheckCommandFormat(List<int> command)
        {
            if (command.Count < 5)
                throw new Exception("Too few fields");
            else if (command.Count > 5)
                throw new Exception("Too many fields");
        }
        public override void DoOneStep(RichTextBox output)
        {
            throw new NotImplementedException();
        }
        #endregion

        #region Auxiliary methods
        protected override void GoToNextAddress()
        {
            this.currentAddress++;
        }
        public override int GetValueOperand(int positionInMemory, int numberOfOperand)
        {
            throw new NotImplementedException();
        }
        public override int GetAddressOperand(int positionInMemory, int numberOfOperand)
        {
            throw new NotImplementedException();
        }
        public override void InitVariable(int position, string name)
        {
            throw new NotImplementedException();
        }
        public override void InitVariable(int position, int value)
        {
            throw new NotImplementedException();
        }
        public override void InitVariable(int position, string name, int value)
        {
            throw new NotImplementedException();
        }
        #endregion

    }
}
