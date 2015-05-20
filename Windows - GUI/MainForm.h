#pragma once

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
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::MenuStrip^  menu_main;
	protected:

	protected:

	private: System::Windows::Forms::ToolStripMenuItem^  menu_file;
	protected:

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
			this->menu_exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_view = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_font = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->button_debug_open = (gcnew System::Windows::Forms::Button());
			this->font_dialog = (gcnew System::Windows::Forms::FontDialog());
			this->tip = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->open_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->save_dialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menu_main->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_main
			// 
			this->menu_main->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->menu_main->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menu_file, this->menu_view,
					this->menu_help
			});
			this->menu_main->Location = System::Drawing::Point(0, 0);
			this->menu_main->Name = L"menu_main";
			this->menu_main->Size = System::Drawing::Size(1264, 24);
			this->menu_main->TabIndex = 0;
			this->menu_main->Text = L"menuStrip1";
			// 
			// menu_file
			// 
			this->menu_file->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->menu_create_file,
					this->menu_open_file, this->toolStripSeparator2, this->menu_save, this->menu_save_as, this->toolStripSeparator3, this->menu_exit
			});
			this->menu_file->Name = L"menu_file";
			this->menu_file->Size = System::Drawing::Size(53, 20);
			this->menu_file->Text = L"ФАЙЛ";
			// 
			// menu_create_file
			// 
			this->menu_create_file->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_create_file.Image")));
			this->menu_create_file->Name = L"menu_create_file";
			this->menu_create_file->Size = System::Drawing::Size(153, 22);
			this->menu_create_file->Text = L"Создать";
			// 
			// menu_open_file
			// 
			this->menu_open_file->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_open_file.Image")));
			this->menu_open_file->Name = L"menu_open_file";
			this->menu_open_file->Size = System::Drawing::Size(153, 22);
			this->menu_open_file->Text = L"Открыть";
			this->menu_open_file->Click += gcnew System::EventHandler(this, &MainForm::menu_open_file_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(150, 6);
			// 
			// menu_save
			// 
			this->menu_save->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_save.Image")));
			this->menu_save->Name = L"menu_save";
			this->menu_save->Size = System::Drawing::Size(153, 22);
			this->menu_save->Text = L"Сохранить";
			// 
			// menu_save_as
			// 
			this->menu_save_as->Name = L"menu_save_as";
			this->menu_save_as->Size = System::Drawing::Size(153, 22);
			this->menu_save_as->Text = L"Сохранить как";
			this->menu_save_as->Click += gcnew System::EventHandler(this, &MainForm::menu_save_as_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(150, 6);
			// 
			// menu_exit
			// 
			this->menu_exit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_exit.Image")));
			this->menu_exit->Name = L"menu_exit";
			this->menu_exit->Size = System::Drawing::Size(153, 22);
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
			this->menu_font->Size = System::Drawing::Size(152, 22);
			this->menu_font->Text = L"Шрифт";
			this->menu_font->Click += gcnew System::EventHandler(this, &MainForm::menu_font_Click);
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
			this->menu_reference->Size = System::Drawing::Size(152, 22);
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
			this->menu_developers->Size = System::Drawing::Size(152, 22);
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
			this->text_box_main->EnableAutoDragDrop = true;
			this->text_box_main->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_box_main->Location = System::Drawing::Point(208, 37);
			this->text_box_main->Name = L"text_box_main";
			this->text_box_main->Size = System::Drawing::Size(831, 632);
			this->text_box_main->TabIndex = 1;
			this->text_box_main->Text = L"";
			// 
			// box_debug
			// 
			this->box_debug->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->box_debug->Location = System::Drawing::Point(1064, 27);
			this->box_debug->Name = L"box_debug";
			this->box_debug->Size = System::Drawing::Size(200, 642);
			this->box_debug->TabIndex = 2;
			this->box_debug->TabStop = false;
			this->box_debug->Text = L"Debug";
			// 
			// button_debug_open
			// 
			this->button_debug_open->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_debug_open->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_debug_open->Location = System::Drawing::Point(1045, 37);
			this->button_debug_open->Name = L"button_debug_open";
			this->button_debug_open->Size = System::Drawing::Size(22, 56);
			this->button_debug_open->TabIndex = 3;
			this->button_debug_open->Text = L">";
			this->tip->SetToolTip(this->button_debug_open, L"Панель тестирования");
			this->button_debug_open->UseVisualStyleBackColor = false;
			this->button_debug_open->Click += gcnew System::EventHandler(this, &MainForm::button_debug_open_Click);
			// 
			// open_dialog
			// 
			this->open_dialog->Filter = L"\"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*\"";
			// 
			// save_dialog
			// 
			this->save_dialog->DefaultExt = L"txt";
			this->save_dialog->Filter = L"\"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*\"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->box_debug);
			this->Controls->Add(this->text_box_main);
			this->Controls->Add(this->menu_main);
			this->Controls->Add(this->button_debug_open);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menu_main;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Lm Interpreter";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menu_main->ResumeLayout(false);
			this->menu_main->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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

	private: System::Void button_debug_open_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->button_debug_open->Text == ">"){
			this->button_debug_open->Left += 200;
			this->button_debug_open->Text = "<";
			this->box_debug->Hide();
			this->text_box_main->Width += 200;
		}
		else{
			this->button_debug_open->Left -= 200;
			this->button_debug_open->Text = ">";
			this->box_debug->Show();
			this->text_box_main->Width -= 200;
		}
	}

	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}

	private: System::Void menu_font_Click(System::Object^  sender, System::EventArgs^  e) {
		this->font_dialog->ShowDialog();
		this->text_box_main->Font = this->font_dialog->Font;
	}

	private: System::Void menu_exit_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Exit();
	}

	private: System::Void menu_open_file_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->open_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			System::IO::StreamReader ^ input = gcnew System::IO::StreamReader(this->open_dialog->FileName);
			this->text_box_main->Text = input->ReadToEnd();
			input->Close();
		}
	}

	private: System::Void menu_save_as_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->save_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			System::IO::File::WriteAllText(this->save_dialog->FileName, this->text_box_main->Text);
	}
};
}
