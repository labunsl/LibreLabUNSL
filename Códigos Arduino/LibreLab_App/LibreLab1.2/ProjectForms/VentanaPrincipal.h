#pragma once
#include "SerialClass.h"
#include "SubMenuArduino.h"
#include "SubMenuExportar.h"
#include "SubMenuTablas.h"
#include "PlanoXY.h"

#include <iostream>


namespace ProjectForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form	{
	private:
		Serial* arduino;

		int flagEscuchando;

		// dibujoGrafica
		Graphics^ graficosPrincipal;
		PlanoXY* planoXY;
		Point clicIni, clicFin, tamResolucion, planoRes, planoPos;
		System::String^ entrada;



	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::CheckBox^ checkPuntos;
	private: System::Windows::Forms::CheckBox^ checkGrilla;
	private: System::Windows::Forms::CheckBox^ checkAutoAjuste;
	private: System::Windows::Forms::CheckBox^ checkLineas;
	private: System::Windows::Forms::CheckBox^ checkBoxBarras;
	private: System::Windows::Forms::ComboBox^ cbPuertos;
	private: System::Windows::Forms::ToolStripMenuItem^ exportarToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;


	private: SubMenuTablas^ subMenuTablas;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Tiempo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Dato;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::Label^ sen1LabNom;
	private: System::Windows::Forms::Label^ sen2LabNom;








			 bool clicDown;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//graficador = this->CreateGraphics();
			//graficador = this->pictureBoxGrafica->CreateGraphics();

			flagEscuchando = 1;
			clicDown = false;
			entrada = "";

			planoXY = new PlanoXY();
			tamResolucion.X = 1920;
			tamResolucion.Y = 1080;
			planoPos.X = 240;
			planoPos.Y = 50;
			planoRes.X = 1366 * 0.5f;
			planoRes.Y = 768 * 0.5f;

			/*for (int i = 0; i < 200; i++) {
				planoXY->agregarMuestra(1, (sin(i*0.1) * 10) + 30);
			}
			*/
			this->cbPuertos->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()		{
			if (components)			{
				delete components;
			}
			arduino->~Serial();
			//delete arduino;
		}
	private: System::Windows::Forms::Button^ bConectar;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbInfo;

	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Button^ bSalir;
	private: System::Windows::Forms::GroupBox^ groupBox1;



	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ nuevoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ salirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ edicionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ajustesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ventanaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ preferenciasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ acercaDeLibreLabToolStripMenuItem;

	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

			 /// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->bConectar = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tbInfo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bSalir = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->cbPuertos = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuevoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->edicionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ajustesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ventanaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferenciasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->acercaDeLibreLabToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBoxBarras = (gcnew System::Windows::Forms::CheckBox());
			this->checkGrilla = (gcnew System::Windows::Forms::CheckBox());
			this->checkAutoAjuste = (gcnew System::Windows::Forms::CheckBox());
			this->checkLineas = (gcnew System::Windows::Forms::CheckBox());
			this->checkPuntos = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Tiempo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Dato = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sen1LabNom = (gcnew System::Windows::Forms::Label());
			this->sen2LabNom = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// bConectar
			// 
			this->bConectar->Location = System::Drawing::Point(11, 48);
			this->bConectar->Margin = System::Windows::Forms::Padding(4);
			this->bConectar->Name = L"bConectar";
			this->bConectar->Size = System::Drawing::Size(165, 36);
			this->bConectar->TabIndex = 0;
			this->bConectar->Text = L"Conectar";
			this->bConectar->UseVisualStyleBackColor = true;
			this->bConectar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 24);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Estado:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// tbInfo
			// 
			this->tbInfo->Location = System::Drawing::Point(11, 133);
			this->tbInfo->Margin = System::Windows::Forms::Padding(4);
			this->tbInfo->Name = L"tbInfo";
			this->tbInfo->Size = System::Drawing::Size(165, 23);
			this->tbInfo->TabIndex = 2;
			this->tbInfo->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 24);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 17);
			this->label2->TabIndex = 4;
			this->label2->Text = L"DESCONECTADO";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// bSalir
			// 
			this->bSalir->Location = System::Drawing::Point(19, 484);
			this->bSalir->Margin = System::Windows::Forms::Padding(4);
			this->bSalir->Name = L"bSalir";
			this->bSalir->Size = System::Drawing::Size(126, 36);
			this->bSalir->TabIndex = 6;
			this->bSalir->Text = L"Salir";
			this->bSalir->UseVisualStyleBackColor = true;
			this->bSalir->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cbPuertos);
			this->groupBox1->Controls->Add(this->bConectar);
			this->groupBox1->Controls->Add(this->tbInfo);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(19, 43);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(205, 185);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Conexión";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// cbPuertos
			// 
			this->cbPuertos->FormattingEnabled = true;
			this->cbPuertos->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"COM1", L"COM2", L"COM3", L"COM4", L"COM5", L"COM6",
					L"COM7", L"COM8", L"COM9", L"COM10"
			});
			this->cbPuertos->Location = System::Drawing::Point(11, 91);
			this->cbPuertos->Name = L"cbPuertos";
			this->cbPuertos->Size = System::Drawing::Size(121, 25);
			this->cbPuertos->TabIndex = 0;
			this->cbPuertos->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->archivoToolStripMenuItem,
					this->edicionToolStripMenuItem, this->ventanaToolStripMenuItem, this->ayudaToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1350, 24);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nuevoToolStripMenuItem,
					this->exportarToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// nuevoToolStripMenuItem
			// 
			this->nuevoToolStripMenuItem->Name = L"nuevoToolStripMenuItem";
			this->nuevoToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->nuevoToolStripMenuItem->Text = L"Nuevo";
			// 
			// exportarToolStripMenuItem
			// 
			this->exportarToolStripMenuItem->Name = L"exportarToolStripMenuItem";
			this->exportarToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->exportarToolStripMenuItem->Text = L"Exportar";
			this->exportarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportarToolStripMenuItem_Click);
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::salirToolStripMenuItem_Click);
			// 
			// edicionToolStripMenuItem
			// 
			this->edicionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ajustesToolStripMenuItem });
			this->edicionToolStripMenuItem->Name = L"edicionToolStripMenuItem";
			this->edicionToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->edicionToolStripMenuItem->Text = L"Edición";
			// 
			// ajustesToolStripMenuItem
			// 
			this->ajustesToolStripMenuItem->Name = L"ajustesToolStripMenuItem";
			this->ajustesToolStripMenuItem->Size = System::Drawing::Size(120, 22);
			this->ajustesToolStripMenuItem->Text = L"Sensores";
			this->ajustesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ajustesToolStripMenuItem_Click);
			// 
			// ventanaToolStripMenuItem
			// 
			this->ventanaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->preferenciasToolStripMenuItem });
			this->ventanaToolStripMenuItem->Name = L"ventanaToolStripMenuItem";
			this->ventanaToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->ventanaToolStripMenuItem->Text = L"Ventana";
			this->ventanaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ventanaToolStripMenuItem_Click);
			// 
			// preferenciasToolStripMenuItem
			// 
			this->preferenciasToolStripMenuItem->Name = L"preferenciasToolStripMenuItem";
			this->preferenciasToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->preferenciasToolStripMenuItem->Text = L"Preferencias";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->acercaDeLibreLabToolStripMenuItem });
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			this->ayudaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ayudaToolStripMenuItem_Click);
			// 
			// acercaDeLibreLabToolStripMenuItem
			// 
			this->acercaDeLibreLabToolStripMenuItem->Name = L"acercaDeLibreLabToolStripMenuItem";
			this->acercaDeLibreLabToolStripMenuItem->Size = System::Drawing::Size(177, 22);
			this->acercaDeLibreLabToolStripMenuItem->Text = L"Acerca de LibreLab ";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 707);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1350, 22);
			this->statusStrip1->TabIndex = 12;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(42, 17);
			this->toolStripStatusLabel1->Text = L"Estado";
			this->toolStripStatusLabel1->Click += gcnew System::EventHandler(this, &MyForm::toolStripStatusLabel1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->checkBoxBarras);
			this->groupBox3->Controls->Add(this->checkGrilla);
			this->groupBox3->Controls->Add(this->checkAutoAjuste);
			this->groupBox3->Controls->Add(this->checkLineas);
			this->groupBox3->Controls->Add(this->checkPuntos);
			this->groupBox3->Location = System::Drawing::Point(20, 279);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(126, 187);
			this->groupBox3->TabIndex = 13;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Visualización";
			// 
			// checkBoxBarras
			// 
			this->checkBoxBarras->AutoSize = true;
			this->checkBoxBarras->Location = System::Drawing::Point(7, 77);
			this->checkBoxBarras->Name = L"checkBoxBarras";
			this->checkBoxBarras->Size = System::Drawing::Size(69, 21);
			this->checkBoxBarras->TabIndex = 4;
			this->checkBoxBarras->Text = L"Barras";
			this->checkBoxBarras->UseVisualStyleBackColor = true;
			this->checkBoxBarras->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			// 
			// checkGrilla
			// 
			this->checkGrilla->AutoSize = true;
			this->checkGrilla->Checked = true;
			this->checkGrilla->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkGrilla->Location = System::Drawing::Point(6, 128);
			this->checkGrilla->Name = L"checkGrilla";
			this->checkGrilla->Size = System::Drawing::Size(60, 21);
			this->checkGrilla->TabIndex = 3;
			this->checkGrilla->Text = L"Grilla";
			this->checkGrilla->UseVisualStyleBackColor = true;
			this->checkGrilla->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkGrilla_CheckedChanged);
			// 
			// checkAutoAjuste
			// 
			this->checkAutoAjuste->AutoSize = true;
			this->checkAutoAjuste->Checked = true;
			this->checkAutoAjuste->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkAutoAjuste->Location = System::Drawing::Point(7, 155);
			this->checkAutoAjuste->Name = L"checkAutoAjuste";
			this->checkAutoAjuste->Size = System::Drawing::Size(99, 21);
			this->checkAutoAjuste->TabIndex = 2;
			this->checkAutoAjuste->Text = L"Auto Ajuste";
			this->checkAutoAjuste->UseVisualStyleBackColor = true;
			this->checkAutoAjuste->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkAutoAjuste_CheckedChanged);
			// 
			// checkLineas
			// 
			this->checkLineas->AutoSize = true;
			this->checkLineas->Checked = true;
			this->checkLineas->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkLineas->Location = System::Drawing::Point(7, 50);
			this->checkLineas->Name = L"checkLineas";
			this->checkLineas->Size = System::Drawing::Size(69, 21);
			this->checkLineas->TabIndex = 1;
			this->checkLineas->Text = L"Lineas";
			this->checkLineas->UseVisualStyleBackColor = true;
			this->checkLineas->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkLineas_CheckedChanged);
			// 
			// checkPuntos
			// 
			this->checkPuntos->AutoSize = true;
			this->checkPuntos->Checked = true;
			this->checkPuntos->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkPuntos->Location = System::Drawing::Point(7, 23);
			this->checkPuntos->Name = L"checkPuntos";
			this->checkPuntos->Size = System::Drawing::Size(71, 21);
			this->checkPuntos->TabIndex = 0;
			this->checkPuntos->Text = L"Puntos";
			this->checkPuntos->UseVisualStyleBackColor = true;
			this->checkPuntos->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(20, 236);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 36);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Limpiar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Tiempo,
					this->Dato
			});
			this->dataGridView1->Location = System::Drawing::Point(550, 80);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(200, 587);
			this->dataGridView1->TabIndex = 15;
			// 
			// Tiempo
			// 
			this->Tiempo->HeaderText = L"Tiempo";
			this->Tiempo->Name = L"Tiempo";
			this->Tiempo->Width = 80;
			// 
			// Dato
			// 
			this->Dato->HeaderText = L"Dato";
			this->Dato->Name = L"Dato";
			this->Dato->Width = 63;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView2->Location = System::Drawing::Point(772, 80);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView2->Size = System::Drawing::Size(200, 587);
			this->dataGridView2->TabIndex = 16;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Tiempo";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 80;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Dato";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 63;
			// 
			// sen1LabNom
			// 
			this->sen1LabNom->AutoSize = true;
			this->sen1LabNom->Location = System::Drawing::Point(547, 60);
			this->sen1LabNom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sen1LabNom->Name = L"sen1LabNom";
			this->sen1LabNom->Size = System::Drawing::Size(57, 17);
			this->sen1LabNom->TabIndex = 17;
			this->sen1LabNom->Text = L"Sensor:";
			// 
			// sen2LabNom
			// 
			this->sen2LabNom->AutoSize = true;
			this->sen2LabNom->Location = System::Drawing::Point(769, 60);
			this->sen2LabNom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sen2LabNom->Name = L"sen2LabNom";
			this->sen2LabNom->Size = System::Drawing::Size(57, 17);
			this->sen2LabNom->TabIndex = 18;
			this->sen2LabNom->Text = L"Sensor:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->ClientSize = System::Drawing::Size(1350, 729);
			this->Controls->Add(this->sen2LabNom);
			this->Controls->Add(this->sen1LabNom);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->bSalir);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MyForm";
			this->Text = L"LibreLab 1.2";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			// Conectar
			if (arduino->estaConectado()) {
				arduino->~Serial();
				this->label2->Text = L"DESCONECTADO";
				this->bConectar->Text = "Conectar";
			}else {
				char puerto[7];
				sprintf(puerto, "%s", this->cbPuertos->SelectedItem->ToString());
				//printf("	puerto %s\n",puerto);
				if (arduino->conectar(puerto)) {
					this->label2->Text = L"CONECTADO";
					this->bConectar->Text = "Desconectar";
					printf("arduino->estaConectado() EXITO\n");
					tbInfo->Text = "EXIT: Puerto conectado";
				}
				else {
					tbInfo->Text = "ERROR: Puerto sin dispositivo";
				}
			}
		
		}
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

			//char hola[] = "Hola\n";
			if (!flagEscuchando) {
				arduino->escribirDatos("Hola\n", 5);
				flagEscuchando = 1;
			}
			else {
				arduino->escribirDatos("Chau\n", 5);
				flagEscuchando = 0;
			}



		}
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
			printf("MyForm_Load\n");

			arduino = new Serial();
			this->label2->Text = L"DESCONECTADO";
			this->bConectar->Text = "Conectar";

			//planoXY = new PlanoXY();

			arduino->addSensor("TempA1");
			arduino->addSensor("TempA2");
			arduino->addSensor("TempA3");

			graficosPrincipal = this->CreateGraphics();

		}

		private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {

		}
		private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void salirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
		private: System::Void ajustesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			SubMenuArduino^ subMenuArduino = gcnew SubMenuArduino();

			std::vector<std::string> vecSensores = arduino->getVecSensores();

			for (int i = 0; i < vecSensores.size(); i++) {
				subMenuArduino->cargarSensores(vecSensores.at(i));
			}
			subMenuArduino->Show();
			subMenuArduino->setArduino(arduino);
			subMenuArduino->setEstadoDeSensores(planoXY->getEstadoS1(), planoXY->getEstadoS2(), planoXY->getPeriodo(0), planoXY->getPeriodo(1));
		}

private: System::Void toolStripStatusLabel1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	// Refrescado
	if ((arduino->estaConectado()) && (flagEscuchando)) {

		char lectura[50];
		int byteLeidos = arduino->leerDatos(lectura, 50);
		if (byteLeidos != -1) {
			printf("leerDatos  byteLeidos:%d 	Datos:'%s'\n", byteLeidos, lectura);
			lectura[byteLeidos] = '\0';
			String^ nuevaEntrada = gcnew String(lectura);
			entrada = entrada->Concat(nuevaEntrada);
		}
	}

	if (entrada->IndexOf(';') != -1) {
		//printf("ENTRE	entrada->Length %d '%s'", entrada->Length, entrada);
		array<String^>^ arrayDatos = entrada->Split(';');
		//for (int i = 0; i < arrayDatos->Length; i++) {

			//printf(" arrayDatos[%d] '%s'\n", i, arrayDatos[i]);

			if ((arrayDatos[0]->Contains(",")) && (arrayDatos[0]->Contains("."))) {
				array<String^>^ datoDupla = arrayDatos[0]->Split(',');
				if (2 == datoDupla->Length) {
					int idSensor = int::Parse(datoDupla[0]);
					double datoSensor = stringToDouble(datoDupla[1]);

					planoXY->agregarMuestra(idSensor,datoSensor);
					//planoXY->agregarMuestra(2, 60.0f - datoSensor);
					printf("	entrada[%d]: '%s'\n", entrada->Length, entrada);

					float time = planoXY->getUltimoTiempo(idSensor);
					addFila(idSensor,time, datoSensor);

					/*if (subMenuTablas) {
						float time = planoXY->getUltimoTiempo(idSensor);
						subMenuTablas->addFila(time, datoSensor);
					}*/

					// Elimino el data ingresado
					//if (0 <= entrada->IndexOf(';')) {
						//printf("	Entra Substring[%d]: '%s' ", entrada->Length, entrada);
						entrada = entrada->Substring(entrada->IndexOf(';')+1);
						//printf("	Sale Substring[%d]: '%s'\n", entrada->Length, entrada);
					//}
				}
			}
		//}
	}

	

	
	Bitmap^ bmpBufSup = gcnew Bitmap(planoRes.X, planoRes.Y, graficosPrincipal);
	Bitmap^ bmpBufInf = gcnew Bitmap(planoRes.X, planoRes.Y, graficosPrincipal);
	Graphics^ bmpGra1 = Graphics::FromImage(bmpBufSup);
	Graphics^ bmpGra2 = Graphics::FromImage(bmpBufInf);
	planoXY->dibujarOptimo(bmpGra1,1);
	planoXY->dibujarOptimo(bmpGra2,2);
	graficosPrincipal->DrawImage(bmpBufSup, planoPos.X, planoPos.Y);
	graficosPrincipal->DrawImage(bmpBufInf, planoPos.X, planoPos.Y + 10 + planoRes.Y);
	delete bmpBufSup;
	delete bmpBufInf;
	delete bmpGra1;
	delete bmpGra2;

	
}
	private: bool hayDatos(String^ s) {
		int posComa = s->IndexOf(',');
		int posPunt = s->IndexOf('.');
		int posPyC = s->IndexOf(';');
		if ((posComa != -1) && (posPunt != -1) && (posPyC != -1)) {
			// puede haber datos
			return true;
		}
		else {
			return false;
		}
	}
	private: void getDato(String^ s) {
		array<String^>^ arrayDatos = entrada->Split(';');

	}

	private: double stringToDouble(String^ s) {
		double numDouble = 0;
		//printf("	stringToDouble %s ", s);
		int largo = s->Length;
		int posPunto = s->IndexOf('.');
		//printf("	largo:%d punto:%d", largo, posPunto);
		for (int i = posPunto-1; i >= 0; i--) {
			numDouble += (s[i] - 48) * pow(10, posPunto - 1 - i);
		}
		for (int i = posPunto + 1; i < largo; i++) {
			numDouble += (s[i] - 48) * pow(10, posPunto - i);
		}
		return numDouble;
	}

private: System::Void ayudaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	planoXY->borrarRegistros();
	arduino->escribirDatos("Rein\n", 5);
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	planoXY->verPuntos(checkPuntos->Checked);
}
private: System::Void checkLineas_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	planoXY->verLineas(checkLineas->Checked);
}
private: System::Void checkGrilla_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	planoXY->verGrilla(checkGrilla->Checked);
}
private: System::Void checkAutoAjuste_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	planoXY->setAutoAjuste(checkAutoAjuste->Checked);
}
private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	planoXY->setBarras(checkBoxBarras->Checked);
}
private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	Point^ pt = this->PointToClient(Control::MousePosition);
	clicIni.X = pt->X - planoPos.X;
	clicIni.Y = pt->Y - planoPos.Y;
	clicDown = true;
	printf("	pictureBox1_MouseDown: %d,%d\n", clicIni.X, clicIni.Y); 
	//planoXY->seleccionar(true, clicIni, clicIni);

}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	

	Point^ pt = this->PointToClient(Control::MousePosition);
	clicFin.X = pt->X - planoPos.X;
	clicFin.Y = pt->Y - planoPos.Y;

	//printf("	pictureBox1_MouseUp: %d,%d\n", clicFin.X, clicFin.Y);

	

	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		// Izquierdo		

		/*if (clicDown) {
			clicDown = false;
			if (clicIni.X > clicFin.X) {
				int aux = clicIni.X;
				clicIni.X = clicFin.X;
				clicFin.X = aux;
			}
			if (clicIni.Y < clicFin.Y) {
				int aux = clicIni.Y;
				clicIni.Y = clicFin.Y;
				clicFin.Y = aux;
			}
			if ((clicIni.X != clicFin.X) && (clicIni.Y != clicFin.Y)) {
				planoXY->acercarRegion(clicIni, clicFin);
				planoXY->seleccionar(false, clicFin, clicFin);
			}
			else {
				planoXY->alejarZoom();
			}
		}*/

		// si clic esta en graficas
		if ((planoPos.X < pt->X) && (pt->X < planoPos.X + planoRes.X)) {
			float porX = (pt->X - planoPos.X) / (float)planoRes.X;
			printf("	zoom %f\n", porX);
			float porI = porX * 0.25f;
			float porF = 1.0f - ((1.0f - porX) * 0.25f);
			planoXY->acercarRegionPorcentajesX(porI, porF);
		}

		break;
	case System::Windows::Forms::MouseButtons::Right:
		// Derecho
		planoXY->alejarZoomG1G2();
		break;
	}
}
private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (clicDown) {
		Point^ pt = this->PointToClient(Control::MousePosition);
		clicFin.X = pt->X - planoPos.X;
		clicFin.Y = pt->Y - planoPos.Y;

		Point puntoA, puntoB;
		if (clicIni.X <= clicFin.X) {
			puntoA.X = clicIni.X;
			puntoB.X = clicFin.X;
		}
		else {
			puntoA.X = clicFin.X;
			puntoB.X = clicIni.X;
		}
		if (clicIni.Y <= clicFin.Y) {
			puntoA.Y = clicIni.Y;
			puntoB.Y = clicFin.Y;
		}
		else {
			puntoA.Y = clicFin.Y;
			puntoB.Y = clicIni.Y;
		}

		//planoXY->seleccionar(true,puntoA, puntoB);
	}
}

private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_2(System::Object^ sender, System::EventArgs^ e) {

	// Initializes the variables to pass to the MessageBox::Show method.
	String^ message = "¿Esta seguro que desea borrar los datos obtenidos hasta el momento?";
	String^ caption = "Limpiar todos los datos registrados";
	MessageBoxButtons buttons = MessageBoxButtons::YesNo;
	System::Windows::Forms::DialogResult result;

	// Displays the MessageBox.
	result = MessageBox::Show(this, message, caption, buttons);
	if (result == System::Windows::Forms::DialogResult::Yes)		{
		// Closes the parent form.
		planoXY->borrarRegistros();
		dataGridView1->Rows->Clear();
		dataGridView2->Rows->Clear();
	}

}
	private: System::Void exportarToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SubMenuExportar^ subMenuExportar = gcnew SubMenuExportar();
		subMenuExportar->setPlanoXY(planoXY);
		subMenuExportar->Show();
	}
	private: System::Void MyForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		//printf("cambio tamano: %d x %d\n",this->Width, this->Height);
	
		tamResolucion.X = this->Width;
		tamResolucion.Y = this->Height;

		planoRes.X = tamResolucion.X - 700;
		planoRes.Y = ((tamResolucion.Y + planoPos.Y) * 0.52f) - planoPos.Y - 70;
		//printf("planoRes: %d x %d\n", planoRes.X, planoRes.Y);

		planoXY->setResolucion(planoRes.X, planoRes.Y);

		System::Drawing::Size size;
		size.Width = 190;
		size.Height = tamResolucion.Y - 170;

		dataGridView1->Location = Point(planoRes.X + size.Width + 80, (planoPos.Y + 30));
		dataGridView1->Size = size;
		dataGridView2->Location = Point(planoRes.X + size.Width + size.Width + 90, (planoPos.Y + 30));
		dataGridView2->Size = size;

		sen1LabNom->Location = Point(planoRes.X + size.Width + 80, planoPos.Y);
		
		sen2LabNom->Location = Point(planoRes.X + size.Width + size.Width + 90, planoPos.Y);

		this->Refresh();
	}
	private: System::Void ventanaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: void addFila(int g, float tiempo, float dato) {
		//dataGridView1->RowCount();
		switch (g) {
		case 1:
			dataGridView1->Rows->Add(tiempo, dato);
			break;
		case 2:
			dataGridView2->Rows->Add(tiempo, dato);
			break;
		}
		
	}

};
}
