using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LM1: LM
    {
        public LM1():base() { }
        #region Main methods
        protected override void InitialiseCommand(List<int> command)
        {
            try
            {
                //CheckCommandForamt(command);
                //Set command in memory
            }
            catch (Exception exp)
            {
                //Process exception
            }
        }
        private void CheckCommandFormat(List<int> command)
        {
            //Long comand check
            //Short command check
        }
        public override void DoOneStep(RichTextBox output)
        {
            throw new NotImplementedException();
        }
        #endregion

        #region Auxiliary methods
        protected override void GoToNextAddress()
        {
            throw new NotImplementedException();
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
