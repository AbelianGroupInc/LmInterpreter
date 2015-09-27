using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class LM2Operations: LMOperations
    {
        public enum ComparisonFlag { EQUAL, N_EQUAL, LESS, GREATER, LESS_OR_EQUAL, GREATER_OR_EQUAL, INS_LESS, INS_GREATER, INS_LESS_OR_EQUAL, INS_GREATER_OR_EQUAL };

        private static Dictionary<ComparisonFlag, bool> comparisonOperations;

        static LM2Operations()
        {
            comparisonOperations = new Dictionary<ComparisonFlag, bool>(10);
        }
        public static void PerformFlagDetermination(LM machine)
        {
                // Need check of transfer command
                MemoryItem var1 = new Variable(machine.GetValueOperand(machine.currentAddress, 1));
                MemoryItem var2 = new Variable(machine.GetValueOperand(machine.currentAddress, 2));

                comparisonOperations[ComparisonFlag.EQUAL] = LMCommands.Equal(var1, var2);
                comparisonOperations[ComparisonFlag.N_EQUAL] = LMCommands.NotEqual(var1, var2);
                comparisonOperations[ComparisonFlag.LESS] = LMCommands.Less(var1, var2);
                comparisonOperations[ComparisonFlag.GREATER] = LMCommands.Greater(var1, var2);
                comparisonOperations[ComparisonFlag.LESS_OR_EQUAL] = LMCommands.LessOrEqual(var1, var2);
                comparisonOperations[ComparisonFlag.GREATER_OR_EQUAL] = LMCommands.GreaterOrEqual(var1, var2);
                comparisonOperations[ComparisonFlag.INS_LESS] = LMCommands.UnsignedLess(var1, var2);
                comparisonOperations[ComparisonFlag.INS_GREATER] = LMCommands.UnsignedGreater(var1, var2);
                comparisonOperations[ComparisonFlag.INS_LESS_OR_EQUAL] = LMCommands.UnsignedLessOrEqual(var1, var2);
                comparisonOperations[ComparisonFlag.INS_GREATER_OR_EQUAL] = LMCommands.UnsignedGreaterOrEqual(var1, var2);

                machine.GoToNextAddress();
        }
        public static void PerformComparisonOperation(LM machine, ComparisonFlag flag)
        {
            machine.currentAddress = comparisonOperations[flag] ? machine.GetAddressOperand(machine.currentAddress, 1) :
                machine.currentAddress + 1;

            for (int i = 0; i < comparisonOperations.Count; i++)
            {
                comparisonOperations[(ComparisonFlag)i] = false;
            }
        }

        public static void PerformAssignmentOperation(LM machine)
        {
            int inPosition = machine.GetAddressOperand(machine.currentAddress, 1);
            int value = machine.GetValueOperand(machine.currentAddress, 2);

            machine.SetVariableInMemory(inPosition, value);

            machine.GoToNextAddress();
        }
        public static void PerformGoToOperation(LM machine)
        {
            machine.currentAddress = machine.GetAddressOperand(machine.currentAddress, 1);
        }
    }
}
