using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class LM1LongCommand:Command
    {
        public LM1LongCommand(int cmd, int r1, int m2, int a2)
        {
            CMD_LIST = new int[]{ 0, 16, 1, 2, 3, 19, 4, 20, 5, 6, 7,
	        128, 129, 130, 131, 132, 133, 134, 147, 148, 149, 150, 300 };

            command = new List<int>() { cmd, r1, m2, a2 };

            if ((r1 < 0 || r1 > MAX_SIZE_OF_REGISTER) ||
                (m2 < 0 || m2 > MAX_SIZE_OF_REGISTER) ||
                (a2 < 0 || a2 > MAX_SIZE_OF_REGISTER))
                throw new Exception("runtime error: Register bounds violation.");

            for (int i = 0; i < CMD_LIST.Length; i++)
                if (cmd == CMD_LIST[i])
                    return;

            throw new Exception("runtime error: Invalid command number.");
        }

        public override string ToString()
        {
            return TextFormat.addZeros(Convert.ToString(command[0], 16).ToUpper(), 2)
                + ' ' + TextFormat.addZeros(Convert.ToString(command[1], 16).ToUpper(), 2)
                + ' ' + TextFormat.addZeros(Convert.ToString(command[2], 16).ToUpper(), 2)
                + ' ' + TextFormat.addZeros(Convert.ToString(command[3], 16).ToUpper(), 4);
        }
    }
}
