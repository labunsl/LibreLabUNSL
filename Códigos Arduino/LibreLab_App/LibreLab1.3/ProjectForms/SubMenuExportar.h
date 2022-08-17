#pragma once

#include "PlanoXY.h"

namespace ProjectForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de SubMenuExportar
	/// </summary>
	public ref class SubMenuExportar : public System::Windows::Forms::Form{
	private:
		PlanoXY* planoXY;
	public:
		SubMenuExportar(void)		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~SubMenuExportar()
		{
			if (components)			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ buttonCan;
	protected:

	private: System::Windows::Forms::Button^ buttonExp;
	private: System::Windows::Forms::TextBox^ textBoxArch;
	private: System::Windows::Forms::CheckBox^ checkBoxS2;



	private: System::Windows::Forms::CheckBox^ checkBoxS1;


	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonCan = (gcnew System::Windows::Forms::Button());
			this->buttonExp = (gcnew System::Windows::Forms::Button());
			this->textBoxArch = (gcnew System::Windows::Forms::TextBox());
			this->checkBoxS2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBoxS1 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonCan);
			this->groupBox1->Controls->Add(this->buttonExp);
			this->groupBox1->Controls->Add(this->textBoxArch);
			this->groupBox1->Controls->Add(this->checkBoxS2);
			this->groupBox1->Controls->Add(this->checkBoxS1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(260, 155);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Opciones para Exportar";
			// 
			// buttonCan
			// 
			this->buttonCan->Location = System::Drawing::Point(91, 118);
			this->buttonCan->Name = L"buttonCan";
			this->buttonCan->Size = System::Drawing::Size(75, 23);
			this->buttonCan->TabIndex = 4;
			this->buttonCan->Text = L"Cancelar";
			this->buttonCan->UseVisualStyleBackColor = true;
			this->buttonCan->Click += gcnew System::EventHandler(this, &SubMenuExportar::buttonCan_Click);
			// 
			// buttonExp
			// 
			this->buttonExp->Location = System::Drawing::Point(172, 118);
			this->buttonExp->Name = L"buttonExp";
			this->buttonExp->Size = System::Drawing::Size(75, 23);
			this->buttonExp->TabIndex = 3;
			this->buttonExp->Text = L"Exportar";
			this->buttonExp->UseVisualStyleBackColor = true;
			this->buttonExp->Click += gcnew System::EventHandler(this, &SubMenuExportar::buttonExp_Click);
			// 
			// textBoxArch
			// 
			this->textBoxArch->Location = System::Drawing::Point(7, 75);
			this->textBoxArch->Name = L"textBoxArch";
			this->textBoxArch->Size = System::Drawing::Size(171, 20);
			this->textBoxArch->TabIndex = 2;
			this->textBoxArch->Text = L"backup01.dat";
			this->textBoxArch->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// checkBoxS2
			// 
			this->checkBoxS2->AutoSize = true;
			this->checkBoxS2->Location = System::Drawing::Point(7, 52);
			this->checkBoxS2->Name = L"checkBoxS2";
			this->checkBoxS2->Size = System::Drawing::Size(68, 17);
			this->checkBoxS2->TabIndex = 1;
			this->checkBoxS2->Text = L"Sensor 2";
			this->checkBoxS2->UseVisualStyleBackColor = true;
			// 
			// checkBoxS1
			// 
			this->checkBoxS1->AutoSize = true;
			this->checkBoxS1->Location = System::Drawing::Point(7, 29);
			this->checkBoxS1->Name = L"checkBoxS1";
			this->checkBoxS1->Size = System::Drawing::Size(68, 17);
			this->checkBoxS1->TabIndex = 0;
			this->checkBoxS1->Text = L"Sensor 1";
			this->checkBoxS1->UseVisualStyleBackColor = true;
			// 
			// SubMenuExportar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(284, 180);
			this->Controls->Add(this->groupBox1);
			this->Name = L"SubMenuExportar";
			this->Text = L"Exportar";
			this->Load += gcnew System::EventHandler(this, &SubMenuExportar::SubMenuExportar_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SubMenuExportar_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonCan_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void buttonExp_Click(System::Object^ sender, System::EventArgs^ e) {

	if (checkBoxS1->Checked) {	
		StreamWriter^ streamWriter1 = gcnew StreamWriter("Sen1-"+this->textBoxArch->Text);
		streamWriter1->WriteLine("Sensor 1");
		for (int i = 0; i < planoXY->getS1CantMuestras(); i++) {
			Muestra muestra = planoXY->getMuestraS1(i);
			String^ s1 = muestra.time.ToString() + "	" + muestra.data.ToString();
			streamWriter1->WriteLine(s1);
		}
		streamWriter1->Close();
	}
	if (checkBoxS2->Checked) {
		StreamWriter^ streamWriter2 = gcnew StreamWriter("Sen2-" + this->textBoxArch->Text);
		streamWriter2->WriteLine("Sensor 2");
		for (int i = 0; i < planoXY->getS2CantMuestras(); i++) {
			Muestra muestra = planoXY->getMuestraS2(i);
			String^ s1 = muestra.time.ToString() + "	" + muestra.data.ToString();
			streamWriter2->WriteLine(s1);
		}
		streamWriter2->Close();
	}


	this->Close();
}
	public: void setPlanoXY(PlanoXY* ptrPlanoXY) {
		this->planoXY = ptrPlanoXY;
	}
};
}
