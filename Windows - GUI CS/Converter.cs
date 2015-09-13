using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    static class Converter
    {
        #region Class Details
        private static class Details
        {
            public static int ToDecSystem (string number, uint k, int cur = 0){
                	return cur < number.Length ? CharToInt(number[cur]) * (int)(Math.Pow(k, number.Length - 1 - cur)) + 
		            ToDecSystem(number, k, cur + 1) : 0;
            }
            private static int CharToInt(char number)
            {
                if (!((number >= '0' && number <= '9') || (number >= 'A' && number <= 'Z')))
		        throw new Exception("");
                //Invalid number
	
	            return number <= '9' ? number - '0' : number + 10 - 'A';
            }
            private static char IntToChar(int number)
            {
                if (number > 36 || number < 0)
                    throw new Exception();
                //invalid numerical system

                return (char)(number > 9 ? number - 10 + 'A' : number + '0');
            }
            public static string AddedZeros(string number, uint numberSize){
                StringBuilder resultingNumber = new StringBuilder();
                int number_of_zeros = (int)numberSize - (int)number.Length;

                if(number_of_zeros < 0)
                    throw new Exception();
                    //Invalid argument

                //possible mistake
                for(int i = 0; i < number_of_zeros;i++)
                    resultingNumber.Append('0');

                resultingNumber.Append(number);

                return resultingNumber.ToString();
            }

            public static string ToKSystem(int decNumber, uint k)
            {
                return decNumber != 0 ? ToKSystem((int)(decNumber / k), k) + IntToChar((int)(decNumber %  k)) : "";
            }

            
        }
        #endregion
        public static int HexToDec(string hexNumber)
        {
            return Details.ToDecSystem(hexNumber, 16);
        }

        public static string DecToHex(int decNumber, uint numberSize)
        {
            return Details.AddedZeros(DecToHex(decNumber), numberSize);
        }

        public static string DecToHex(int decNumber)
        {
            return Details.ToKSystem(decNumber, 16);
        }
    }
}
