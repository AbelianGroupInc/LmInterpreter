using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    interface ILMOperations
    {
        void PerformArithmeticOperation(Func<MemoryItem, MemoryItem, MemoryItem> arithmeticDelegate);
        void PerformComparisonOperation(Func<MemoryItem, MemoryItem, bool> comparisoDelegate);
        void PerformInputOperation(int value);
        void Perform_output_operation(Action<System.Windows.Forms.RichTextBox, MemoryItem, string> outputDelegate,
            System.Windows.Forms.RichTextBox output);
        void PerformAssignmentOperation();
        void PerformGoToOperation();
        void PerformDivisionOperation(Func<MemoryItem, MemoryItem, MemoryItem> divisionDelegate);
    }
}
