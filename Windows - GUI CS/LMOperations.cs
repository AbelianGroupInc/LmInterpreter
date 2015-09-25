using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LMOperations
    {
        public static void PerformArithmeticOperation(LM machine, Func<MemoryItem, MemoryItem, MemoryItem> arithmeticDelegate)
        {
            MemoryItem var1 = new Variable(machine.GetValueOperand(machine.currentAddress, 1));
            MemoryItem var2 = new Variable(machine.GetValueOperand(machine.currentAddress, 2));

            machine.SetOperationResultInMemory(arithmeticDelegate(var1, var2));

            machine.GoToNextAddress();
        }
        public static void PerformInputOperation(LM machine, int value)
        {
            MemoryItem var = new Variable(value);

            machine.SetVariableInMemory(machine.GetAddressOperand(machine.currentAddress, machine.GetInOutOperand()), var.GetValue());
        }

        public static void PerformOutputOperation(LM machine, Action<RichTextBox, MemoryItem, string> outputDelegate,
            RichTextBox output)
        {
            MemoryItem var = new Variable(machine.GetValueOperand(machine.currentAddress, machine.GetInOutOperand()));

            outputDelegate(output, var, machine.GetName(machine.GetAddressOperand(machine.currentAddress, machine.GetInOutOperand())));

            machine.GoToNextAddress();
        }

        public static void PerformDivisionOperation(LM machine, Func<MemoryItem, MemoryItem, MemoryItem> divisionDelegate,
            Func<MemoryItem, MemoryItem, MemoryItem> moduleDelegate)
        {
            MemoryItem var1 = new Variable(machine.GetValueOperand(machine.currentAddress, 1));
            MemoryItem var2 = new Variable(machine.GetValueOperand(machine.currentAddress, 2));

            machine.SetOperationResultInMemory(divisionDelegate(var1, var2), moduleDelegate(var1, var2));

            machine.GoToNextAddress();
        }
    }
}
