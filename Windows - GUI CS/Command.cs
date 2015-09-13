using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    abstract class Command: MemoryItem
    {
        protected List<int> command;
        protected const int MAX_SIZE_OF_REGISTER = 65535;
        protected int[] CMD_LIST;

        public Command()
        {
            CMD_LIST = null;
            command = null;
        }
        public List<int> GetItem()
        {
            return command;
        }
        public int GetValue()
        {
            // returns the number of command
            return (int)this.command[0];
        }
    }
}
