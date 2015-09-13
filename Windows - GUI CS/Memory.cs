using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class Memory
    {
        const int SIZE_OF_MEMORY = 65535;
        private MemoryItem[] memory;
        private Dictionary<int, string> names;

        public Memory(){
            if (memory != null)
                this.ClearMemory();
            else
            {
                memory = new MemoryItem[SIZE_OF_MEMORY];
                names = new Dictionary<int, string>();
            }
        }
        #region Methods for memory
        public MemoryItem GetCell(int position){
            this.Check(position);

            if (this.memory[position] == null)
                throw new Exception();
            //Appealing to a non-existent adress

            return this.memory[position];
        }
        public void SetCell(int position, MemoryItem item)
        {
            this.Check(position);

            this.memory[position] = item;
        }
        public void ClearMemory()
        {
            for (int i = 0; i < SIZE_OF_MEMORY; i++)
                this.memory[i] = null;
        }
        public bool IsMemoryCellEmpty(int position)
        {
            this.Check(position);

            return this.memory[position] == null;
        }
        #endregion

        #region Methods for names
        public void SetName(int position, string name)
        {
            this.Check(position);

            this.names.Add(position, name);
        }

        public string GetName(int position)
        {
            this.Check(position);

            if (this.names[position] == null)
                return Converter.DecToHex(position, 4); // possible mistakes
            else
               return this.names[position];
        }
        #endregion
        public void Check(int position)
        {
            if (position < 0 || position > SIZE_OF_MEMORY)
                throw new Exception("");
            //Memory bounds violation
        }
    }
}
