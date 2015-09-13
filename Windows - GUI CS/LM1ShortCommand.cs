using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class LM1ShortCommand:Command
    {
        public LM1ShortCommand(int cmd, int r1, int r2){
            CMD_LIST = new int[]{ 153, 32, 33, 34, 35, 51, 36, 52, 37 };

            this.command = new List<int>(){cmd, r1, r2};

            if ((r1 < 0 || r1 > MAX_SIZE_OF_REGISTER) ||
		        (r2 < 0 || r2 > MAX_SIZE_OF_REGISTER))
		    throw new Exception();
            //Register bounds violation

            for (int i = 0; i < CMD_LIST.Length; i++)
                if (cmd == CMD_LIST[i])
                    return;

            throw new Exception();
            //"Invalid command
        }
    }
}
