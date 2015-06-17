#pragma once

#include <memory>

#include "LmInterpreter.h"
#include "Lm3.h"
#include "Lm2.h"
#include "Lm1.h"

namespace LmGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			this->current_filename = gcnew System::String("");
			this->timer_intr = 1000;
			this->TEMP_PATH = gcnew System::String("bin\\temp.lm");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::String^ TEMP_PATH;
	private: System::Int32^ timer_intr;
	private: LmInterpreter* lmc;
	private: System::String^ current_filename;
	private: System::Windows::Forms::MenuStrip^  menu_main;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_file;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_help;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_reference;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_developers;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_grigoryan;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_bandura;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_eremeev;
	private: System::Windows::Forms::ToolStripTextBox^  menu_text_1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_bondarenko;
	private: System::Windows::Forms::RichTextBox^  text_box_main;
	private: System::Windows::Forms::GroupBox^  box_debug;
	private: System::Windows::Forms::Button^  button_debug_open;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_view;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_font;
	private: System::Windows::Forms::FontDialog^  font_dialog;
	private: System::Windows::Forms::ToolTip^  tip;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_create_file;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_open_file;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_save;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_save_as;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_exit;
	private: System::Windows::Forms::OpenFileDialog^  open_dialog;
	private: System::Windows::Forms::SaveFileDialog^  save_dialog;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_settings;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_set_lm;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_lm_3;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_lm_2;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_lm_rm;
	private: System::Windows::Forms::Button^  button_memory_open;
	private: System::Windows::Forms::GroupBox^  box_memory;
	private: System::Windows::Forms::RichTextBox^  text_output;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  text_errors;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RichTextBox^  text_input;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label_main;
	private: System::Windows::Forms::Button^  button_enter;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_set_test;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_test_def;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_test_step;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button_a_update_memory;
	private: System::Windows::Forms::Button^  button_update_memory;
	private: System::Windows::Forms::ListBox^  list_memory;
	private: System::Windows::Forms::Button^  button_start;

	private: System::Windows::Forms::ToolStripMenuItem^  menu_memory_set;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_auto_update_frequency;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_50_gc;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_100_gc;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_250_gc;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_500_gc;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_1000_gc;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_update_mode;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_user_mode;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_auto_mode;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_view_mode;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_var;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_cmd;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_interpret;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
	private: System::Windows::Forms::Button^  button_do_step;
	private: System::Windows::Forms::Timer^  timer_memory;
	private: System::Windows::Forms::ToolStripMenuItem^  menu_1_gc;
	private: System::Windows::Forms::Timer^  main_timer;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  text_command;


	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menu_main = (gcnew System::Windows::Forms::MenuStrip());
			this->menu_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_create_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_open_file = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menu_save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_save_as = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menu_interpret = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menu_exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_view = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_font = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_settings = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_set_lm = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_lm_3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_lm_2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_lm_rm = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_set_test = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_test_def = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_test_step = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_memory_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_auto_update_frequency = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_1_gc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_50_gc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_100_gc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_250_gc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_500_gc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_1000_gc = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_update_mode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_user_mode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_auto_mode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_view_mode = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_var = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_cmd = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_reference = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_developers = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_text_1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->menu_grigoryan = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_bandura = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_eremeev = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_bondarenko = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->text_box_main = (gcnew System::Windows::Forms::RichTextBox());
			this->box_debug = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button_do_step = (gcnew System::Windows::Forms::Button());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button_enter = (gcnew System::Windows::Forms::Button());
			this->text_input = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->text_errors = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->text_output = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_debug_open = (gcnew System::Windows::Forms::Button());
			this->font_dialog = (gcnew System::Windows::Forms::FontDialog());
			this->tip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button_memory_open = (gcnew System::Windows::Forms::Button());
			this->open_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->save_dialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->box_memory = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button_a_update_memory = (gcnew System::Windows::Forms::Button());
			this->button_update_memory = (gcnew System::Windows::Forms::Button());
			this->list_memory = (gcnew System::Windows::Forms::ListBox());
			this->label_main = (gcnew System::Windows::Forms::Label());
			this->timer_memory = (gcnew System::Windows::Forms::Timer(this->components));
			this->main_timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->text_command = (gcnew System::Windows::Forms::RichTextBox());
			this->menu_main->SuspendLayout();
			this->box_debug->SuspendLayout();
			this->box_memory->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_main
			// 
			this->menu_main->BackColor = System::Drawing::Color::SteelBlue;
			this->menu_main->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->menu_file, this->menu_view,
					this->menu_settings, this->menu_help
			});
			this->menu_main->Location = System::Drawing::Point(0, 0);
			this->menu_main->Name = L"menu_main";
			this->menu_main->Size = System::Drawing::Size(1264, 24);
			this->menu_main->TabIndex = 0;
			this->menu_main->Text = L"menuStrip1";
			// 
			// menu_file
			// 
			this->menu_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->menu_create_file,
					this->menu_open_file, this->toolStripSeparator2, this->menu_save, this->menu_save_as, this->toolStripSeparator3, this->menu_interpret,
					this->toolStripSeparator4, this->menu_exit
			});
			this->menu_file->Name = L"menu_file";
			this->menu_file->Size = System::Drawing::Size(53, 20);
			this->menu_file->Text = L"ФАЙЛ";
			// 
			// menu_create_file
			// 
			this->menu_create_file->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_create_file.Image")));
			this->menu_create_file->Name = L"menu_create_file";
			this->menu_create_file->Size = System::Drawing::Size(177, 22);
			this->menu_create_file->Text = L"Создать";
			this->menu_create_file->Click += gcnew System::EventHandler(this, &MainForm::menu_create_file_Click);
			// 
			// menu_open_file
			// 
			this->menu_open_file->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_open_file.Image")));
			this->menu_open_file->Name = L"menu_open_file";
			this->menu_open_file->Size = System::Drawing::Size(177, 22);
			this->menu_open_file->Text = L"Открыть";
			this->menu_open_file->Click += gcnew System::EventHandler(this, &MainForm::menu_open_file_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(174, 6);
			// 
			// menu_save
			// 
			this->menu_save->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_save.Image")));
			this->menu_save->Name = L"menu_save";
			this->menu_save->Size = System::Drawing::Size(177, 22);
			this->menu_save->Text = L"Сохранить";
			this->menu_save->Click += gcnew System::EventHandler(this, &MainForm::menu_save_Click);
			// 
			// menu_save_as
			// 
			this->menu_save_as->Name = L"menu_save_as";
			this->menu_save_as->Size = System::Drawing::Size(177, 22);
			this->menu_save_as->Text = L"Сохранить как";
			this->menu_save_as->Click += gcnew System::EventHandler(this, &MainForm::menu_save_as_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(174, 6);
			// 
			// menu_interpret
			// 
			this->menu_interpret->Name = L"menu_interpret";
			this->menu_interpret->Size = System::Drawing::Size(177, 22);
			this->menu_interpret->Text = L"Интерпретировать";
			this->menu_interpret->Click += gcnew System::EventHandler(this, &MainForm::menu_interpret_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(174, 6);
			// 
			// menu_exit
			// 
			this->menu_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_exit.Image")));
			this->menu_exit->Name = L"menu_exit";
			this->menu_exit->Size = System::Drawing::Size(177, 22);
			this->menu_exit->Text = L"Выйти";
			this->menu_exit->Click += gcnew System::EventHandler(this, &MainForm::menu_exit_Click);
			// 
			// menu_view
			// 
			this->menu_view->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menu_font });
			this->menu_view->Name = L"menu_view";
			this->menu_view->Size = System::Drawing::Size(43, 20);
			this->menu_view->Text = L"ВИД";
			// 
			// menu_font
			// 
			this->menu_font->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_font.Image")));
			this->menu_font->Name = L"menu_font";
			this->menu_font->Size = System::Drawing::Size(113, 22);
			this->menu_font->Text = L"Шрифт";
			this->menu_font->Click += gcnew System::EventHandler(this, &MainForm::menu_font_Click);
			// 
			// menu_settings
			// 
			this->menu_settings->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menu_set_lm,
					this->menu_set_test, this->menu_memory_set
			});
			this->menu_settings->Name = L"menu_settings";
			this->menu_settings->Size = System::Drawing::Size(92, 20);
			this->menu_settings->Text = L"НАСТРОЙКИ";
			// 
			// menu_set_lm
			// 
			this->menu_set_lm->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menu_lm_3,
					this->menu_lm_2, this->menu_lm_rm
			});
			this->menu_set_lm->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_set_lm.Image")));
			this->menu_set_lm->Name = L"menu_set_lm";
			this->menu_set_lm->Size = System::Drawing::Size(226, 22);
			this->menu_set_lm->Text = L"Режим интерпритирования";
			// 
			// menu_lm_3
			// 
			this->menu_lm_3->Checked = true;
			this->menu_lm_3->CheckOnClick = true;
			this->menu_lm_3->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menu_lm_3->Name = L"menu_lm_3";
			this->menu_lm_3->Size = System::Drawing::Size(121, 22);
			this->menu_lm_3->Text = L"УМ - 3";
			this->menu_lm_3->Click += gcnew System::EventHandler(this, &MainForm::menu_lm_3_Click);
			// 
			// menu_lm_2
			// 
			this->menu_lm_2->CheckOnClick = true;
			this->menu_lm_2->Name = L"menu_lm_2";
			this->menu_lm_2->Size = System::Drawing::Size(121, 22);
			this->menu_lm_2->Text = L"УМ - 2";
			this->menu_lm_2->Click += gcnew System::EventHandler(this, &MainForm::menu_lm_2_Click);
			// 
			// menu_lm_rm
			// 
			this->menu_lm_rm->CheckOnClick = true;
			this->menu_lm_rm->Name = L"menu_lm_rm";
			this->menu_lm_rm->Size = System::Drawing::Size(121, 22);
			this->menu_lm_rm->Text = L"УМ - РМ";
			this->menu_lm_rm->Click += gcnew System::EventHandler(this, &MainForm::menu_lm_rm_Click);
			// 
			// menu_set_test
			// 
			this->menu_set_test->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menu_test_def,
					this->menu_test_step
			});
			this->menu_set_test->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_set_test.Image")));
			this->menu_set_test->Name = L"menu_set_test";
			this->menu_set_test->Size = System::Drawing::Size(226, 22);
			this->menu_set_test->Text = L"Режим тестирования";
			// 
			// menu_test_def
			// 
			this->menu_test_def->Checked = true;
			this->menu_test_def->CheckOnClick = true;
			this->menu_test_def->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menu_test_def->Name = L"menu_test_def";
			this->menu_test_def->Size = System::Drawing::Size(141, 22);
			this->menu_test_def->Text = L"Обычный";
			this->menu_test_def->Click += gcnew System::EventHandler(this, &MainForm::menu_test_def_Click);
			// 
			// menu_test_step
			// 
			this->menu_test_step->CheckOnClick = true;
			this->menu_test_step->Name = L"menu_test_step";
			this->menu_test_step->Size = System::Drawing::Size(141, 22);
			this->menu_test_step->Text = L"Пошаговый";
			this->menu_test_step->Click += gcnew System::EventHandler(this, &MainForm::menu_test_step_Click);
			// 
			// menu_memory_set
			// 
			this->menu_memory_set->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menu_auto_update_frequency,
					this->menu_update_mode, this->menu_view_mode
			});
			this->menu_memory_set->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_memory_set.Image")));
			this->menu_memory_set->Name = L"menu_memory_set";
			this->menu_memory_set->Size = System::Drawing::Size(226, 22);
			this->menu_memory_set->Text = L"Память";
			// 
			// menu_auto_update_frequency
			// 
			this->menu_auto_update_frequency->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->menu_1_gc,
					this->menu_50_gc, this->menu_100_gc, this->menu_250_gc, this->menu_500_gc, this->menu_1000_gc
			});
			this->menu_auto_update_frequency->Name = L"menu_auto_update_frequency";
			this->menu_auto_update_frequency->Size = System::Drawing::Size(212, 22);
			this->menu_auto_update_frequency->Text = L"Частота обновлений (Гц)";
			// 
			// menu_1_gc
			// 
			this->menu_1_gc->Checked = true;
			this->menu_1_gc->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menu_1_gc->Name = L"menu_1_gc";
			this->menu_1_gc->Size = System::Drawing::Size(98, 22);
			this->menu_1_gc->Text = L"1";
			this->menu_1_gc->Click += gcnew System::EventHandler(this, &MainForm::menu_1_gc_Click);
			// 
			// menu_50_gc
			// 
			this->menu_50_gc->Name = L"menu_50_gc";
			this->menu_50_gc->Size = System::Drawing::Size(98, 22);
			this->menu_50_gc->Text = L"50";
			this->menu_50_gc->Click += gcnew System::EventHandler(this, &MainForm::menu_50_gc_Click);
			// 
			// menu_100_gc
			// 
			this->menu_100_gc->Name = L"menu_100_gc";
			this->menu_100_gc->Size = System::Drawing::Size(98, 22);
			this->menu_100_gc->Text = L"100";
			this->menu_100_gc->Click += gcnew System::EventHandler(this, &MainForm::menu_100_gc_Click);
			// 
			// menu_250_gc
			// 
			this->menu_250_gc->Name = L"menu_250_gc";
			this->menu_250_gc->Size = System::Drawing::Size(98, 22);
			this->menu_250_gc->Text = L"250";
			this->menu_250_gc->Click += gcnew System::EventHandler(this, &MainForm::menu_250_gc_Click);
			// 
			// menu_500_gc
			// 
			this->menu_500_gc->Name = L"menu_500_gc";
			this->menu_500_gc->Size = System::Drawing::Size(98, 22);
			this->menu_500_gc->Text = L"500";
			this->menu_500_gc->Click += gcnew System::EventHandler(this, &MainForm::menu_500_gc_Click);
			// 
			// menu_1000_gc
			// 
			this->menu_1000_gc->Name = L"menu_1000_gc";
			this->menu_1000_gc->Size = System::Drawing::Size(98, 22);
			this->menu_1000_gc->Text = L"1000";
			this->menu_1000_gc->Click += gcnew System::EventHandler(this, &MainForm::menu_1000_gc_Click);
			// 
			// menu_update_mode
			// 
			this->menu_update_mode->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menu_user_mode,
					this->menu_auto_mode
			});
			this->menu_update_mode->Name = L"menu_update_mode";
			this->menu_update_mode->Size = System::Drawing::Size(212, 22);
			this->menu_update_mode->Text = L"Режим обнавлений";
			// 
			// menu_user_mode
			// 
			this->menu_user_mode->Checked = true;
			this->menu_user_mode->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menu_user_mode->Name = L"menu_user_mode";
			this->menu_user_mode->Size = System::Drawing::Size(166, 22);
			this->menu_user_mode->Text = L"Ручной";
			// 
			// menu_auto_mode
			// 
			this->menu_auto_mode->Name = L"menu_auto_mode";
			this->menu_auto_mode->Size = System::Drawing::Size(166, 22);
			this->menu_auto_mode->Text = L"Автоматический";
			// 
			// menu_view_mode
			// 
			this->menu_view_mode->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menu_var,
					this->menu_cmd
			});
			this->menu_view_mode->Name = L"menu_view_mode";
			this->menu_view_mode->Size = System::Drawing::Size(212, 22);
			this->menu_view_mode->Text = L"Режим отабражения";
			// 
			// menu_var
			// 
			this->menu_var->Checked = true;
			this->menu_var->CheckOnClick = true;
			this->menu_var->CheckState = System::Windows::Forms::CheckState::Checked;
			this->menu_var->Name = L"menu_var";
			this->menu_var->Size = System::Drawing::Size(146, 22);
			this->menu_var->Text = L"Переменные";
			// 
			// menu_cmd
			// 
			this->menu_cmd->CheckOnClick = true;
			this->menu_cmd->Name = L"menu_cmd";
			this->menu_cmd->Size = System::Drawing::Size(146, 22);
			this->menu_cmd->Text = L"Команды";
			// 
			// menu_help
			// 
			this->menu_help->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menu_reference,
					this->menu_developers
			});
			this->menu_help->Name = L"menu_help";
			this->menu_help->Size = System::Drawing::Size(76, 20);
			this->menu_help->Text = L"ПОМОЩЬ";
			// 
			// menu_reference
			// 
			this->menu_reference->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_reference.Image")));
			this->menu_reference->Name = L"menu_reference";
			this->menu_reference->Size = System::Drawing::Size(151, 22);
			this->menu_reference->Text = L"Справка";
			this->menu_reference->Click += gcnew System::EventHandler(this, &MainForm::menu_reference_Click);
			// 
			// menu_developers
			// 
			this->menu_developers->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->menu_text_1,
					this->toolStripSeparator1, this->menu_grigoryan, this->menu_bandura, this->menu_eremeev, this->menu_bondarenko
			});
			this->menu_developers->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_developers.Image")));
			this->menu_developers->Name = L"menu_developers";
			this->menu_developers->Size = System::Drawing::Size(151, 22);
			this->menu_developers->Text = L"Разработчики";
			// 
			// menu_text_1
			// 
			this->menu_text_1->Name = L"menu_text_1";
			this->menu_text_1->ReadOnly = true;
			this->menu_text_1->Size = System::Drawing::Size(100, 23);
			this->menu_text_1->Text = L"AbelianGroup";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(186, 6);
			// 
			// menu_grigoryan
			// 
			this->menu_grigoryan->Name = L"menu_grigoryan";
			this->menu_grigoryan->Size = System::Drawing::Size(189, 22);
			this->menu_grigoryan->Text = L"Григорян Артем";
			this->menu_grigoryan->Click += gcnew System::EventHandler(this, &MainForm::menu_grigoryan_artem_Click);
			// 
			// menu_bandura
			// 
			this->menu_bandura->Name = L"menu_bandura";
			this->menu_bandura->Size = System::Drawing::Size(189, 22);
			this->menu_bandura->Text = L"Бандура Алексей";
			this->menu_bandura->Click += gcnew System::EventHandler(this, &MainForm::menu_bandura_Click);
			// 
			// menu_eremeev
			// 
			this->menu_eremeev->Name = L"menu_eremeev";
			this->menu_eremeev->Size = System::Drawing::Size(189, 22);
			this->menu_eremeev->Text = L"Еремеев Андрей";
			this->menu_eremeev->Click += gcnew System::EventHandler(this, &MainForm::menu_eremeev_Click);
			// 
			// menu_bondarenko
			// 
			this->menu_bondarenko->Name = L"menu_bondarenko";
			this->menu_bondarenko->Size = System::Drawing::Size(189, 22);
			this->menu_bondarenko->Text = L"Бондаренко Виталий";
			this->menu_bondarenko->Click += gcnew System::EventHandler(this, &MainForm::menu_bondarenko_Click);
			// 
			// text_box_main
			// 
			this->text_box_main->AcceptsTab = true;
			this->text_box_main->AutoWordSelection = true;
			this->text_box_main->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->text_box_main->EnableAutoDragDrop = true;
			this->text_box_main->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_box_main->Location = System::Drawing::Point(12, 54);
			this->text_box_main->Name = L"text_box_main";
			this->text_box_main->Size = System::Drawing::Size(1227, 615);
			this->text_box_main->TabIndex = 1;
			this->text_box_main->Text = L"";
			// 
			// box_debug
			// 
			this->box_debug->BackColor = System::Drawing::Color::SteelBlue;
			this->box_debug->Controls->Add(this->text_command);
			this->box_debug->Controls->Add(this->label5);
			this->box_debug->Controls->Add(this->button_do_step);
			this->box_debug->Controls->Add(this->button_start);
			this->box_debug->Controls->Add(this->button_enter);
			this->box_debug->Controls->Add(this->text_input);
			this->box_debug->Controls->Add(this->label3);
			this->box_debug->Controls->Add(this->text_errors);
			this->box_debug->Controls->Add(this->label2);
			this->box_debug->Controls->Add(this->text_output);
			this->box_debug->Controls->Add(this->label1);
			this->box_debug->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->box_debug->Location = System::Drawing::Point(964, 25);
			this->box_debug->Name = L"box_debug";
			this->box_debug->Size = System::Drawing::Size(300, 644);
			this->box_debug->TabIndex = 2;
			this->box_debug->TabStop = false;
			this->box_debug->Text = L"Панель Тестирования";
			this->box_debug->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::LightGray;
			this->label5->Location = System::Drawing::Point(6, 387);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(286, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"current command                                          ";
			// 
			// button_do_step
			// 
			this->button_do_step->BackColor = System::Drawing::Color::White;
			this->button_do_step->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_do_step->Location = System::Drawing::Point(6, 520);
			this->button_do_step->Name = L"button_do_step";
			this->button_do_step->Size = System::Drawing::Size(287, 56);
			this->button_do_step->TabIndex = 8;
			this->button_do_step->Text = L"Выполнить шаг";
			this->button_do_step->UseVisualStyleBackColor = false;
			this->button_do_step->Visible = false;
			this->button_do_step->Click += gcnew System::EventHandler(this, &MainForm::button_do_step_Click);
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::Color::White;
			this->button_start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_start->Location = System::Drawing::Point(6, 582);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(287, 56);
			this->button_start->TabIndex = 7;
			this->button_start->Text = L"Запустить";
			this->button_start->UseVisualStyleBackColor = false;
			this->button_start->Click += gcnew System::EventHandler(this, &MainForm::button_start_Click);
			// 
			// button_enter
			// 
			this->button_enter->BackColor = System::Drawing::Color::White;
			this->button_enter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_enter->Location = System::Drawing::Point(199, 343);
			this->button_enter->Name = L"button_enter";
			this->button_enter->Size = System::Drawing::Size(94, 35);
			this->button_enter->TabIndex = 6;
			this->button_enter->Text = L"Ввести";
			this->button_enter->UseVisualStyleBackColor = false;
			this->button_enter->Click += gcnew System::EventHandler(this, &MainForm::button_enter_Click);
			// 
			// text_input
			// 
			this->text_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->text_input->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_input->Location = System::Drawing::Point(6, 294);
			this->text_input->Name = L"text_input";
			this->text_input->Size = System::Drawing::Size(287, 43);
			this->text_input->TabIndex = 5;
			this->text_input->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::LightGray;
			this->label3->Location = System::Drawing::Point(6, 277);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(287, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Input                                                              ";
			// 
			// text_errors
			// 
			this->text_errors->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->text_errors->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_errors->Location = System::Drawing::Point(6, 219);
			this->text_errors->Name = L"text_errors";
			this->text_errors->ReadOnly = true;
			this->text_errors->Size = System::Drawing::Size(287, 43);
			this->text_errors->TabIndex = 3;
			this->text_errors->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightGray;
			this->label2->Location = System::Drawing::Point(6, 202);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(287, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Errors                                                            ";
			// 
			// text_output
			// 
			this->text_output->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->text_output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_output->Location = System::Drawing::Point(6, 52);
			this->text_output->Name = L"text_output";
			this->text_output->ReadOnly = true;
			this->text_output->Size = System::Drawing::Size(287, 136);
			this->text_output->TabIndex = 1;
			this->text_output->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightGray;
			this->label1->Location = System::Drawing::Point(6, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(287, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Output                                                           ";
			// 
			// button_debug_open
			// 
			this->button_debug_open->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_debug_open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_debug_open->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_debug_open->Location = System::Drawing::Point(1243, 53);
			this->button_debug_open->Name = L"button_debug_open";
			this->button_debug_open->Size = System::Drawing::Size(22, 56);
			this->button_debug_open->TabIndex = 3;
			this->button_debug_open->Text = L"<";
			this->tip->SetToolTip(this->button_debug_open, L"Панель тестирования");
			this->button_debug_open->UseVisualStyleBackColor = false;
			this->button_debug_open->Click += gcnew System::EventHandler(this, &MainForm::button_debug_open_Click);
			// 
			// button_memory_open
			// 
			this->button_memory_open->BackColor = System::Drawing::Color::OldLace;
			this->button_memory_open->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_memory_open->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_memory_open->Location = System::Drawing::Point(1243, 112);
			this->button_memory_open->Name = L"button_memory_open";
			this->button_memory_open->Size = System::Drawing::Size(22, 56);
			this->button_memory_open->TabIndex = 4;
			this->button_memory_open->Text = L"<";
			this->tip->SetToolTip(this->button_memory_open, L"Панель памяти");
			this->button_memory_open->UseVisualStyleBackColor = false;
			this->button_memory_open->Click += gcnew System::EventHandler(this, &MainForm::button_memory_open_Click);
			// 
			// open_dialog
			// 
			this->open_dialog->Filter = L"\"Файл  учебной машины (*.lm)|*.lm|Все файлы (*.*)|*.*\"";
			// 
			// save_dialog
			// 
			this->save_dialog->DefaultExt = L"lm";
			this->save_dialog->FileName = L"NewProgram";
			this->save_dialog->Filter = L"\"Файл  учебной машины (*.lm)|*.lm|Все файлы (*.*)|*.*\"";
			// 
			// box_memory
			// 
			this->box_memory->BackColor = System::Drawing::Color::SteelBlue;
			this->box_memory->Controls->Add(this->label4);
			this->box_memory->Controls->Add(this->button_a_update_memory);
			this->box_memory->Controls->Add(this->button_update_memory);
			this->box_memory->Controls->Add(this->list_memory);
			this->box_memory->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->box_memory->Location = System::Drawing::Point(1064, 25);
			this->box_memory->Name = L"box_memory";
			this->box_memory->Size = System::Drawing::Size(200, 644);
			this->box_memory->TabIndex = 3;
			this->box_memory->TabStop = false;
			this->box_memory->Text = L"Панель памяти";
			this->box_memory->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::LightGray;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(7, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(123, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Адрес / значение";
			// 
			// button_a_update_memory
			// 
			this->button_a_update_memory->BackColor = System::Drawing::Color::White;
			this->button_a_update_memory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_a_update_memory->Location = System::Drawing::Point(8, 594);
			this->button_a_update_memory->Name = L"button_a_update_memory";
			this->button_a_update_memory->Size = System::Drawing::Size(186, 44);
			this->button_a_update_memory->TabIndex = 2;
			this->button_a_update_memory->Text = L"Автомотически обновлять память";
			this->button_a_update_memory->UseVisualStyleBackColor = false;
			this->button_a_update_memory->Click += gcnew System::EventHandler(this, &MainForm::button_a_update_memory_Click);
			// 
			// button_update_memory
			// 
			this->button_update_memory->BackColor = System::Drawing::Color::White;
			this->button_update_memory->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_update_memory->Location = System::Drawing::Point(8, 544);
			this->button_update_memory->Name = L"button_update_memory";
			this->button_update_memory->Size = System::Drawing::Size(186, 44);
			this->button_update_memory->TabIndex = 1;
			this->button_update_memory->Text = L"Обновить память";
			this->button_update_memory->UseVisualStyleBackColor = false;
			this->button_update_memory->Click += gcnew System::EventHandler(this, &MainForm::button_update_memory_Click);
			// 
			// list_memory
			// 
			this->list_memory->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->list_memory->FormattingEnabled = true;
			this->list_memory->ItemHeight = 16;
			this->list_memory->Location = System::Drawing::Point(7, 39);
			this->list_memory->Name = L"list_memory";
			this->list_memory->Size = System::Drawing::Size(187, 496);
			this->list_memory->TabIndex = 0;
			// 
			// label_main
			// 
			this->label_main->AutoSize = true;
			this->label_main->BackColor = System::Drawing::Color::LightGray;
			this->label_main->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_main->Location = System::Drawing::Point(12, 37);
			this->label_main->Name = L"label_main";
			this->label_main->Size = System::Drawing::Size(124, 17);
			this->label_main->TabIndex = 5;
			this->label_main->Text = L"Новая программа";
			// 
			// timer_memory
			// 
			this->timer_memory->Tick += gcnew System::EventHandler(this, &MainForm::timer_memory_Tick);
			// 
			// main_timer
			// 
			this->main_timer->Interval = 10;
			this->main_timer->Tick += gcnew System::EventHandler(this, &MainForm::main_timer_Tick);
			// 
			// text_command
			// 
			this->text_command->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->text_command->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_command->Location = System::Drawing::Point(6, 404);
			this->text_command->Name = L"text_command";
			this->text_command->Size = System::Drawing::Size(286, 43);
			this->text_command->TabIndex = 11;
			this->text_command->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->box_debug);
			this->Controls->Add(this->label_main);
			this->Controls->Add(this->box_memory);
			this->Controls->Add(this->text_box_main);
			this->Controls->Add(this->menu_main);
			this->Controls->Add(this->button_debug_open);
			this->Controls->Add(this->button_memory_open);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu_main;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Lm Interpreter";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menu_main->ResumeLayout(false);
			this->menu_main->PerformLayout();
			this->box_debug->ResumeLayout(false);
			this->box_debug->PerformLayout();
			this->box_memory->ResumeLayout(false);
			this->box_memory->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void temp_save();

	private: System::Void view_var_in_memory();

	private: System::Void view_cmd_in_memory();

	private: System::Void open_debug_box();

	private: System::Void close_debug_box();
	
	private: System::Void button_debug_open_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->button_debug_open->Text == ">")
			this->open_debug_box();
		else
			this->close_debug_box();
	}

	private: System::Void open_memory_box();

	private: System::Void close_memory_box();

	private: System::Void button_memory_open_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->button_memory_open->Text == ">")
			this->open_memory_box();
		else
			this->close_memory_box();
	}

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->chose_lmc();
	}

	private: System::Void menu_font_Click(System::Object^  sender, System::EventArgs^  e) {
		this->font_dialog->ShowDialog();
		this->text_box_main->Font = this->font_dialog->Font;
	}

	private: System::Void menu_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	private: System::Void open_file();

	private: System::Void check_file();

	private: System::Void menu_open_file_Click(System::Object^  sender, System::EventArgs^  e) {
		this->check_file();
		this->open_file();
	}

	private: System::Void save_file();

	private: System::Void save_as_file();

	private: System::Void save_change();

	private: System::Void menu_save_as_Click(System::Object^  sender, System::EventArgs^  e) {
		this->save_as_file();
	}

	private: System::Void menu_save_Click(System::Object^  sender, System::EventArgs^  e) {
		this->save_file();
	}

	private: System::Void MainForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		if (this->current_filename->Length > 0){
			System::IO::StreamReader ^ input = gcnew System::IO::StreamReader(this->current_filename);
			System::String^ temp_str = gcnew System::String(input->ReadToEnd());
			input->Close();

			if (this->text_box_main->Text != temp_str){
				System::Windows::Forms::DialogResult answer = MessageBox::Show("Сохранить изменения перед выходом?", "Lm Interpreter", MessageBoxButtons::YesNoCancel);

				if (answer == System::Windows::Forms::DialogResult::Cancel)
					e->Cancel = true;

				if (answer == System::Windows::Forms::DialogResult::Yes)
					this->save_file();
			}
		}
		else{
			if (this->text_box_main->Text->Length > 0){
				System::Windows::Forms::DialogResult answer = MessageBox::Show("Сохранить изменения перед выходом?", "Lm Interpreter", MessageBoxButtons::YesNoCancel);

				if (answer == System::Windows::Forms::DialogResult::Cancel)
					e->Cancel = true;

				if (answer == System::Windows::Forms::DialogResult::Yes)
					this->save_file();
			}
		}
	}

	private: System::Void menu_create_file_Click(System::Object^  sender, System::EventArgs^  e) {
		this->label_main->Text = "Новая программа";
		this->current_filename = "";
		this->text_box_main->Text = "";
	}

	private: System::Void button_enter_Click(System::Object^  sender, System::EventArgs^  e) {
		this->text_output->Text += this->text_input->Text + "\n";
		this->lmc->input(Convert::ToInt32(this->text_input->Text));
		this->text_input->Text = "";
	}

	private: System::Void button_update_memory_Click(System::Object^  sender, System::EventArgs^  e) {
		this->list_memory->Items->Clear();

		if (this->menu_var->Checked)
			this->view_var_in_memory();

		if (this->menu_cmd->Checked)
			this->view_cmd_in_memory();
	}

	private: System::Void chose_lmc(){
		if (this->menu_lm_3->Checked)
			this->lmc = new LmInterpreter(new Lm3);

		if (this->menu_lm_2->Checked)
			this->lmc = new LmInterpreter(new Lm2);

		if (this->menu_lm_rm->Checked)
			this->lmc = new LmInterpreter(new Lm1);
	}

	private: System::Void start_program();

	private: System::Void stop_program();

	private: System::Void button_start_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->button_start->Text == "Запустить")
			this->start_program();
		else
			this->stop_program();
	}

	private: System::Void button_do_step_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->lmc->is_end())
			this->stop_program();

		try{
			this->lmc->step(this->text_output);
		}
		catch (std::exception& exp){
			System::String^ err = gcnew System::String(exp.what());
			this->text_errors->Text = err;
		}

		System::String^ temp = gcnew System::String(this->lmc->current_command().c_str());
		this->text_command->Text = temp;
	}

	private: System::Void memory_auto_update_on(){
		this->menu_auto_mode->Checked = true;
		this->menu_user_mode->Checked = false;

		this->button_update_memory->Hide();
		this->list_memory->Height += 48;

		this->timer_memory->Interval = (int)this->timer_intr;
		this->timer_memory->Start();
	}

	private: System::Void memory_auto_update_off(){
		this->menu_auto_mode->Checked = false;
		this->menu_user_mode->Checked = true;

		this->button_update_memory->Show();
		this->list_memory->Height -= 48;

		this->timer_memory->Stop();
	}

	private: System::Void button_a_update_memory_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->menu_auto_mode->Checked)
			this->memory_auto_update_off();
		else
			this->memory_auto_update_on();
	}

	private: System::Void menu_test_def_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_test_step->Checked = false;
		this->menu_test_def->Checked = true;
	}

	private: System::Void menu_test_step_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_test_def->Checked = false;
		this->menu_test_step->Checked = true;
	}

	private: System::Void menu_lm_3_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_lm_3->Checked = true;
		this->menu_lm_2->Checked = false;
		this->menu_lm_rm->Checked = false;
	}

	private: System::Void menu_lm_2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_lm_3->Checked = false;
		this->menu_lm_2->Checked = true;
		this->menu_lm_rm->Checked = false;
	}

	private: System::Void menu_lm_rm_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_lm_3->Checked = false;
		this->menu_lm_2->Checked = false;
		this->menu_lm_rm->Checked = true;
	}

	private: System::Void timer_memory_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->button_update_memory_Click(sender, e);
	}

	private: System::Void menu_50_gc_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_1_gc->Checked = false;
		this->menu_50_gc->Checked = true;
		this->menu_100_gc->Checked = false;
		this->menu_250_gc->Checked = false;
		this->menu_500_gc->Checked = false;
		this->menu_1000_gc->Checked = false;

		this->timer_intr = 1000 / 50;
	}

	private: System::Void menu_100_gc_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_1_gc->Checked = false;
		this->menu_50_gc->Checked = false;
		this->menu_100_gc->Checked = true;
		this->menu_250_gc->Checked = false;
		this->menu_500_gc->Checked = false;
		this->menu_1000_gc->Checked = false;

		this->timer_intr = 1000 / 100;
	}

	private: System::Void menu_1_gc_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_1_gc->Checked = true;
		this->menu_50_gc->Checked = false;
		this->menu_100_gc->Checked = false;
		this->menu_250_gc->Checked = false;
		this->menu_500_gc->Checked = false;
		this->menu_1000_gc->Checked = false;

		this->timer_intr = 1000;
	}

	private: System::Void menu_250_gc_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_1_gc->Checked = false;
		this->menu_50_gc->Checked = false;
		this->menu_100_gc->Checked = false;
		this->menu_250_gc->Checked = true;
		this->menu_500_gc->Checked = false;
		this->menu_1000_gc->Checked = false;

		this->timer_intr = 1000 / 250;
	}

	private: System::Void menu_500_gc_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_1_gc->Checked = false;
		this->menu_50_gc->Checked = false;
		this->menu_100_gc->Checked = false;
		this->menu_250_gc->Checked = false;
		this->menu_500_gc->Checked = true;
		this->menu_1000_gc->Checked = false;

		this->timer_intr = 1000 / 500;
	}

	private: System::Void menu_1000_gc_Click(System::Object^  sender, System::EventArgs^  e) {
		this->menu_1_gc->Checked = false;
		this->menu_50_gc->Checked = false;
		this->menu_100_gc->Checked = false;
		this->menu_250_gc->Checked = false;
		this->menu_500_gc->Checked = false;
		this->menu_1000_gc->Checked = true;

		this->timer_intr = 1;
	}

	private: System::Void chose_exe_file(){
		if (this->menu_lm_3->Checked)
			system("bin\\dtalmi3.exe");

		if (this->menu_lm_2->Checked)
			system("bin\\dtalmi2.exe");

		if (this->menu_lm_rm->Checked)
			system("bin\\dtalmi1.exe");
	}

	private: System::Void menu_interpret_Click(System::Object^  sender, System::EventArgs^  e) {
		this->temp_save();
		this->chose_exe_file();
	}

	private: System::Void main_timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->button_do_step_Click(sender, e);
	}

	private: System::Void menu_grigoryan_artem_Click(System::Object^  sender, System::EventArgs^  e) {
		Diagnostics::Process::Start("https://github.com/GrigoryanArtem");
	}

	private: System::Void menu_bandura_Click(System::Object^  sender, System::EventArgs^  e) {
		Diagnostics::Process::Start("https://github.com/braza501");
	}

	private: System::Void menu_eremeev_Click(System::Object^  sender, System::EventArgs^  e) {
		Diagnostics::Process::Start("https://github.com/fofancy");
	}

	private: System::Void menu_bondarenko_Click(System::Object^  sender, System::EventArgs^  e) {
		Diagnostics::Process::Start("https://github.com/Vitaliyvin");
	}

	private: System::Void menu_reference_Click(System::Object^  sender, System::EventArgs^  e) {
		Diagnostics::Process::Start("http://lmitnterpriter.besaba.com/");
	}
};
}
