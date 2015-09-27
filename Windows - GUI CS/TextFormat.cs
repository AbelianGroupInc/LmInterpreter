using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    static class TextFormat
    {
        public static string addZeros(string number, int number_lenght)
        {
            int number_of_zeros = number_lenght - number.Length;

            if (number_of_zeros < 0)
                throw new System.Exception("formating error: (" + number + ")");

            if (number_of_zeros > 0)
            {
                string temp = new string('0', number_of_zeros);
                number = temp + number;
            }

            return number;
        }

        public static string additionalCode16(int number)
        {
            if (number < 0)
                return Convert.ToString((short)((~-number) + 1), 2);
            else
                return addZeros(Convert.ToString((ushort)number, 2),16);
        }

        public static string additionalCode32(int number)
        {
            if (number < 0)
                return Convert.ToString((int)((~-number) + 1), 2);
            else
                return addZeros(Convert.ToString((uint)number, 2), 32);
        }
    }
}
