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
        private string[] names;

        public Memory(){
            //if (memory != null)
            //    this.ClearMemory();
            //else
                memory = new MemoryItem[SIZE_OF_MEMORY];
        }
        public MemoryItem GetCell(int position){
            this.check(position);

            if (this.memory[position].GetItem() == null)
                throw new Exception();

            return this.memory[position];
        }
        public void SetCell(int position, MemoryItem item)
        {
            this.check(position);

            this.memory[position] = item;
        }
        public void ClearMemory()
        {
            for (int i = 0; i < SIZE_OF_MEMORY; i++)
                this.memory[i] = null;
        }
        public bool IsMemoryCellEmpty(int position)
        {
            this.check(position);

            return this.memory[position] == null;
        }

        //public void SetName(int position, string name)
        //{
        //    this.check(position);

        //    this.names[position] = name;
        //}

        //public string GetName(int position)
        //{
        //    this.check(position);

        //    if (this.names[position] == null)
        //        return Converter.DecToHex(position, 4); // possible mistakes
        //    else
        //        return this.names[position];
        //}
        public void check(int position)
        {
            if (position < 0 || position > SIZE_OF_MEMORY)
                throw new Exception("Wrong address");
        }
    }
}
