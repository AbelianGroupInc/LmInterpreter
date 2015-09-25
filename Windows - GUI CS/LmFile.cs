using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    class LmFile
    {
        private bool _file_changed;
        private string _name;
        private string _path;

        #region constructors

        public LmFile()
        {
            _name = Strings.new_program;
            _file_changed = false;
            _path = null;
        }

        public LmFile(string name)
        {
            _name = name;
            _file_changed = false;
            _path = null;
        }

        public LmFile(string name, string path)
        {
            _name = name;
            _file_changed = false;
            _path = path;
        }

        #endregion

        #region auto-implemented property

        public string Name
        {
            get
            {
                return _name;
            }
        }

        public bool FileChanged
        {
            get
            {
                return _file_changed;
            }
            set
            {
                _file_changed = value;
            }
        }

        public string Path
        {
            get
            {
                return _path;
            }
        }

        #endregion

        public void Changed()
        {
            _file_changed = true;
        }

        public bool OpenFile()
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "File Lm(*.lm;) | *.lm;";
            ofd.RestoreDirectory = true;

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                _file_changed = false;
                _path = ofd.FileName;
                _name = System.IO.Path.GetFileNameWithoutExtension(_path);

                return true;
            }

            return false;
        }
        public void CloseFile(string text)
        {
            if (_file_changed)
            {
                if (MessageBox.Show(Strings.file_changed_text, Strings.file_changed_head,
                    MessageBoxButtons.YesNo, MessageBoxIcon.Warning) == DialogResult.Yes)
                {
                    SaveFile(text);
                }
            }
        }
        public void SaveFile(string text)
        {
            if (_path == null)
            {
                SaveFileAs(text);
            }
            else
            {
                System.IO.File.WriteAllText(_path, text);
            }

            _file_changed = false;
        }
        public void SaveFileAs(string text)
        {
            SaveFileDialog svd = new SaveFileDialog();

            svd.Filter = "File Lm(*.lm;) | *.lm;";
            svd.RestoreDirectory = true;


            if (svd.ShowDialog() == DialogResult.OK)
            {
                System.IO.File.WriteAllText(svd.FileName, text);
                _path = svd.FileName;
                _name = System.IO.Path.GetFileNameWithoutExtension(_path);
            }

            _file_changed = false;
        }
    }
}
