#pragma once

#include <iostream>
#include <vector>

namespace ProjectForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de SubMenuTablas
	/// </summary>
	public ref class SubMenuTablas : public System::Windows::Forms::Form
	{
	public:
		SubMenuTablas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~SubMenuTablas()		{
			if (components)			{
				delete components;
			}
		}



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Dato;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Tiempo;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:

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
		void InitializeComponent(void)		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Dato = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tiempo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 206);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SubMenuTablas::button1_Click);
			// 
			// Dato
			// 
			this->Dato->HeaderText = L"Dato";
			this->Dato->Name = L"Dato";
			this->Dato->Width = 55;
			// 
			// Tiempo
			// 
			this->Tiempo->HeaderText = L"Tiempo";
			this->Tiempo->Name = L"Tiempo";
			this->Tiempo->Width = 67;
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
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(250, 160);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SubMenuTablas::dataGridView1_CellContentClick);
			// 
			// SubMenuTablas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"SubMenuTablas";
			this->Text = L"Menu Tablas";
			this->Load += gcnew System::EventHandler(this, &SubMenuTablas::SubMenuTablas_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void SubMenuTablas_Load(System::Object^ sender, System::EventArgs^ e) {
		// inicio
		
		//dataGridView1->Rows[0]->Cells[1]->Value = 21;
		//int cant = dataGridView1->RowCount;
		//printf("cantidad %d\n",cant);
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		
	}
	public: void addNombre(String^ nom) {
		this->Text = nom;
	}
	public: void addFila(float tiempo, float dato) {
		//dataGridView1->RowCount();
		dataGridView1->Rows->Add(tiempo, dato);
	}
	public: void importarRegistros(std::vector<float> vecTiempo, std::vector<float> vecDato) {
		for (int i = 0; i < vecTiempo.size(); i++) {
			addFila(vecTiempo.at(i), vecDato.at(i));
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		addFila(0.3f, 33.2f);
	}
	
};
}
