using System;

using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class Interpreter
    {

        protected LM machine;
        //temp_file

        public Interpreter(LM machine)
        {
            if (machine == null)
                throw new Exception("Machine is missed");
                //
            else 
                this.machine = machine;
        }
        public void ReadProgram(string program_text)
        {
            machine.ClearMemory();
            ArrayList parsed_program_text = Parsing(program_text);
            machine.SetProgram(parsed_program_text);
        }
        public void execute_a_step()
        {
            machine.DoOneStep();
        }
        public static ArrayList Parsing(string program_text)
        {
            //string temp_str;


            return new ArrayList();
        }
        private static void ParsingCodeString()
        {

        }
        private static void ParsingInitString()
        {

        }
       public int InitAdress(ref string str, ref int index)
       {
            StringBuilder address = new StringBuilder();

            for (; index < (int)str.Length; index++)
            {
                if (index == str.Length || str[index] == ' ' || str[index] == '\t')
                {
                    if(address.Length != 0)
                        return Converter.HexToDec(address.ToString());
                }
                else
                {
                    address.Append(str[index]);
                }
            }
            
           throw new Exception("");
           //wrong address
        }
        public void InitName(ref string str,int adress, ref int index)
        {
            StringBuilder name = new StringBuilder();

            while(true){
                if(++index == str.Length)
                    throw new Exception("");

                if(str[index] == '\"'){
                    this.machine.InitVariable(adress, name.ToString());
                    return;
                }

                name.Append(str[index]);
            }
                
        }
        public void InitValue(ref string str, int adress, ref int index)
        {
            StringBuilder value = new StringBuilder();
            for (; index <= (int)str.Length; index++)
            {
                if (index == str.Length || str[index] == ' ' || str[index] == '\t' || str[index] == ';')
                {
                    if (value.Length != 0)
                    {
                        this.machine.InitVariable(adress, Converter.HexToDec(value.ToString()));
                    }
                }
                else
                {
                    value.Append(str[index]);
                }
            }

        }

    }
}
