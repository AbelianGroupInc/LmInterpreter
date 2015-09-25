using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace LM_GUI_UP
{
    static class Parser
    {
        private static bool ChekNumber(string number)
        {
            if(number.Length > 4)
                throw new System.Exception(String.Format("Parsing error: wrong address \"{0}\".", number));

            return true;
        }
        private static int GetNumber(string number)
        {
            try
            {
                return Convert.ToInt32(number, 16);
            }
            catch (System.Exception)
            {
                throw new System.Exception(String.Format("Parsing error: invalid hexadecimal number \"{0}\".", number));
            }
        }
        public static string AlignText(string text)
        {
            text = text.Replace('\t', ' ');
            text = Regex.Replace(text, @" +", " ");
            text = Regex.Replace(text, @"(\n)\s*(\n)*", "\n");
            text = Regex.Replace(text, @"^", "\t",RegexOptions.Multiline);
            text = Regex.Replace(text, @"\t#", "#", RegexOptions.Multiline);

            return text;
        }
        private static void RemovePass(ref string text)
        {
            text = text.Replace('\t', ' ');
            text = Regex.Replace(text, @" +", " ");
            text = Regex.Replace(text, @";.*?\n", "\n");
            text = Regex.Replace(text, @"(\n)\s*(\n)*", "\n");
        }
        private static string SplitInit(ref string text)
        {
            string init = Regex.Match(text, @"#init[\s\S]*?#end").Value;

            if (Regex.IsMatch(init, @"#code"))
                throw new System.Exception("Parsing error: imposition areas.");

            if (init.Length == 0)
                throw new System.Exception("Parsing error: lack of initialization area.");

            init = Regex.Replace(init, @"#.*?\n", String.Empty);
            init = Regex.Replace(init, @"\n#.*?$", String.Empty);

            return init;
        }
        private static string SplitCode(ref string text)
        {
            string code = Regex.Match(text, @"#code[\s\S]*?#end").Value;

            if (Regex.IsMatch(code, @"#init"))
                throw new System.Exception("Parsing error: imposition areas.");

            if (code.Length == 0)
                throw new System.Exception("Parsing error: lack of code area.");

            code = Regex.Replace(code, @"#.*?\n", String.Empty);
            code = Regex.Replace(code, @"\n#.*?$", String.Empty);

            return code;
        }
        private static List<AddressValue> ParseInit(string init_code)
        {
            string[] init_lines = init_code.Split(new Char[] { '\r', '\n' });
            List<AddressValue> parsed_init = new List<AddressValue>();

            foreach (string temp in init_lines)
            {
                string[] line = temp.Split(' ');
                int? address = null, value = null;
                string name = null;

                if (line.Length < 2)
                    throw new System.Exception(String.Format("Parsing error: too few arguments ({0}).", temp));

                ChekNumber(line[0]);
                    
                address = GetNumber(line[0]);

                for (int i = 1; i < line.Length; i++)
                {
                    if (line[i] == "" || line[i] == " ")
                        continue;

                    if (line[i].IndexOf('\"') != -1)
                        name = Regex.Replace(line[i], "\"", String.Empty); 
                    else
                        value = GetNumber(line[i]);
                }

                AddressValue tmp = new AddressValue(address, value, name);

                parsed_init.Add(tmp);
            }

            return parsed_init;
        }
        private static List<List<int>> ParseCode(string code)
        {
            List<List<int>> parsing_code = new List<List<int>>();
            string[] program = code.Split(new Char[] { '\r', '\n' });

            foreach (string temp in program)
            {
                string[] numbers = temp.Split(' ');
                List<int> line = new List<int>();

                foreach (string number in numbers)
                    if (number != "" && number != " ")
                    {
                        ChekNumber(number);
                        line.Add(GetNumber(number));
                    }

                parsing_code.Add(line);
            }

            return parsing_code;
        }
        public static List<List<int>> GetParsedCode(string text)
        {
            RemovePass(ref text);
            return ParseCode(SplitCode(ref text));;
        }

        public static List<AddressValue> GetParsedInit(string text)
        {
            RemovePass(ref text);
            return ParseInit(SplitInit(ref text));
        }
    }
}
