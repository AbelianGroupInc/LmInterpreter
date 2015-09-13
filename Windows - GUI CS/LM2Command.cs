using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class LM2Command: Command
    {
        public LM2Command(int cmd, int r1, int r2)
        {
            CMD_LIST = new int[]{ 153, 0, 1, 2, 3, 4,5, 6, 7, 19, 20, 22, 23,
            128, 129, 130, 131, 132, 133, 134, 147, 148, 149, 150 };

            this.command = new List<int>() { cmd, r1, r2 };

            if ((r1 < 0 || r1 > MAX_SIZE_OF_REGISTER) ||
                (r2 < 0 || r2 > MAX_SIZE_OF_REGISTER))
                throw new Exception();
                //Register bounds violation

            for (int i = 0; i < CMD_LIST.Length; i++)
                if (cmd == CMD_LIST[i])
                    return;

            throw new Exception("");
            //Invalid command

        }
    }
}
