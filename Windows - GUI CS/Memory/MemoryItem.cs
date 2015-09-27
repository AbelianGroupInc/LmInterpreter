using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LM_GUI_UP
{
    struct AddressValue
    {
        int? _address;
        int? _value;
        string _name;

        public AddressValue(int? address, int? value, string name)
        {
            _address = address;
            _value = value;
            _name = name;
        }

        #region auto-implemented property
        public int? Address
        {
            set
            {
                _address = value;
            }
            get
            {
                return _address;
            }
        }

        public int? Value
        {
            set
            {
                _value = value;
            }
            get
            {
                return _value;
            }
        }

        public string Name
        {
            set
            {
                _name = value;
            }
            get
            {
                return _name;
            }
        }
        #endregion
    }

    interface MemoryItem
    {
        List<int> GetItem();
        int GetValue();
    }
}
