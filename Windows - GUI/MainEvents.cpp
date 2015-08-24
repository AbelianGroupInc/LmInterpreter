#include "MainForm.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

System::Void LmGUI::MainForm::temp_save(){
	System::IO::File::WriteAllText(TEMP_PATH, this->text_box_main->Text);
}

System::Void LmGUI::MainForm::view_var_in_memory(){
	std::vector<std::string> temp = this->lmc->get_var_inf();

	for (int i = 0; i < (int)temp.size(); i++){
		System::String^ str = gcnew System::String(temp[i].c_str());
		this->list_memory->Items->Add(str);
	}
}

System::Void LmGUI::MainForm::view_cmd_in_memory(){
	std::vector<std::string> temp = this->lmc->get_cmd_inf();

	for (int i = 0; i < (int)temp.size(); i++){
		System::String^ str = gcnew System::String(temp[i].c_str());
		this->list_memory->Items->Add(str);
	}
}

System::Void LmGUI::MainForm::open_debug_box(){
	this->button_debug_open->Left += 300;
	this->button_memory_open->Left += 300;
	this->text_box_main->Width += 300;
	this->box_memory->Left += 300;

	this->button_debug_open->Text = "<";
	this->box_debug->Hide();
}

System::Void LmGUI::MainForm::close_debug_box(){
	this->button_debug_open->Left -= 300;
	this->button_memory_open->Left -= 300;
	this->text_box_main->Width -= 300;
	this->box_memory->Left -= 300;

	this->button_debug_open->Text = ">";
	this->box_debug->Show();
}

System::Void LmGUI::MainForm::open_memory_box(){
	this->button_debug_open->Left += 200;
	this->button_memory_open->Left += 200;
	this->button_memory_open->Text = "<";
	this->box_memory->Hide();
	this->text_box_main->Width += 200;
}

System::Void LmGUI::MainForm::close_memory_box(){
	this->button_debug_open->Left -= 200;
	this->button_memory_open->Left -= 200;
	this->button_memory_open->Text = ">";
	this->box_memory->Show();
	this->text_box_main->Width -= 200;
}

System::Void LmGUI::MainForm::open_file(){
	if (this->open_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		System::IO::StreamReader ^ input = gcnew System::IO::StreamReader(this->open_dialog->FileName);
		this->current_filename = this->open_dialog->FileName;

		this->label_main->Text = this->current_filename;
		this->text_box_main->Text = input->ReadToEnd();
		input->Close();
	}
}

System::Void LmGUI::MainForm::save_file(){
	if (!this->current_filename->Length){
		this->save_as_file();
		return;
	}

	System::IO::File::WriteAllText(this->current_filename, this->text_box_main->Text);
}

System::Void LmGUI::MainForm::save_as_file(){
	if (this->save_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		System::IO::File::WriteAllText(this->save_dialog->FileName, this->text_box_main->Text);
		this->current_filename = this->save_dialog->FileName;
		this->label_main->Text = this->current_filename;
	}
}

System::Void LmGUI::MainForm::save_change(){
	if (MessageBox::Show("Сохранить изменения?", "Lm Interpreter", MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes)
		this->save_file();
}

System::Void LmGUI::MainForm::check_file(){
	if (this->current_filename->Length > 0){
		System::IO::StreamReader ^ input = gcnew System::IO::StreamReader(this->current_filename);
		System::String^ temp_str = gcnew System::String(input->ReadToEnd());
		input->Close();

		if (this->text_box_main->Text != temp_str)
			this->save_change();
	}
	else{
		if (this->text_box_main->Text->Length > 0)
			this->save_change();
	}
}

System::Void LmGUI::MainForm::start_program(){
	this->button_start->Text = "Остановить";

	this->text_output->Text = "";
	this->text_errors->Text = "";
	this->temp_save();

	try{
		this->chose_lmc();
		this->lmc->read_program(TEMP_PATH);
		this->lmc->init_program();
	}
	catch (std::exception& exp){
		System::String^ err = gcnew System::String(exp.what());
		this->text_errors->Text = err;
		this->stop_program();
	}

	System::String^ temp = gcnew System::String(this->lmc->current_command().c_str());
	this->text_command->Text = temp;

	if (this->menu_test_def->Checked)
		this->main_timer->Start();
	else
		this->button_do_step->Show();
}

System::Void LmGUI::MainForm::stop_program(){
	this->button_start->Text = "Запустить";

	if (this->menu_test_def->Checked)
		this->main_timer->Stop();
	else
		this->button_do_step->Hide();
}