using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LM_GUI_UP
{
    public partial class main_form : Form
    {
        LmFile _file;
        LM _machine;
        public main_form()
        {
            if (!String.IsNullOrEmpty(Properties.Settings.Default.Language))
            {
                System.Threading.Thread.CurrentThread.CurrentUICulture = System.Globalization.CultureInfo.GetCultureInfo(Properties.Settings.Default.Language);
                System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.GetCultureInfo(Properties.Settings.Default.Language);
            }

            _file = new LmFile();
            _machine = new LM3();
            InitializeComponent();
        }

        #region Form

        private void main_form_Load(object sender, EventArgs e)
        {
            this.checked_language();

            this.label_main_head.Text = Strings.new_program;
        }

        private void main_form_FormClosing(object sender, FormClosingEventArgs e)
        {
            Properties.Settings.Default.Save();

            _file.CloseFile(textbox_main.Text);
        }

        #endregion

        #region Language
        private void checked_language()
        {
            if (System.Threading.Thread.CurrentThread.CurrentUICulture == System.Globalization.CultureInfo.GetCultureInfo("ru-RU"))
                this.menu_language_rus.Checked = true;

            if (System.Threading.Thread.CurrentThread.CurrentUICulture == System.Globalization.CultureInfo.GetCultureInfo("en-US"))
                this.menu_language_en.Checked = true;

            if (System.Threading.Thread.CurrentThread.CurrentUICulture == System.Globalization.CultureInfo.GetCultureInfo("uk-UA"))
                this.menu_language_ua.Checked = true;
        }

        private void reboot()
        {
            MessageBox.Show(Strings.reboot_text, Strings.reboot_head, MessageBoxButtons.OK, MessageBoxIcon.Information);
            this.Close();
        }

        private void choose_language(System.Windows.Forms.ToolStripMenuItem menu, String language)
        {
            if (!menu.Checked)
            {
                Properties.Settings.Default.Language = language;
                this.reboot();
            }
        }

        private void menu_language_rus_Click(object sender, EventArgs e)
        {
            this.choose_language(menu_language_rus, "ru-RU");
        }

        private void menu_language_en_Click(object sender, EventArgs e)
        {
            this.choose_language(menu_language_en, "en-US");
        }

        private void menu_language_ua_Click(object sender, EventArgs e)
        {
            this.choose_language(menu_language_ua, "uk-UA");
        }

        #endregion

        #region Theme

        private void choose_color(System.Drawing.Color c1, System.Drawing.Color c2, System.Drawing.Color c3)
        {
            Properties.Settings.Default.CLR1 = c1;
            Properties.Settings.Default.CLR2 = c2;
            Properties.Settings.Default.CLR3 = c3;
        }

        private void menu_blue_Click(object sender, EventArgs e)
        {
            this.choose_color(System.Drawing.Color.FromArgb(40, 57, 85), System.Drawing.Color.FromArgb(117, 136, 170), System.Drawing.Color.FromArgb(207, 215, 228));
        }

        private void menu_green_Click(object sender, EventArgs e)
        {
            this.choose_color(System.Drawing.Color.FromArgb(32, 56, 10), System.Drawing.Color.FromArgb(102, 154, 50), System.Drawing.Color.FromArgb(62, 136, 108));
        }

        private void menu_lblue_Click(object sender, EventArgs e)
        {
            this.choose_color(System.Drawing.Color.FromArgb(148, 195, 218), System.Drawing.Color.FromArgb(204, 227, 230), System.Drawing.Color.FromArgb(204, 227, 230));
        }

        private void menu_black_Click(object sender, EventArgs e)
        {
            this.choose_color(System.Drawing.Color.FromArgb(10, 10, 10), System.Drawing.Color.FromArgb(210, 210, 210), System.Drawing.Color.FromArgb(210, 210, 210));
        }

        #endregion

        #region File

        private void menu_open_Click(object sender, EventArgs e)
        {
            _file.CloseFile(textbox_main.Text);

            try
            {
                if (_file.OpenFile())
                {
                    System.IO.StreamReader input = new System.IO.StreamReader(_file.Path);

                    this.textbox_main.Text = input.ReadToEnd();
                    this.label_main_head.Text = _file.Name;
                    _file.FileChanged = false;

                    input.Close();
                }
            }
            catch (System.Exception exp)
            {
                MessageBox.Show(exp.Message,Strings.error_head, MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void menu_save_Click(object sender, EventArgs e)
        {
                _file.SaveFile(textbox_main.Text);

                this.label_main_head.Text = _file.Name;

        }

        private void menu_save_as_Click(object sender, EventArgs e)
        {
            _file.SaveFileAs(textbox_main.Text);

            this.label_main_head.Text = _file.Name;
        }

        private void menu_create_Click(object sender, EventArgs e)
        {
            _file.CloseFile(textbox_main.Text);

            textbox_main.Clear();
            label_main_head.Text = Strings.new_program;

            _file = new LmFile();
        }

        #endregion

        #region Help

        private void menu_helps_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("http://abeliangroup.kl.com.ua/");
        }

        private void menu_developers_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://github.com/GrigoryanArtem");
            System.Diagnostics.Process.Start("https://github.com/Vitaliyvin");
            System.Diagnostics.Process.Start("https://github.com/fofancy");
            System.Diagnostics.Process.Start("https://github.com/braza501");
        }

        #endregion

        #region Chose Lm

        private void menu_chose_lm_3_Click(object sender, EventArgs e)
        {
            _machine = new LM3();
            menu_chose_lm_3.Checked = true;
            menu_chose_lm_2.Checked = false;
            menu_chose_lm_rm.Checked = false;
        }

        private void menu_chose_lm_2_Click(object sender, EventArgs e)
        {
            _machine = new LM2();
            menu_chose_lm_3.Checked = false;
            menu_chose_lm_2.Checked = true;
            menu_chose_lm_rm.Checked = false;
        }

        private void menu_chose_lm_rm_Click(object sender, EventArgs e)
        {
            _machine = new LM1();
            menu_chose_lm_3.Checked = false;
            menu_chose_lm_2.Checked = false;
            menu_chose_lm_rm.Checked = true;
        }

        #endregion

        private void textbox_main_TextChanged(object sender, EventArgs e)
        {
            _file.Changed();
        }

        private void StartProgram()
        {
            button_update.Enabled = true;
            button_next_step.Enabled = true;

            menu_file.Enabled = false;
            menu_chose_lm.Enabled = false;

            button_start.Text = Strings.button_stop;
            textbox_main.Enabled = false;

            try
            {
                _machine.Init(textbox_main.Text);
            }
            catch (System.Exception exp)
            {
                textbox_errors.AppendText(exp.Message + '\n');
                StopProgram();
            }
        }

        private void StopProgram()
        {
            button_update.Enabled = false;
            button_next_step.Enabled = false;
            button_enter.Enabled = false;

            menu_file.Enabled = true;
            menu_chose_lm.Enabled = true;

            label_command.Text = string.Empty;
            textbox_input.Clear();
            button_start.Text = Strings.button_start;
            textbox_main.Enabled = true;
        }

        private void button_start_Click(object sender, EventArgs e)
        {
            if (this.button_start.Text == Strings.button_start)
            {
                StartProgram();
            }
            else
            {
                StopProgram();
            }
        }

        private void menu_align_text_Click(object sender, EventArgs e)
        {
            textbox_main.Text = Parser.AlignText(textbox_main.Text);
        }

        private void menu_interpreter_Click(object sender, EventArgs e)
        {
            
        }

        private void button_clear_Click(object sender, EventArgs e)
        {
            textbox_errors.Clear();
            textbox_input.Clear();
            textbox_output.Clear();
        }

        private void button_update_Click(object sender, EventArgs e)
        {
            List<string> temp = new List<string>();

            list_box_memory.Items.Clear();


            if (menu_chose_var.Checked)
            {
                temp = _machine.GetVarInfo();

                foreach (var variable in temp)
                    list_box_memory.Items.Add(variable);
            }


            if (menu_chose_cmd.Checked)
            {
                temp = _machine.GetCmdInfo();

                foreach (var variable in temp)
                    list_box_memory.Items.Add(variable);
            }
        }

        private void button_next_step_Click(object sender, EventArgs e)
        {
            try
            {
                label_command.Text = _machine.GetCurrentCommand();
                _machine.DoOneStep(textbox_output);
                button_update_Click(sender, e);

                if (_machine.IsEnd())
                    button_start_Click(sender, e);

                if (_machine.IsInput())
                    button_enter.Enabled = true;
            }
            catch(System.Exception exp){
                textbox_errors.AppendText(exp.Message + '\n');
            }
        }

        private void textbox_input_KeyPress(object sender, KeyPressEventArgs e)
        {
            if ((e.KeyChar <= 47 || e.KeyChar >= 59) && e.KeyChar != 8 && e.KeyChar != 45)
                e.Handled = true;

            if(textbox_input.Text.Length > 5)
                e.Handled = true;
        }

        private void button_enter_Click(object sender, EventArgs e)
        {
            try{
                _machine.Input(Convert.ToInt32(textbox_input.Text));

                textbox_output.AppendText(textbox_input.Text + "\n");
                textbox_input.Clear();
            }
            catch(System.Exception exp){
                textbox_errors.AppendText(exp.Message + '\n');
            }

            button_enter.Enabled = false;
        }

        private void list_box_memory_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
