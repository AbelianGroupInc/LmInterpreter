using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class LM3Operations : LMOperations
    {
        public static void PerformAssignmentOperation(LM machine)
        {
            int value = machine.GetValueOperand(machine.currentAddress, 1);

            MemoryItem var = new Variable(value);

            machine.SetOperationResultInMemory(var);
            machine.GoToNextAddress();
        }

        public static void PerformGoToOperation(LM machine)
        {
            int value = machine.GetAddressOperand(machine.currentAddress, 3);

            machine.currentAddress = value;
        }

        public static void PerformComparisonOperation(LM machine, Func<MemoryItem, MemoryItem, bool> comparisonDelegate)
        {
            MemoryItem var_1 = new Variable(machine.GetValueOperand(machine.currentAddress, 1));
            MemoryItem var_2 = new Variable(machine.GetValueOperand(machine.currentAddress, 2));

            machine.currentAddress = comparisonDelegate(var_1, var_2) ? 
                machine.GetAddressOperand(machine.currentAddress, 3) : machine.currentAddress + 1;
        }
    }
}
