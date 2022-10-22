#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "SerialClass.h"
#include "PlanoXY.h"

namespace ProjectForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Resumen de SubMenuArduino
	/// </summary>
	public ref class SubMenuArduino : public System::Windows::Forms::Form	{

	private:
		Serial* arduino;
		//bool flagS1;
		//bool flagS2;
		//int* per1;
		//int* per2;
		//int* estS1;
		//int* estS2;
		PlanoXY* copiaPlanoXY;

	public:
		SubMenuArduino(void)		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->comboBoxS1->SelectedIndex = 0;
			this->comboBoxS2->SelectedIndex = 0;
			//flagS1 = false;
			//flagS2 = false;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~SubMenuArduino()		{
			if (components)			{
				delete components;
			}
		}
	public: void setArduino(Serial* ard) {
		arduino = ard;
	}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBoxS1;
	private: System::Windows::Forms::Label^ labelS1;
	protected:









	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ s1Mili;







	private: System::Windows::Forms::RadioButton^ rb1Per;






	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;








	private: System::Windows::Forms::RadioButton^ rb1Man;
	private: System::Windows::Forms::Button^ butS1;




	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ butS2;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ s2Mili;


	private: System::Windows::Forms::RadioButton^ rb2Man;



	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RadioButton^ rb2Per;



	private: System::Windows::Forms::ComboBox^ comboBoxS2;
	private: System::Windows::Forms::Label^ labelS2;









	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->butS1 = (gcnew System::Windows::Forms::Button());
			this->rb1Man = (gcnew System::Windows::Forms::RadioButton());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->s1Mili = (gcnew System::Windows::Forms::TextBox());
			this->rb1Per = (gcnew System::Windows::Forms::RadioButton());
			this->labelS1 = (gcnew System::Windows::Forms::Label());
			this->comboBoxS1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->butS2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->s2Mili = (gcnew System::Windows::Forms::TextBox());
			this->rb2Man = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->rb2Per = (gcnew System::Windows::Forms::RadioButton());
			this->comboBoxS2 = (gcnew System::Windows::Forms::ComboBox());
			this->labelS2 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->butS1);
			this->groupBox1->Controls->Add(this->rb1Man);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->s1Mili);
			this->groupBox1->Controls->Add(this->rb1Per);
			this->groupBox1->Controls->Add(this->labelS1);
			this->groupBox1->Controls->Add(this->comboBoxS1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(17, 16);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(745, 127);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Sensor 1";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &SubMenuArduino::groupBox1_Enter);
			// 
			// butS1
			// 
			this->butS1->Location = System::Drawing::Point(101, 68);
			this->butS1->Margin = System::Windows::Forms::Padding(4);
			this->butS1->Name = L"butS1";
			this->butS1->Size = System::Drawing::Size(100, 28);
			this->butS1->TabIndex = 22;
			this->butS1->Text = L"Aplicar";
			this->butS1->UseVisualStyleBackColor = true;
			this->butS1->Click += gcnew System::EventHandler(this, &SubMenuArduino::buttonAplicarS1);
			// 
			// rb1Man
			// 
			this->rb1Man->AutoSize = true;
			this->rb1Man->Location = System::Drawing::Point(414, 33);
			this->rb1Man->Margin = System::Windows::Forms::Padding(4);
			this->rb1Man->Name = L"rb1Man";
			this->rb1Man->Size = System::Drawing::Size(84, 24);
			this->rb1Man->TabIndex = 19;
			this->rb1Man->Text = L"Manual";
			this->rb1Man->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(613, 64);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(107, 20);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Milisegundos";
			this->label7->Click += gcnew System::EventHandler(this, &SubMenuArduino::label7_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(340, 199);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 20);
			this->label6->TabIndex = 16;
			// 
			// s1Mili
			// 
			this->s1Mili->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->s1Mili->Location = System::Drawing::Point(521, 60);
			this->s1Mili->Margin = System::Windows::Forms::Padding(4);
			this->s1Mili->Name = L"s1Mili";
			this->s1Mili->Size = System::Drawing::Size(84, 27);
			this->s1Mili->TabIndex = 15;
			this->s1Mili->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->s1Mili->TextChanged += gcnew System::EventHandler(this, &SubMenuArduino::tbMicros_TextChanged);
			// 
			// rb1Per
			// 
			this->rb1Per->AutoSize = true;
			this->rb1Per->Checked = true;
			this->rb1Per->Location = System::Drawing::Point(414, 62);
			this->rb1Per->Margin = System::Windows::Forms::Padding(4);
			this->rb1Per->Name = L"rb1Per";
			this->rb1Per->Size = System::Drawing::Size(100, 24);
			this->rb1Per->TabIndex = 14;
			this->rb1Per->TabStop = true;
			this->rb1Per->Text = L"Periodico";
			this->rb1Per->UseVisualStyleBackColor = true;
			this->rb1Per->CheckedChanged += gcnew System::EventHandler(this, &SubMenuArduino::rbAutomatico_CheckedChanged);
			// 
			// labelS1
			// 
			this->labelS1->AutoSize = true;
			this->labelS1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelS1->Location = System::Drawing::Point(9, 38);
			this->labelS1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelS1->Name = L"labelS1";
			this->labelS1->Size = System::Drawing::Size(68, 20);
			this->labelS1->TabIndex = 1;
			this->labelS1->Text = L"Sensor";
			this->labelS1->Click += gcnew System::EventHandler(this, &SubMenuArduino::label1_Click);
			// 
			// comboBoxS1
			// 
			this->comboBoxS1->FormattingEnabled = true;
			this->comboBoxS1->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"Ninguno", L"Id0 - max6675 - Temperatura", L"Id1 - bmp180 - Temperatura",
					L"Id2 - bmp180 - Presión", L"Id3 - ds18b20 - Temperatura", L"Id4 - dht11 - Temperatura", L"Id5 - dht11 - Humedad", L"Id6 - HX710 - Presión manguera",
					L"Id7 - HCSR04 - Posición ultrasónico", L"Id8 - Bmp280 - Temperatura",
					L"Id9 - Bmp280 - Presión"
			});
			this->comboBoxS1->Location = System::Drawing::Point(101, 34);
			this->comboBoxS1->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxS1->Name = L"comboBoxS1";
			this->comboBoxS1->Size = System::Drawing::Size(290, 28);
			this->comboBoxS1->TabIndex = 0;
			this->comboBoxS1->SelectedIndexChanged += gcnew System::EventHandler(this, &SubMenuArduino::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(337, 290);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cerrar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SubMenuArduino::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->butS2);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->s2Mili);
			this->groupBox2->Controls->Add(this->rb2Man);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->rb2Per);
			this->groupBox2->Controls->Add(this->comboBoxS2);
			this->groupBox2->Controls->Add(this->labelS2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(16, 150);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4);
			this->groupBox2->Size = System::Drawing::Size(745, 133);
			this->groupBox2->TabIndex = 23;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Sensor 2";
			// 
			// butS2
			// 
			this->butS2->Location = System::Drawing::Point(103, 74);
			this->butS2->Margin = System::Windows::Forms::Padding(4);
			this->butS2->Name = L"butS2";
			this->butS2->Size = System::Drawing::Size(100, 28);
			this->butS2->TabIndex = 22;
			this->butS2->Text = L"Aplicar";
			this->butS2->UseVisualStyleBackColor = true;
			this->butS2->Click += gcnew System::EventHandler(this, &SubMenuArduino::buttonAplicarS2);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(614, 70);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 20);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Milisegundos";
			// 
			// s2Mili
			// 
			this->s2Mili->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->s2Mili->Location = System::Drawing::Point(522, 66);
			this->s2Mili->Margin = System::Windows::Forms::Padding(4);
			this->s2Mili->Name = L"s2Mili";
			this->s2Mili->Size = System::Drawing::Size(84, 27);
			this->s2Mili->TabIndex = 20;
			this->s2Mili->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->s2Mili->TextChanged += gcnew System::EventHandler(this, &SubMenuArduino::textBox1_TextChanged_1);
			// 
			// rb2Man
			// 
			this->rb2Man->AutoSize = true;
			this->rb2Man->Location = System::Drawing::Point(415, 39);
			this->rb2Man->Margin = System::Windows::Forms::Padding(4);
			this->rb2Man->Name = L"rb2Man";
			this->rb2Man->Size = System::Drawing::Size(84, 24);
			this->rb2Man->TabIndex = 18;
			this->rb2Man->Text = L"Manual";
			this->rb2Man->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(340, 199);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 20);
			this->label5->TabIndex = 16;
			// 
			// rb2Per
			// 
			this->rb2Per->AutoSize = true;
			this->rb2Per->Checked = true;
			this->rb2Per->Location = System::Drawing::Point(415, 70);
			this->rb2Per->Margin = System::Windows::Forms::Padding(4);
			this->rb2Per->Name = L"rb2Per";
			this->rb2Per->Size = System::Drawing::Size(100, 24);
			this->rb2Per->TabIndex = 13;
			this->rb2Per->TabStop = true;
			this->rb2Per->Text = L"Periodico";
			this->rb2Per->UseVisualStyleBackColor = true;
			// 
			// comboBoxS2
			// 
			this->comboBoxS2->FormattingEnabled = true;
			this->comboBoxS2->Items->AddRange(gcnew cli::array< System::Object^  >(11) {
				L"Ninguno", L"Id0 - max6675 - Temperatura", L"Id1 - bmp180 - Temperatura",
					L"Id2 - bmp180 - Presion", L"Id3 - ds18b20 - Temperatura", L"Id4 - dht11 - Temperatura", L"Id5 - dht11 - Humedad", L"Id6 - HX710 - Presion manguera",
					L"Id7 - HCSR04 - Posición ultrasónico", L"Id8 - Bmp280 - Temperatura",
					L"Id9 - Bmp280 - Presión"
			});
			this->comboBoxS2->Location = System::Drawing::Point(103, 41);
			this->comboBoxS2->Margin = System::Windows::Forms::Padding(4);
			this->comboBoxS2->Name = L"comboBoxS2";
			this->comboBoxS2->Size = System::Drawing::Size(290, 28);
			this->comboBoxS2->TabIndex = 3;
			// 
			// labelS2
			// 
			this->labelS2->AutoSize = true;
			this->labelS2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelS2->Location = System::Drawing::Point(11, 44);
			this->labelS2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelS2->Name = L"labelS2";
			this->labelS2->Size = System::Drawing::Size(68, 20);
			this->labelS2->TabIndex = 2;
			this->labelS2->Text = L"Sensor";
			// 
			// SubMenuArduino
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->ClientSize = System::Drawing::Size(779, 331);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"SubMenuArduino";
			this->Text = L"Administrador de Sensores";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &SubMenuArduino::SubMenuArduino_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SubMenuArduino_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// boton aplicar
		printf("comboBoxS1: %s %d\n", this->comboBoxS1->SelectedItem->ToString(), this->comboBoxS1->SelectedIndex);
		printf("comboBoxS2: %s %d\n", this->comboBoxS2->SelectedItem->ToString(), this->comboBoxS2->SelectedIndex);

		String^ s1 = gcnew String("s1:");
		if (this->rb1Man->Checked) {
			s1 = s1->Insert(s1->Length,"1,");
		}
		else {
			s1 = s1->Insert(s1->Length, "0,");
		}
		if (this->rb1Per->Checked) {
			s1 = s1->Insert(s1->Length, "1,");
		}
		else {
			s1 = s1->Insert(s1->Length, "0,");
		}
		s1 = s1->Insert(s1->Length, this->s1Mili->Text);

		printf("s1: %s\n", s1);

	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void cargarSensores(std::string nuevoSensor) {
		//std::vector<std::string> vecSensores;
		//comboBoxS1->Items->Add(vecSensores);
	}
private: System::Void comboBoxS2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//this->rb1Esporadico->Checked = true;
	//this->rb1Automatico->Checked = false;
	//this->tb1Micros->Enabled = false;
}
private: System::Void rbAutomatico_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	//this->rbAutomatico->Checked = true;
	//this->rb1Esporadico->Checked = false;
	//this->tb1Micros->Enabled = true;
}
private: System::Void tbMicros_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonAplicarS1(System::Object^ sender, System::EventArgs^ e) {
	// sintasis: SetX,ID,MODO,MICROS
	// X:  1,2 (sensor)
	// ID: 0..7 (tipo de sensor)
	// MODO: 0 (manual), 1 (periodico)
	// MICROS: T en microsegundos, para el caso periodico
	// ejemplo: Set1,0,1,250000
	//

	char mjs[20];
	strcpy(mjs, "Set");
	strcat(mjs, "1,");

	copiaPlanoXY->setIdSen(0, this->comboBoxS1->SelectedIndex-1);
	//char sensor = this->comboBoxS1->SelectedIndex;


	switch (this->comboBoxS1->SelectedIndex) {
	case 1: strcat(mjs, "0,"); break;
	case 2: strcat(mjs, "1,"); break;
	case 3: strcat(mjs, "2,"); break;
	case 4: strcat(mjs, "3,"); break;
	case 5: strcat(mjs, "4,"); break;
	case 6: strcat(mjs, "5,"); break;
	case 7: strcat(mjs, "6,"); break;
	case 8: strcat(mjs, "7,"); break;
	}

	if (this->rb1Man->Checked) {
		strcat(mjs, "0,");
	}
	else if (this->rb1Per->Checked) {
		strcat(mjs, "1,");
	}
	char mic[6];
	sprintf(mic, "%s", this->s1Mili->Text);
	strcat(mjs, mic);
	strcat(mjs, "\n");

	//arduino->escribirDatos(mjs, 20);

	printf(" SENSOR 1 '%s'\n", mjs);

	if (this->rb1Man->Checked) {
		copiaPlanoXY->setTipoMue(0, 0);
	}
	else if (this->rb1Per->Checked) {
		copiaPlanoXY->setTipoMue(0, 1);
	}
	char mili[6];
	sprintf(mili, "%s", this->s1Mili->Text);
	copiaPlanoXY->setPeriodo(0, atoi(mili));
	copiaPlanoXY->setCambioSensor(0,true);
	copiaPlanoXY->mostrarConfSensor(0);
}

private: System::Void buttonAplicarS2(System::Object^ sender, System::EventArgs^ e) {

	char mjs[20];
	strcpy(mjs, "Set");
	strcat(mjs, "2,");

	//char sensor = this->comboBoxS2->SelectedIndex;
	copiaPlanoXY->setIdSen(1, this->comboBoxS2->SelectedIndex-1);

	switch (this->comboBoxS2->SelectedIndex) {
	case 1: strcat(mjs, "0,"); break;
	case 2: strcat(mjs, "1,"); break;
	case 3: strcat(mjs, "2,"); break;
	case 4: strcat(mjs, "3,"); break;
	case 5: strcat(mjs, "4,"); break;
	case 6: strcat(mjs, "5,"); break;
	case 7: strcat(mjs, "6,"); break;
	case 8: strcat(mjs, "7,"); break;
	case 9: strcat(mjs, "8,"); break;
	}

	if (this->rb2Man->Checked) {
		strcat(mjs, "0,");
	}
	else if (this->rb2Per->Checked) {
		strcat(mjs, "1,");
	}
	char mic[6];
	sprintf(mic, "%s", this->s2Mili->Text);
	strcat(mjs, mic);

	strcat(mjs, "\n");

	//arduino->escribirDatos(mjs, 20);
	printf(" SENSOR 2 '%s'\n", mjs);
	if (this->rb2Man->Checked) {
		copiaPlanoXY->setTipoMue(1, 0);
	}
	else if (this->rb2Per->Checked) {
		copiaPlanoXY->setTipoMue(1, 1);
	}
	char mili[6];
	sprintf(mili, "%s", this->s2Mili->Text);
	copiaPlanoXY->setPeriodo(1, atoi(mili));
	copiaPlanoXY->setCambioSensor(1,true);

	copiaPlanoXY->mostrarConfSensor(1);	
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
public: void setEstadoPlanoXY(PlanoXY* intPlanoXY) {

	copiaPlanoXY = intPlanoXY;

	//this->per1 = per1;
	//this->per2 = per2;
	int val1 = copiaPlanoXY->getPeriodo(0);
	int val2 = copiaPlanoXY->getPeriodo(1);
	s1Mili->Text = val1.ToString();
	s2Mili->Text = val2.ToString();

	this->comboBoxS1->SelectedIndex = copiaPlanoXY->getIdSensor(0)+1;
	this->comboBoxS2->SelectedIndex = copiaPlanoXY->getIdSensor(1)+1;

	if (copiaPlanoXY->getTipoMue(0) == 0) {
		this->rb1Man->Checked = true;
	}
	if (copiaPlanoXY->getTipoMue(0) == 1) {
		this->rb1Per->Checked = true;
	}
	if (copiaPlanoXY->getTipoMue(1) == 0) {
		this->rb2Man->Checked = true;
	}
	if (copiaPlanoXY->getTipoMue(1) == 1) {
		this->rb2Per->Checked = true;
	}

	
	//this->estS1 = estS1;
	//this->estS2 = estS2;
	
}
		 

private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
