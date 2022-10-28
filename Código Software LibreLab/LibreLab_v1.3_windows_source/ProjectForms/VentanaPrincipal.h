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

		int numGraficaClic;



	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::CheckBox^ checkPuntos;
	private: System::Windows::Forms::CheckBox^ checkGrilla;
	private: System::Windows::Forms::CheckBox^ checkAutoAjuste;
	private: System::Windows::Forms::CheckBox^ checkLineas;

	private: System::Windows::Forms::ComboBox^ cbPuertos;
	private: System::Windows::Forms::ToolStripMenuItem^ exportarToolStripMenuItem;
	private: System::Windows::Forms::Button^ butLimpiar;


	private: SubMenuTablas^ subMenuTablas;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Tiempo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Dato;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::Label^ sen1LabNom;
	private: System::Windows::Forms::Label^ sen2LabNom;
	private: System::Windows::Forms::Button^ butComenzar;
	private: System::Windows::Forms::Button^ butMuestra;


	private: System::Windows::Forms::Button^ butDetener;

	private: System::Windows::Forms::Label^ labS1;
	private: System::Windows::Forms::Label^ labS2;
	private: System::Windows::Forms::CheckBox^ checkS1TablaAuto;
	private: System::Windows::Forms::CheckBox^ checkS2TablaAuto;










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


	private: System::Windows::Forms::TextBox^ tbInfo;

	private: System::Windows::Forms::Label^ label2;


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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->bConectar = (gcnew System::Windows::Forms::Button());
			this->tbInfo = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
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
			this->checkGrilla = (gcnew System::Windows::Forms::CheckBox());
			this->checkAutoAjuste = (gcnew System::Windows::Forms::CheckBox());
			this->checkLineas = (gcnew System::Windows::Forms::CheckBox());
			this->checkPuntos = (gcnew System::Windows::Forms::CheckBox());
			this->butLimpiar = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Tiempo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Dato = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sen1LabNom = (gcnew System::Windows::Forms::Label());
			this->sen2LabNom = (gcnew System::Windows::Forms::Label());
			this->butComenzar = (gcnew System::Windows::Forms::Button());
			this->butMuestra = (gcnew System::Windows::Forms::Button());
			this->butDetener = (gcnew System::Windows::Forms::Button());
			this->labS1 = (gcnew System::Windows::Forms::Label());
			this->labS2 = (gcnew System::Windows::Forms::Label());
			this->checkS1TablaAuto = (gcnew System::Windows::Forms::CheckBox());
			this->checkS2TablaAuto = (gcnew System::Windows::Forms::CheckBox());
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
			this->bConectar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bConectar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->bConectar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bConectar->ForeColor = System::Drawing::Color::Black;
			this->bConectar->Location = System::Drawing::Point(8, 37);
			this->bConectar->Margin = System::Windows::Forms::Padding(4);
			this->bConectar->Name = L"bConectar";
			this->bConectar->Size = System::Drawing::Size(82, 82);
			this->bConectar->TabIndex = 0;
			this->bConectar->Text = L"Conectar";
			this->bConectar->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->bConectar->UseVisualStyleBackColor = true;
			this->bConectar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// tbInfo
			// 
			this->tbInfo->Location = System::Drawing::Point(6, 152);
			this->tbInfo->Margin = System::Windows::Forms::Padding(4);
			this->tbInfo->Name = L"tbInfo";
			this->tbInfo->ReadOnly = true;
			this->tbInfo->Size = System::Drawing::Size(185, 30);
			this->tbInfo->TabIndex = 2;
			this->tbInfo->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 123);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(183, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"DESCONECTADO";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cbPuertos);
			this->groupBox1->Controls->Add(this->bConectar);
			this->groupBox1->Controls->Add(this->tbInfo);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(19, 43);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(214, 193);
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
			this->cbPuertos->Location = System::Drawing::Point(97, 63);
			this->cbPuertos->Name = L"cbPuertos";
			this->cbPuertos->Size = System::Drawing::Size(99, 33);
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
			this->menuStrip1->Size = System::Drawing::Size(1350, 31);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nuevoToolStripMenuItem,
					this->exportarToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(81, 27);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// nuevoToolStripMenuItem
			// 
			this->nuevoToolStripMenuItem->Name = L"nuevoToolStripMenuItem";
			this->nuevoToolStripMenuItem->Size = System::Drawing::Size(158, 28);
			this->nuevoToolStripMenuItem->Text = L"Nuevo";
			// 
			// exportarToolStripMenuItem
			// 
			this->exportarToolStripMenuItem->Name = L"exportarToolStripMenuItem";
			this->exportarToolStripMenuItem->Size = System::Drawing::Size(158, 28);
			this->exportarToolStripMenuItem->Text = L"Exportar";
			this->exportarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportarToolStripMenuItem_Click);
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(158, 28);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::salirToolStripMenuItem_Click);
			// 
			// edicionToolStripMenuItem
			// 
			this->edicionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ajustesToolStripMenuItem });
			this->edicionToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->edicionToolStripMenuItem->Name = L"edicionToolStripMenuItem";
			this->edicionToolStripMenuItem->Size = System::Drawing::Size(79, 27);
			this->edicionToolStripMenuItem->Text = L"Edición";
			// 
			// ajustesToolStripMenuItem
			// 
			this->ajustesToolStripMenuItem->Name = L"ajustesToolStripMenuItem";
			this->ajustesToolStripMenuItem->Size = System::Drawing::Size(161, 28);
			this->ajustesToolStripMenuItem->Text = L"Sensores";
			this->ajustesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ajustesToolStripMenuItem_Click);
			// 
			// ventanaToolStripMenuItem
			// 
			this->ventanaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->preferenciasToolStripMenuItem });
			this->ventanaToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ventanaToolStripMenuItem->Name = L"ventanaToolStripMenuItem";
			this->ventanaToolStripMenuItem->Size = System::Drawing::Size(87, 27);
			this->ventanaToolStripMenuItem->Text = L"Ventana";
			this->ventanaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ventanaToolStripMenuItem_Click);
			// 
			// preferenciasToolStripMenuItem
			// 
			this->preferenciasToolStripMenuItem->Name = L"preferenciasToolStripMenuItem";
			this->preferenciasToolStripMenuItem->Size = System::Drawing::Size(186, 28);
			this->preferenciasToolStripMenuItem->Text = L"Preferencias";
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->acercaDeLibreLabToolStripMenuItem });
			this->ayudaToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(72, 27);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			this->ayudaToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ayudaToolStripMenuItem_Click);
			// 
			// acercaDeLibreLabToolStripMenuItem
			// 
			this->acercaDeLibreLabToolStripMenuItem->Name = L"acercaDeLibreLabToolStripMenuItem";
			this->acercaDeLibreLabToolStripMenuItem->Size = System::Drawing::Size(243, 28);
			this->acercaDeLibreLabToolStripMenuItem->Text = L"Acerca de LibreLab ";
			// 
			// statusStrip1
			// 
			this->statusStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripStatusLabel1 });
			this->statusStrip1->Location = System::Drawing::Point(0, 703);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(1350, 26);
			this->statusStrip1->TabIndex = 12;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(54, 20);
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
			this->groupBox3->Controls->Add(this->checkGrilla);
			this->groupBox3->Controls->Add(this->checkAutoAjuste);
			this->groupBox3->Controls->Add(this->checkLineas);
			this->groupBox3->Controls->Add(this->checkPuntos);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(19, 559);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(214, 187);
			this->groupBox3->TabIndex = 13;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Visualización";
			// 
			// checkGrilla
			// 
			this->checkGrilla->AutoSize = true;
			this->checkGrilla->Checked = true;
			this->checkGrilla->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkGrilla->Location = System::Drawing::Point(6, 109);
			this->checkGrilla->Name = L"checkGrilla";
			this->checkGrilla->Size = System::Drawing::Size(78, 29);
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
			this->checkAutoAjuste->Location = System::Drawing::Point(7, 136);
			this->checkAutoAjuste->Name = L"checkAutoAjuste";
			this->checkAutoAjuste->Size = System::Drawing::Size(135, 29);
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
			this->checkLineas->Location = System::Drawing::Point(7, 68);
			this->checkLineas->Name = L"checkLineas";
			this->checkLineas->Size = System::Drawing::Size(92, 29);
			this->checkLineas->TabIndex = 1;
			this->checkLineas->Text = L"Líneas";
			this->checkLineas->UseVisualStyleBackColor = true;
			this->checkLineas->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkLineas_CheckedChanged);
			// 
			// checkPuntos
			// 
			this->checkPuntos->AutoSize = true;
			this->checkPuntos->Checked = true;
			this->checkPuntos->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkPuntos->Location = System::Drawing::Point(7, 41);
			this->checkPuntos->Name = L"checkPuntos";
			this->checkPuntos->Size = System::Drawing::Size(95, 29);
			this->checkPuntos->TabIndex = 0;
			this->checkPuntos->Text = L"Puntos";
			this->checkPuntos->UseVisualStyleBackColor = true;
			this->checkPuntos->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// butLimpiar
			// 
			this->butLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butLimpiar->ForeColor = System::Drawing::Color::Black;
			this->butLimpiar->Location = System::Drawing::Point(70, 463);
			this->butLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->butLimpiar->Name = L"butLimpiar";
			this->butLimpiar->Size = System::Drawing::Size(82, 82);
			this->butLimpiar->TabIndex = 5;
			this->butLimpiar->Text = L"Limpiar";
			this->butLimpiar->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->butLimpiar->UseVisualStyleBackColor = true;
			this->butLimpiar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			this->butLimpiar->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::button1_KeyUp);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Tiempo,
					this->Dato
			});
			this->dataGridView1->Location = System::Drawing::Point(550, 80);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(200, 587);
			this->dataGridView1->TabIndex = 15;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Tiempo
			// 
			this->Tiempo->HeaderText = L"Tiempo";
			this->Tiempo->MinimumWidth = 6;
			this->Tiempo->Name = L"Tiempo";
			this->Tiempo->ReadOnly = true;
			this->Tiempo->Width = 93;
			// 
			// Dato
			// 
			this->Dato->HeaderText = L"Dato";
			this->Dato->MinimumWidth = 6;
			this->Dato->Name = L"Dato";
			this->Dato->ReadOnly = true;
			this->Dato->Width = 74;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView2->Location = System::Drawing::Point(772, 80);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView2->Size = System::Drawing::Size(200, 587);
			this->dataGridView2->TabIndex = 16;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Tiempo";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 93;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Dato";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->Width = 74;
			// 
			// sen1LabNom
			// 
			this->sen1LabNom->AutoSize = true;
			this->sen1LabNom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sen1LabNom->Location = System::Drawing::Point(547, 53);
			this->sen1LabNom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sen1LabNom->Name = L"sen1LabNom";
			this->sen1LabNom->Size = System::Drawing::Size(26, 25);
			this->sen1LabNom->TabIndex = 17;
			this->sen1LabNom->Text = L"--";
			// 
			// sen2LabNom
			// 
			this->sen2LabNom->AutoSize = true;
			this->sen2LabNom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sen2LabNom->Location = System::Drawing::Point(769, 53);
			this->sen2LabNom->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->sen2LabNom->Name = L"sen2LabNom";
			this->sen2LabNom->Size = System::Drawing::Size(26, 25);
			this->sen2LabNom->TabIndex = 18;
			this->sen2LabNom->Text = L"--";
			// 
			// butComenzar
			// 
			this->butComenzar->AccessibleDescription = L"";
			this->butComenzar->BackColor = System::Drawing::SystemColors::Window;
			this->butComenzar->Enabled = false;
			this->butComenzar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butComenzar->ForeColor = System::Drawing::Color::Black;
			this->butComenzar->Location = System::Drawing::Point(31, 285);
			this->butComenzar->Margin = System::Windows::Forms::Padding(4);
			this->butComenzar->Name = L"butComenzar";
			this->butComenzar->Size = System::Drawing::Size(82, 82);
			this->butComenzar->TabIndex = 19;
			this->butComenzar->Text = L"Comenzar";
			this->butComenzar->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->butComenzar->UseVisualStyleBackColor = false;
			this->butComenzar->Click += gcnew System::EventHandler(this, &MyForm::buttonComenzar);
			// 
			// butMuestra
			// 
			this->butMuestra->Enabled = false;
			this->butMuestra->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butMuestra->ForeColor = System::Drawing::Color::Black;
			this->butMuestra->Location = System::Drawing::Point(31, 374);
			this->butMuestra->Margin = System::Windows::Forms::Padding(4);
			this->butMuestra->Name = L"butMuestra";
			this->butMuestra->Size = System::Drawing::Size(82, 82);
			this->butMuestra->TabIndex = 20;
			this->butMuestra->Text = L"Muestra";
			this->butMuestra->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->butMuestra->UseVisualStyleBackColor = true;
			this->butMuestra->Click += gcnew System::EventHandler(this, &MyForm::butMuestra_Click);
			// 
			// butDetener
			// 
			this->butDetener->Enabled = false;
			this->butDetener->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->butDetener->ForeColor = System::Drawing::Color::Black;
			this->butDetener->Location = System::Drawing::Point(123, 285);
			this->butDetener->Margin = System::Windows::Forms::Padding(4);
			this->butDetener->Name = L"butDetener";
			this->butDetener->Size = System::Drawing::Size(82, 82);
			this->butDetener->TabIndex = 21;
			this->butDetener->Text = L"Detener";
			this->butDetener->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->butDetener->UseVisualStyleBackColor = true;
			this->butDetener->Click += gcnew System::EventHandler(this, &MyForm::butDetener_Click);
			// 
			// labS1
			// 
			this->labS1->AutoSize = true;
			this->labS1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labS1->Location = System::Drawing::Point(21, 239);
			this->labS1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labS1->Name = L"labS1";
			this->labS1->Size = System::Drawing::Size(26, 25);
			this->labS1->TabIndex = 22;
			this->labS1->Text = L"--";
			this->labS1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->labS1->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// labS2
			// 
			this->labS2->AutoSize = true;
			this->labS2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labS2->Location = System::Drawing::Point(22, 261);
			this->labS2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labS2->Name = L"labS2";
			this->labS2->Size = System::Drawing::Size(26, 25);
			this->labS2->TabIndex = 23;
			this->labS2->Text = L"--";
			this->labS2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// checkS1TablaAuto
			// 
			this->checkS1TablaAuto->AutoSize = true;
			this->checkS1TablaAuto->Checked = true;
			this->checkS1TablaAuto->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkS1TablaAuto->Location = System::Drawing::Point(552, 673);
			this->checkS1TablaAuto->Name = L"checkS1TablaAuto";
			this->checkS1TablaAuto->Size = System::Drawing::Size(148, 24);
			this->checkS1TablaAuto->TabIndex = 24;
			this->checkS1TablaAuto->Text = L"Mostrar últimos";
			this->checkS1TablaAuto->UseVisualStyleBackColor = true;
			// 
			// checkS2TablaAuto
			// 
			this->checkS2TablaAuto->AutoSize = true;
			this->checkS2TablaAuto->Checked = true;
			this->checkS2TablaAuto->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkS2TablaAuto->Location = System::Drawing::Point(774, 673);
			this->checkS2TablaAuto->Name = L"checkS2TablaAuto";
			this->checkS2TablaAuto->Size = System::Drawing::Size(148, 24);
			this->checkS2TablaAuto->TabIndex = 25;
			this->checkS2TablaAuto->Text = L"Mostrar últimos";
			this->checkS2TablaAuto->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(223)),
				static_cast<System::Int32>(static_cast<System::Byte>(226)));
			this->ClientSize = System::Drawing::Size(1350, 729);
			this->Controls->Add(this->checkS2TablaAuto);
			this->Controls->Add(this->checkS1TablaAuto);
			this->Controls->Add(this->labS2);
			this->Controls->Add(this->labS1);
			this->Controls->Add(this->butDetener);
			this->Controls->Add(this->butMuestra);
			this->Controls->Add(this->butComenzar);
			this->Controls->Add(this->sen2LabNom);
			this->Controls->Add(this->sen1LabNom);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->butLimpiar);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(800, 600);
			this->Name = L"MyForm";
			this->Text = L"LibreLab 1.3";
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
				//this->bConectar->Text = "Conectar";
				statusStrip1->BackColor = Color::Gray;
			}else {
				char puerto[7];
				sprintf(puerto, "%s", this->cbPuertos->SelectedItem->ToString());
				//printf("	puerto %s\n",puerto);
				if (arduino->conectar(puerto)) {
					this->label2->Text = L"CONECTADO";
					//this->bConectar->Text = "Desconectar";
					printf("arduino->estaConectado() EXITO\n");
					tbInfo->Text = this->cbPuertos->SelectedItem->ToString()+": conectado";
					statusStrip1->BackColor = Color::Green;
				}
				else {
					tbInfo->Text = this->cbPuertos->SelectedItem->ToString()+": sin dispositivo";
					statusStrip1->BackColor = Color::Gray;
				}
			}
			// simulacion de entradas
			/*addFila(1, 0.0f, 4);
			addFila(1, 1.0f, 5);
			addFila(1, 2.0f, 6);
			addFila(1, 3.0f, 5);
			addFila(1, 4.0f, 4);
			addFila(1, 5.0f, 3);
			addFila(1, 6.0f, 4);*/
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
			this->bConectar->Image = Image::FromFile("Conexiones.png");
			this->butComenzar->Image = Image::FromFile("Comenzar.png");
			this->butDetener->Image = Image::FromFile("Detener.png");
			this->butMuestra->Image = Image::FromFile("muestra.png");
			this->butLimpiar->Image = Image::FromFile("Limpiar.png");
			//this->bConectar->Text = "Conectar";

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
			
			if (arduino->estaConectado()) {
				printf("	ajustesToolStripMenuItem_Click\n");
				SubMenuArduino^ subMenuArduino = gcnew SubMenuArduino();

				subMenuArduino->Show();
				subMenuArduino->setArduino(arduino);
				subMenuArduino->setEstadoPlanoXY(planoXY);
				planoXY->mostrarConfSensor(0);
				planoXY->mostrarConfSensor(1);
			}
			else {
				// Initializes the variables to pass to the MessageBox::Show method.
				
				String^ caption = "Atencion"; 
				String^ message = "Primero debe conectar el modulo arduino";				
				MessageBoxButtons buttons = MessageBoxButtons::OK;
				System::Windows::Forms::DialogResult result;

				// Displays the MessageBox.
				result = MessageBox::Show(this, message, caption, buttons);
			}
			
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

				entrada = entrada->Substring(entrada->IndexOf(';')+1);
			}
		}

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



	if (planoXY->getCambioSensor(0) || planoXY->getCambioSensor(1)) {
		if ((planoXY->getIdSensor(0) == -1) && (planoXY->getIdSensor(1) == -1)) {
			butComenzar->Enabled = false;
			butDetener->Enabled = false;
			butMuestra->Enabled = false;
		}
		else if (planoXY->getCambioSensor(0)) {
			String^ str1;
			switch (planoXY->getIdSensor(0)) {
			case -1: str1 = "--"; break;
			case 0: str1 = "max6675 - Temperatura"; break;
			case 1: str1 = "bme280 #1 - Temperatura"; break;
			case 2: str1 = "bme280 #1 - Presión"; break;
			case 3: str1 = "ds18b20 - Temperatura"; break;
			case 4: str1 = "dht11 - Temperatura"; break;
			case 5: str1 = "dht11 - Humedad"; break;
			case 6: str1 = "hx710 - Presión manguera"; break;
			case 7: str1 = "hcsr04 - Posición ultrasónico"; break;
			case 8: str1 = "bme280 #2 - Temperatura"; break;
			case 9: str1 = "bme280 #2 - Presión"; break;
			}
			labS1->Text = str1;
			sen1LabNom->Text = str1;
			planoXY->setCambioSensor(0, false);

			// analizo los botones para abilitar y desabilitar
			if (planoXY->getTipoMue(0) == 0) {
				butMuestra->Enabled = true;
			}
			else if (planoXY->getTipoMue(0) == 1) {
				butComenzar->Enabled = true;
				butDetener->Enabled = false;
				planoXY->setEstadoGeneral(0);
			}
		}
		else if (planoXY->getCambioSensor(1)) {
			String^ str2;
			switch (planoXY->getIdSensor(1)) {
			case -1: str2 = "--"; break;
			case 0: str2 = "max6675 - Temperatura"; break;
			case 1: str2 = "bme280 #1 - Temperatura"; break;
			case 2: str2 = "bme280 #1 - Presión"; break;
			case 3: str2 = "ds18b20 - Temperatura"; break;
			case 4: str2 = "dht11 - Temperatura"; break;
			case 5: str2 = "dht11 - Humedad"; break;
			case 6: str2 = "hx710 - Presión manguera"; break;
			case 7: str2 = "hcsr04 - Posición ultrasónico"; break;
			case 8: str2 = "bme280 #2 - Temperatura"; break;
			case 9: str2 = "bme280 #2 - Presión"; break;
			}
			labS2->Text = str2;
			sen2LabNom->Text = str2;
			planoXY->setCambioSensor(1, false);

			// analizo los botones para abilitar y desabilitar
			if (planoXY->getTipoMue(1) == 0) {
				butMuestra->Enabled = true;
			}
			else if (planoXY->getTipoMue(1) == 1) {
				butComenzar->Enabled = true;
				butDetener->Enabled = false;
				planoXY->setEstadoGeneral(0);
			}
		}
		if (planoXY->getIdSensor(0) >= 0 &&	planoXY->getTipoMue(0) == 0 &&
			planoXY->getIdSensor(1) >= 0 && planoXY->getTipoMue(1) == 0){
			
			butComenzar->Enabled = false;
			butDetener->Enabled = false;
		}
		if ((planoXY->getIdSensor(0) < 0 || 
			(planoXY->getIdSensor(0) >= 0 && planoXY->getTipoMue(0) == 1)) &&
			(planoXY->getIdSensor(1) < 0 || 
			(planoXY->getIdSensor(1) >= 0 && planoXY->getTipoMue(1) == 1))) {

			butMuestra->Enabled = false;
		}
	}

	


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
private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		// Izquierdo		

		Point^ pt = this->PointToClient(Control::MousePosition);
		clicIni.X = pt->X - planoPos.X;
		clicIni.Y = pt->Y - planoPos.Y;
		clicDown = true;
		//printf("	pictureBox1_MouseDown: %d,%d\n", clicIni.X, clicIni.Y);

		if (clicIni.Y < planoRes.Y) {
			numGraficaClic = 0;
			//printf("	arriba\n");
		}
		else {
			numGraficaClic = 1;
			//printf("	abajo\n");
			clicIni.Y = pt->Y - planoPos.Y- planoRes.Y - 10;
		}
		planoXY->seleccionar(numGraficaClic, true, clicIni, clicIni);

		//planoXY->seleccionar(1,true, clicIni, clicIni);
	}
}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

	Point^ pt = this->PointToClient(Control::MousePosition);
	clicFin.X = pt->X - planoPos.X;
	if (numGraficaClic == 0) {
		clicFin.Y = pt->Y - planoPos.Y;
	}
	else {
		clicFin.Y = pt->Y - (planoPos.Y + planoRes.Y + 10);
	}

	switch (e->Button) {
	case System::Windows::Forms::MouseButtons::Left:
		// Izquierdo		

		if (clicDown) {
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
				planoXY->acercarRegion(numGraficaClic,clicIni, clicFin);
				planoXY->seleccionar(numGraficaClic,false, clicFin, clicFin);
				this->checkAutoAjuste->Checked = false;
				planoXY->setAutoAjuste(false);
			}
			else {
				//planoXY->alejarZoom();
				planoXY->alejarZoomG1G2();
			}
		}

		// si clic esta en graficas
		if ((planoPos.X < pt->X) && (pt->X < planoPos.X + planoRes.X)) {
			float porX = (pt->X - planoPos.X) / (float)planoRes.X;
			printf("	zoom %f\n", porX);
			float porI = porX * 0.25f;
			float porF = 1.0f - ((1.0f - porX) * 0.25f);
			//planoXY->acercarRegionPorcentajesX(porI, porF);
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
		if (numGraficaClic == 0) {
			clicFin.Y = pt->Y - planoPos.Y;
		}
		else {
			clicFin.Y = pt->Y - (planoPos.Y + planoRes.Y + 10);
		}
		

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

		planoXY->seleccionar(numGraficaClic,true,puntoA, puntoB);
	}
}

private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	printf("	MyForm_KeyDown\n"); 
	switch (e->KeyCode) {
	case Keys::A:
		printf("	A\n");
		planoXY->moverRangosX(-5);
		break;
	case Keys::D:
		planoXY->moverRangosX(5);
		break;
	case Keys::Up:
		planoXY->moverRangosY(5);
		break;
	case Keys::Down:
		planoXY->moverRangosY(-5);
		break;
	}
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

		planoXY->setEstadoGeneral(0);
		butDetener_Click(sender, e);
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
		checkS1TablaAuto->Location = Point(planoRes.X + size.Width + 80, this->Height - 90);
		checkS2TablaAuto->Location = Point(planoRes.X + size.Width + size.Width + 90, this->Height - 90);

		this->Refresh();
	}
	private: System::Void ventanaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: void addFila(int g, float tiempo, float dato) {
		char uni[10];
		planoXY->getUnidad(g, uni);
		System::String^ unidad = gcnew String(uni);
		switch (g) {
		case 1:						
			dataGridView1->Rows->Add(tiempo+" s", dato + unidad);
			if (checkS1TablaAuto->Checked) {
				this->dataGridView1->FirstDisplayedScrollingRowIndex = this->dataGridView1->RowCount - 1;
			}			
			break;
		case 2:
			dataGridView2->Rows->Add(tiempo + " s", dato + unidad);
			if (checkS2TablaAuto->Checked) {
				this->dataGridView2->FirstDisplayedScrollingRowIndex = this->dataGridView2->RowCount - 1;
			}			
			break;
		}
	}

private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void buttonComenzar(System::Object^ sender, System::EventArgs^ e) {
	// sintasis: SetX,ID,MODO,MICROS
	// X:  1,2 (sensor)
	// ID: 0..7 (tipo de sensor)
	// MODO: 0 (manual), 1 (periodico)
	// MICROS: T en microsegundos, para el caso periodico
	// ejemplo: Set1,0,1,250000

	if (planoXY->getIdSensor(0) != -1) {
		// tengo un sensor seleccionado
		char mjs[20];

		strcpy(mjs, "Set1,");
		int idSen = planoXY->getIdSensor(0);
		char idChar[6];
		sprintf(idChar, "%d", idSen);
		strcat(mjs, idChar);
		strcat(mjs, ",");
		if (planoXY->getTipoMue(0) == 1) {
			strcat(mjs, "1,");
		}		else {
			strcat(mjs, "0,");
		}
		int periodo = planoXY->getPeriodo(0);
		char perChar[4];
		sprintf(perChar, "%d", periodo);
		strcat(mjs, perChar);
		strcat(mjs, "\n");

		//strcat(mjs, "0,");
		printf(" SENSOR 1 '%s'\n", mjs);
		arduino->escribirDatos(mjs, strlen(mjs));

	}
	if (planoXY->getIdSensor(1) != -1) {
		// tengo un sensor seleccionado
		char mjs[20];

		strcpy(mjs, "Set2,");
		int idSen = planoXY->getIdSensor(1);
		char idChar[6];
		sprintf(idChar, "%d", idSen);
		strcat(mjs, idChar);
		strcat(mjs, ",");
		if (planoXY->getTipoMue(1) == 1) {
			strcat(mjs, "1,");
		}		else {
			strcat(mjs, "0,");
		}
		int periodo = planoXY->getPeriodo(1);
		char perChar[6];
		sprintf(perChar, "%d", periodo);
		strcat(mjs, perChar);
		strcat(mjs, "\n");

		//strcat(mjs, "0,");
		printf(" SENSOR 2 '%s'\n", mjs);
		arduino->escribirDatos(mjs, strlen(mjs));
	}

	butComenzar->Enabled = false;
	butDetener->Enabled = true;
	planoXY->setEstadoGeneral(1);
}
private: System::Void butDetener_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((planoXY->getIdSensor(0) != -1) || (planoXY->getIdSensor(1) != -1)) {
		char mjs[20];
		strcpy(mjs, "Stop");
		printf(" '%s'\n", mjs);
		arduino->escribirDatos(mjs, strlen(mjs));
	}
	butComenzar->Enabled = true;
	butDetener->Enabled = false;
	planoXY->setEstadoGeneral(0);
}
private: System::Void butMuestra_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((planoXY->getIdSensor(0) != -1) && (planoXY->getTipoMue(0) == 0)) {
		char mjs[20];
		strcpy(mjs, "Get1\n");
		printf(" '%s'\n", mjs);
		arduino->escribirDatos(mjs, strlen(mjs));
	}
	if ((planoXY->getIdSensor(1) != -1) && (planoXY->getTipoMue(1) == 0)) {
		char mjs[20];
		strcpy(mjs, "Get2\n");
		printf(" '%s'\n", mjs);
		arduino->escribirDatos(mjs, strlen(mjs));
	}
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	checkS2TablaAuto->Checked = false;
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	checkS1TablaAuto->Checked = false;
}
private: System::Void button1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
}
};
}

// LibreLab fue desarrollado en el entorno Visual Studio en su version Community 2022.
// Se implemento en lenguaje C++ utilizando el framework Windows Forms de .NET para el manejo de ventana y eventos estandares.
// Al proyecto LibreLab se incluye los modulos de ventanas, el modulo de conexion con los sensores (kit arduino), el modulo de almacenamiento y la exportacion de los datos.
// Ademas, se incluyo el modulo de instalacion compatible con la arquitectura Windows de 64bits.
// El diseno propuesto muestra informacion acotada al usuario pensado para el uso rapido e intuitivo, con la informacion grafica como area principal de la comunicacion con el usuario.
// Dicha disposicion fue propuesta por docentes investigadores que haran uso de la herramienta frente a estudiantes de la facultad. 