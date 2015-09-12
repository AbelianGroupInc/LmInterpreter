using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class Variable: MemoryItem
    {
        const int VAR_MAX = 65535;

        private ArrayList variableItem;
        public Variable(int value)
        {
            variableItem = new ArrayList();
            variableItem.Add(value % VAR_MAX);
        }

        public ArrayList GetItem()
        {
            return variableItem;
        }

        public int GetValue()
        {
            return (int)variableItem[0];
        }

    }
}
