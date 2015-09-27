using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    static class LMCommands
    {
        #region In/Out
        public static void Output(RichTextBox output, MemoryItem variable, string name)
        {
            StringBuilder temp = new StringBuilder(name);
            temp.Append(": " + ((short)variable.GetValue()).ToString() + "\n");
            output.Text += temp.ToString();
        }
        public static void UnsignedOuput(RichTextBox output, MemoryItem variable, string name)
        {
            StringBuilder temp = new StringBuilder(name);
            temp.Append(": " + ((ushort)variable.GetValue()).ToString() + "\n");
            output.Text += temp.ToString();
        }

        public static void InputMessage(RichTextBox output, string name)
        {
            output.AppendText("Please, enter " + name + ": ");
        }

        #endregion

        #region Arithmetic operations
        public static MemoryItem Add(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() + variable2.GetValue();
            return new Variable(value);
        }
        public static MemoryItem Substract(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() - variable2.GetValue();
            return new Variable(value);
        }
        public static MemoryItem Multiplication(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() * variable2.GetValue();
            return new Variable(value);
        }
        public static MemoryItem Division(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() / variable2.GetValue();
            return new Variable(value);
        }
        public static MemoryItem Module(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() % variable2.GetValue();
            return new Variable(value);
        }
        #endregion

        #region Unsigned arithmetic operations
        public static MemoryItem UnsignedAdd(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() + variable2.GetValue();
            return new Variable((ushort)value);
        }
        public static MemoryItem UnsignedSubstract(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() - variable2.GetValue();
            return new Variable((ushort)value);
        }
        public static MemoryItem UnsignedMultiplication(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() * variable2.GetValue();
            return new Variable((ushort)value);
        }
        public static MemoryItem UnsignedDivision(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() / variable2.GetValue();
            return new Variable((ushort)value);
        }
        public static MemoryItem UnsignedModule(MemoryItem variable1, MemoryItem variable2)
        {
            int value = variable1.GetValue() % variable2.GetValue();
            return new Variable((ushort)value);
        }
        #endregion

        #region Comparing operations
        public static bool Less(MemoryItem variable1, MemoryItem variable2)
        {
            return variable1.GetValue() < variable2.GetValue();
        }
        public static bool Greater(MemoryItem variable1, MemoryItem variable2)
        {
            return variable1.GetValue() > variable2.GetValue();
        }
        public static bool LessOrEqual(MemoryItem variable1, MemoryItem variable2)
        {
            return variable1.GetValue() <= variable2.GetValue();
        }
        public static bool GreaterOrEqual(MemoryItem variable1, MemoryItem variable2)
        {
            return variable1.GetValue() >= variable2.GetValue();
        }
        public static bool Equal(MemoryItem variable1, MemoryItem variable2)
        {
            return variable1.GetValue() == variable2.GetValue();
        }
        public static bool NotEqual(MemoryItem variable1, MemoryItem variable2)
        {
            return variable1.GetValue() != variable2.GetValue();
        }
        public static bool GoTo(MemoryItem variable1, MemoryItem variable2)
        {
            return true;
        }
        #endregion

        #region Unsigned comparing operations
        public static bool UnsignedLess(MemoryItem variable1, MemoryItem variable2)
        {
            return (ushort)variable1.GetValue() < (ushort)variable2.GetValue();
        }
        public static bool UnsignedGreater(MemoryItem variable1, MemoryItem variable2)
        {
            return (ushort)variable1.GetValue() > (ushort)variable2.GetValue();
        }
        public static bool UnsignedLessOrEqual(MemoryItem variable1, MemoryItem variable2)
        {
            return (ushort)variable1.GetValue() <= (ushort)variable2.GetValue();
        }
        public static bool UnsignedGreaterOrEqual(MemoryItem variable1, MemoryItem variable2)
        {
            return (ushort)variable1.GetValue() >= (ushort)variable2.GetValue();
        }
        #endregion
    }
}
