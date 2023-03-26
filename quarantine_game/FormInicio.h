#pragma once
#include "FormJuego.h"
#include "CIntrucciones.h"

namespace QuarantineGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de FormInicio
	/// </summary>
	public ref class FormInicio : public System::Windows::Forms::Form
	{
	public:
		FormInicio(void)
		{
			ptrSalir = new bool;
			*ptrSalir = false;
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormInicio()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	protected:

	private:
		bool* ptrSalir;
		CIntrucciones* objInstrucciones = new CIntrucciones();
		Bitmap^ bmpMenu = gcnew Bitmap("menu.png");
	private: System::Windows::Forms::Panel^ panelControles;




	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::PictureBox^ ptbCerrar;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::GroupBox^ groupBox2;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormInicio::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelControles = (gcnew System::Windows::Forms::Panel());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->ptbCerrar = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelControles->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbCerrar))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::SeaGreen;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(393, 267);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Iniciar Juego";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormInicio::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &FormInicio::dentro);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &FormInicio::fuera);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormInicio::timer1_Tick_1);
			// 
			// panelControles
			// 
			this->panelControles->BackColor = System::Drawing::Color::White;
			this->panelControles->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelControles->Controls->Add(this->groupBox2);
			this->panelControles->Controls->Add(this->panel1);
			this->panelControles->Controls->Add(this->groupBox1);
			this->panelControles->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelControles->Location = System::Drawing::Point(0, 0);
			this->panelControles->Name = L"panelControles";
			this->panelControles->Size = System::Drawing::Size(790, 500);
			this->panelControles->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->panel6);
			this->groupBox2->Location = System::Drawing::Point(753, 60);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(388, 400);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::White;
			this->panel6->Location = System::Drawing::Point(6, 21);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(376, 373);
			this->panel6->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DimGray;
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(788, 40);
			this->panel1->TabIndex = 1;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->pictureBox4);
			this->panel5->Location = System::Drawing::Point(1119, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(40, 40);
			this->panel5->TabIndex = 5;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(0, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(40, 40);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 4;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &FormInicio::pictureBox4_Click);
			this->pictureBox4->MouseEnter += gcnew System::EventHandler(this, &FormInicio::pictureBox4_MouseEnter);
			this->pictureBox4->MouseLeave += gcnew System::EventHandler(this, &FormInicio::pictureBox4_MouseLeave);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox3);
			this->panel4->Location = System::Drawing::Point(1158, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(40, 40);
			this->panel4->TabIndex = 3;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(0, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(40, 40);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &FormInicio::pictureBox3_Click);
			this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &FormInicio::pictureBox3_MouseEnter);
			this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &FormInicio::pictureBox3_MouseLeave);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Consolas", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label4->Location = System::Drawing::Point(334, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Quarantine Game";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->ptbCerrar);
			this->panel2->Location = System::Drawing::Point(750, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(40, 40);
			this->panel2->TabIndex = 2;
			// 
			// ptbCerrar
			// 
			this->ptbCerrar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ptbCerrar.Image")));
			this->ptbCerrar->Location = System::Drawing::Point(-1, 0);
			this->ptbCerrar->Name = L"ptbCerrar";
			this->ptbCerrar->Size = System::Drawing::Size(40, 40);
			this->ptbCerrar->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->ptbCerrar->TabIndex = 2;
			this->ptbCerrar->TabStop = false;
			this->ptbCerrar->Click += gcnew System::EventHandler(this, &FormInicio::ptbCerrar_Click);
			this->ptbCerrar->MouseEnter += gcnew System::EventHandler(this, &FormInicio::ptbCerrar_MouseEnter);
			this->ptbCerrar->MouseLeave += gcnew System::EventHandler(this, &FormInicio::ptbCerrar_MouseLeave);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->pictureBox1);
			this->panel3->Location = System::Drawing::Point(710, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(40, 40);
			this->panel3->TabIndex = 4;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(40, 40);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &FormInicio::pictureBox1_Click);
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &FormInicio::pictureBox2_MouseEnter);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &FormInicio::pictureBox1_MouseLeave);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::White;
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->numericUpDown2);
			this->groupBox1->Controls->Add(this->btnInstrucciones);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->pictureBox2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(47, 60);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(700, 400);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &FormInicio::groupBox1_Enter);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(370, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Nombre";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(478, 99);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(203, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(368, 174);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Tiempo (min)";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown2->Location = System::Drawing::Point(478, 172);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(203, 23);
			this->numericUpDown2->TabIndex = 2;
			this->numericUpDown2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->BackColor = System::Drawing::Color::Gray;
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->ForeColor = System::Drawing::Color::White;
			this->btnInstrucciones->Location = System::Drawing::Point(540, 267);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(131, 38);
			this->btnInstrucciones->TabIndex = 5;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = false;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FormInicio::btnInstrucciones_Click);
			this->btnInstrucciones->MouseEnter += gcnew System::EventHandler(this, &FormInicio::btnInstrucciones_MouseEnter);
			this->btnInstrucciones->MouseLeave += gcnew System::EventHandler(this, &FormInicio::btnInstrucciones_MouseLeave);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(370, 139);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Vidas";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(368, 206);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Dificultad";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(478, 137);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(203, 23);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(478, 203);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->comboBox1->Size = System::Drawing::Size(203, 23);
			this->comboBox1->TabIndex = 3;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(29, 53);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(321, 303);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &FormInicio::pictureBox2_Click);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 200;
			this->timer2->Tick += gcnew System::EventHandler(this, &FormInicio::timer2_Tick);
			// 
			// FormInicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(790, 500);
			this->Controls->Add(this->panelControles);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormInicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormInicio";
			this->Load += gcnew System::EventHandler(this, &FormInicio::FormInicio_Load);
			this->panelControles->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ptbCerrar))->EndInit();
			this->panel3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int dificultad;
		
		if (textBox1->Text != "") {
			String^ nombre = textBox1->Text;
			if (comboBox1->Text == "Normal" || comboBox1->Text == "Dificil") {
				if (comboBox1->Text == "Normal") dificultad = 1;
				else dificultad = 2;
				textBox1->Text = "";
				int vidasJugador = Convert::ToInt32(numericUpDown1->Text);
				int tiempoJuego = Convert::ToInt32(numericUpDown2->Text);
				FormJuego^ ventJugar = gcnew FormJuego(vidasJugador, dificultad, ptrSalir, tiempoJuego, nombre);
				ventJugar->Show();
				this->Hide();
				timer2->Stop();
			}
			else {
				MessageBox::Show("Rellene todos los campos, por favor ...", "Campos Vacios", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				comboBox1->Focus();
			}
		}
		else {
			MessageBox::Show("Rellene todos los campos, por favor ...", "Campos Vacios", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			textBox1->Focus();
		}
	}
	private: System::Void FormInicio_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->Items->Add("Normal");
		comboBox1->Items->Add("Dificil");
		panel6->Visible = false;
		groupBox2->Visible = false;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {	
	}
	private: System::Void timer1_Tick_1(System::Object^ sender, System::EventArgs^ e) {
		if (*ptrSalir == true) {
			this->Show();
			*+ptrSalir = false;
		}
		
	}
	private: System::Void ptbVideoInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	WindowState = FormWindowState::Minimized;
}
private: System::Void ptbCerrar_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void pictureBox2_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	panel3->BackColor = Color::Black;
}
private: System::Void pictureBox1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	panel3->BackColor = Color::DimGray;
}
private: System::Void ptbCerrar_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	panel2->BackColor = Color::Red;
}
private: System::Void ptbCerrar_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	panel2->BackColor = Color::DimGray;
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	int aumento = 308;
	if (this->Width <= 595) {
		objInstrucciones->cambiar_indX(0);
		objInstrucciones->cambiar_indY(0);
		this->Width = this->Width + aumento;
		pictureBox1->Visible = false;
		ptbCerrar->Visible = false;
		panel2->Visible = false;
		panel3->Visible = false;
		panel6->Visible = true;
		groupBox2->Visible = true;
		timer2->Start();
		
	}
	else {
		this->Width = 595;
		pictureBox1->Visible = true;
		ptbCerrar->Visible = true;
		panel2->Visible = true;
		panel3->Visible = true;
		panel6->Visible = false;
		groupBox2->Visible = false;
		timer2->Stop();
	}
}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	WindowState = FormWindowState::Minimized;
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void pictureBox3_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	panel4->BackColor = Color::DimGray;
}
private: System::Void pictureBox3_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	panel4->BackColor = Color::Red;
}
private: System::Void pictureBox4_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	panel5->BackColor = Color::Black;
}
private: System::Void pictureBox4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	panel5->BackColor = Color::DimGray;
}
private: System::Void dentro(System::Object^ sender, System::EventArgs^ e) {
	button1->BackColor = Color::LightSeaGreen;
}
private: System::Void fuera(System::Object^ sender, System::EventArgs^ e) {
	button1->BackColor = Color::SeaGreen;
}
private: System::Void btnInstrucciones_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btnInstrucciones->BackColor = Color::Silver;
}
private: System::Void btnInstrucciones_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btnInstrucciones->BackColor = Color::Gray;
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	Graphics^ g = panel6->CreateGraphics();
	BufferedGraphicsContext^ espaciobuffer = BufferedGraphicsManager::Current;
	BufferedGraphics^ buffer = espaciobuffer->Allocate(g, panel6->ClientRectangle);
	buffer->Graphics->Clear(Color::White);
	objInstrucciones->mover_instrucciones(buffer->Graphics, bmpMenu);
	buffer->Render(g);
	delete buffer;
	delete espaciobuffer;
	delete g;
}
};
}
