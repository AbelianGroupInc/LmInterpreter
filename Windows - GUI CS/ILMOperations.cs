using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    interface ILMOperations
    {
        void PerformArithmeticOperation(Func<MemoryItem, MemoryItem, MemoryItem> arithmeticDelegate);
        void PerformInputOperation(int value);
        void PerformOutputOperation(Action<RichTextBox, MemoryItem, string> outputDelegate,
            RichTextBox output);
        void PerformAssignmentOperation();
        void PerformGoToOperation();
    }
}
