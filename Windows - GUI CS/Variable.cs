using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class Variable: MemoryItem
    {
        const int VAR_MAX = 65536;

        private List<int> variableItem;
        public Variable(int value)
        {
            variableItem = new List<int>();
            variableItem.Add(value % VAR_MAX);
        }

        public List<int> GetItem()
        {
            return variableItem;
        }

        public int GetValue()
        {
            return (int)variableItem[0];
        }

        public override string ToString()
        {
            return TextFormat.addZeros(Convert.ToString(variableItem[0], 16), 4);
        }
    }
}
