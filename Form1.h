#pragma once
#include "../ViajeDelReyDeLaPradera/Controller.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		Controller^ ocontroller = gcnew Controller();

		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 631);
			this->Name = L"Form1";
			this->Text = L"Viaje del Rey de La Pradera";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::Form1_KeyPress);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		ocontroller->jugar(buffer);
		buffer->Render(g);
	}

	private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Disparar
		if (e->KeyData == Keys::Right) {
			ocontroller->ojugador->iy = 2;
		}
		if (e->KeyData == Keys::Left) {
			ocontroller->ojugador->iy = 4;
		}
		if (e->KeyData == Keys::Down) {
			ocontroller->ojugador->iy = 3;
		}
		if (e->KeyData == Keys::Up) {
			ocontroller->ojugador->iy = 1;
		}
	}
	private: System::Void Form1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		if (e->KeyChar == char(68) || e->KeyChar == char(100)) {
			ocontroller->mover_jugador(buffer, "DER");
			ocontroller->ojugador->caminar();
		}
		if (e->KeyChar == char(65) || e->KeyChar == char(97)) {
			ocontroller->mover_jugador(buffer, "IZQ");
			ocontroller->ojugador->caminar();
		}
		if (e->KeyChar == char(83) || e->KeyChar == char(115)) {
			ocontroller->mover_jugador(buffer, "ABA");
			ocontroller->ojugador->caminar();
		}
		if (e->KeyChar == char(87) || e->KeyChar == char(119)) {
			ocontroller->mover_jugador(buffer, "ARR");
			ocontroller->ojugador->caminar();
		}
	}
	private: System::Void Form1_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		ocontroller->ojugador->iy = 0;
	}
	};
}
