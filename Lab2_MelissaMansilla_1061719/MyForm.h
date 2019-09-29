#pragma once
#include "Carrera.h"

namespace Lab2MelissaMansilla1061719 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  empezarbtn;
	private: System::Windows::Forms::Button^  crearbtn;
	protected:

	private: System::Windows::Forms::Label^  detalleslbl;
	private: System::Windows::Forms::RichTextBox^  RTBregistro;
	private: System::Windows::Forms::Timer^  PasoT;
	private: System::Windows::Forms::Label^  label1;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->empezarbtn = (gcnew System::Windows::Forms::Button());
			this->crearbtn = (gcnew System::Windows::Forms::Button());
			this->detalleslbl = (gcnew System::Windows::Forms::Label());
			this->RTBregistro = (gcnew System::Windows::Forms::RichTextBox());
			this->PasoT = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// empezarbtn
			// 
			this->empezarbtn->Location = System::Drawing::Point(12, 138);
			this->empezarbtn->Name = L"empezarbtn";
			this->empezarbtn->Size = System::Drawing::Size(140, 43);
			this->empezarbtn->TabIndex = 1;
			this->empezarbtn->Text = L"Empezar Carrera";
			this->empezarbtn->UseVisualStyleBackColor = true;
			this->empezarbtn->Click += gcnew System::EventHandler(this, &MyForm::empezarbtn_Click);
			// 
			// crearbtn
			// 
			this->crearbtn->Location = System::Drawing::Point(12, 78);
			this->crearbtn->Name = L"crearbtn";
			this->crearbtn->Size = System::Drawing::Size(140, 43);
			this->crearbtn->TabIndex = 0;
			this->crearbtn->Text = L"Crear Pista";
			this->crearbtn->UseVisualStyleBackColor = true;
			this->crearbtn->Click += gcnew System::EventHandler(this, &MyForm::reiniciarbtn_Click);
			// 
			// detalleslbl
			// 
			this->detalleslbl->AutoSize = true;
			this->detalleslbl->Location = System::Drawing::Point(327, 30);
			this->detalleslbl->Name = L"detalleslbl";
			this->detalleslbl->Size = System::Drawing::Size(162, 20);
			this->detalleslbl->TabIndex = 2;
			this->detalleslbl->Text = L"Detalles de la Carrera";
			// 
			// RTBregistro
			// 
			this->RTBregistro->Location = System::Drawing::Point(158, 63);
			this->RTBregistro->Name = L"RTBregistro";
			this->RTBregistro->Size = System::Drawing::Size(488, 331);
			this->RTBregistro->TabIndex = 3;
			this->RTBregistro->Text = L"";
			// 
			// PasoT
			// 
			this->PasoT->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 20);
			this->label1->TabIndex = 4;
			this->label1->Text = L"CREAR PISTA PRIMERO*";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 420);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->RTBregistro);
			this->Controls->Add(this->detalleslbl);
			this->Controls->Add(this->crearbtn);
			this->Controls->Add(this->empezarbtn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Se crea un objeto carrera con el fin de apuntar a la posicion del animal.
		//tambien ayuda en la generación del numero random hasta que las iteraciones se cumplan y uno llegue a la meta.
		public: Carrera *carrera = new Carrera();

	private: System::Void empezarbtn_Click(System::Object^  sender, System::EventArgs^  e) {
		RTBregistro->Text = "¡BANG!" + "\n ¡Y ARRANCAN!";
		PasoT->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Random^ r = gcnew Random();
		if (carrera->PosL() >= 70) {
			RTBregistro->Text = RTBregistro->Text + "\n" + "\n La liebre gana. Ni hablar";
			PasoT->Enabled = false;
		}
		else if (carrera->PosH() >= 70) {
			RTBregistro->Text = RTBregistro->Text + "\n" + "\n ¡LA TORTUGA GANA! ¡BRAVO!";
			PasoT->Enabled = false;
		}
		else if ((carrera->PosL() >= 70) && (carrera->PosH() >= 70)) {
			RTBregistro->Text = RTBregistro->Text + "\n" +"\n Es un empate";
			PasoT->Enabled = false;
		}
		else {
			carrera->PL(r->Next(1, 10));
			carrera->PH(r->Next(1, 10));
			if (carrera->PosL() != carrera->PosH()) {
				RTBregistro->Text = RTBregistro->Text + "\n *****";
				RTBregistro->Text = RTBregistro->Text + "\n  Liebre=" + 
				(System::Convert::ToString(carrera->PosL())) + " Tortuga=" + (System::Convert::ToString(carrera->PosH()));
			}
			else {
				RTBregistro->Text = RTBregistro->Text + "\n ******";
				RTBregistro->Text = RTBregistro->Text + "\n  OUCH!";
			}
		}
	}
private: System::Void reiniciarbtn_Click(System::Object^  sender, System::EventArgs^  e) {
	carrera->CrearPista();
	
}
};
}
