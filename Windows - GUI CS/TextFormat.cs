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
                throw new System.Exception("Formating error: (" + number + ")");

            if (number_of_zeros > 0)
            {
                string temp = new string('0', number_of_zeros);
                number = temp + number;
            }

            return number;
        }
    }
}
