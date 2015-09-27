using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class Variable: MemoryItem
    {
        private int variableItem;
        public Variable(int value)
        {
            if(value < 0)
                variableItem = (short)value;
            else
                variableItem = (ushort)value;
        }

        public List<int> GetItem()
        {
            return new List<int>{variableItem};
        }

        public int GetValue()
        {
            return variableItem;
        }

        public override string ToString()
        {
            return TextFormat.addZeros(Convert.ToString(variableItem, 16), 4);
        }
    }
}
