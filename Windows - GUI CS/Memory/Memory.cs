using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    class Memory
    {
        const int SIZE_OF_MEMORY = 65536;

        private MemoryItem[] _memory;
        private Dictionary<int, string> _names;

        public Memory()
        {
            _memory = new MemoryItem[SIZE_OF_MEMORY];
            _names = new Dictionary<int, string>();

            ClearMemory();
        }

        #region Methods for memory
        public MemoryItem GetCell(int position)
        {
            Check(position);

            if (_memory[position] == null)
                throw new Exception("memory error: appealing to a non-existent adress.");

            return _memory[position];
        }
        public void SetCell(int position, MemoryItem item)
        {
            Check(position);

            _memory[position] = item;
        }
        public void ClearMemory()
        {
            for (int i = 0; i < SIZE_OF_MEMORY; i++)
                _memory[i] = null;

            _names.Clear();
        }
        public bool IsMemoryCellEmpty(int position)
        {
            Check(position);

            return _memory[position] == null;
        }
        #endregion

        #region Methods for names
        public void SetName(int position, string name)
        {
            Check(position);

            if (_names.ContainsKey(position))
                _names[position] = name;
            else
                _names.Add(position, name);
        }

        public string GetName(int position)
        {
            Check(position);

            if (_names.ContainsKey(position))
                return _names[position]; 
            else
                return TextFormat.addZeros(Convert.ToString(position, 16).ToUpper(),4);
        }

        #region information about variables

        private string StringInDecNumber(string address, string name, int value)
        {
            return string.Format("{0} ( {1} ) := {2}", address, name, value);
        }

        private string StringInAdditionalCode(string address, string name, int value)
        {
            return string.Format("{0} ( {1} ) := {2} ({3})", address, name, value,TextFormat.additionalCode16(value));
        }

        private List<string> CreateVarInfo(Func<string, string, int, string> stringFormat)
        {
            List<string> varInfo = new List<string>();

            for (int i = 0; i < _memory.Length; i++)
                if (_memory[i] != null && _memory[i] is Variable)
                    varInfo.Add(stringFormat(TextFormat.addZeros(Convert.ToString(i, 16).ToUpper(), 4),GetName(i), _memory[i].GetValue()));

            return varInfo;
        }

        public List<string> GetVarInfo()
        {
            return CreateVarInfo(StringInDecNumber);
        }

        public List<string> GetVarInfoInAdditionalCode()
        {
            return CreateVarInfo(StringInAdditionalCode);
        }

        #endregion

        public List<string> GetCmdInfo()
        {
            List<string> cmdInfo = new List<string>();

            for (int i = 0; i < _memory.Length; i++)
                if (_memory[i] != null && _memory[i] is Command)
                    cmdInfo.Add(string.Format("{0} := {1}", TextFormat.addZeros(Convert.ToString(i, 16).ToUpper(), 4), _memory[i].ToString()));

            return cmdInfo;
        }

        #endregion
        public void Check(int position)
        {
            if (position < 0 || position > SIZE_OF_MEMORY)
                throw new Exception("Memory error: Memory bounds violation.");
        }
    }
}
