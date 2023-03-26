#pragma once
#include "CJuego.h"
#include <Windows.h>

namespace QuarantineGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de FormJuego
	/// </summary>
	public ref class FormJuego : public System::Windows::Forms::Form 
	{
	private:

	public:
		FormJuego(int vidas, int _dificultad, bool* _ptrSalir, int tiempoJuego, String^ _nombre)
		{
			InitializeComponent();
			nombre = _nombre;
			tiempoDJuego = tiempoJuego;
			dificultad = _dificultad;
			vidasJugador = vidas;
			TPantalla = this->CreateGraphics();
			MAX_ANCHO = TPantalla->VisibleClipBounds.Width;
			MAX_ALTO = TPantalla->VisibleClipBounds.Height;
			delete TPantalla;
			objJuego = new CJuego(MAX_ANCHO, MAX_ALTO, vidasJugador, dificultad, tiempoDJuego);
			ptrSalir = _ptrSalir;
			tiemp_seg = tiemp_min = tiemp_hor = 0;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormJuego()
		{
			if (components)
			{
				delete components;
				delete objJuego;
			}
		}

	private:
		String^ nombre;
		int tiempoDJuego;
		int vidasJugador;
		int tiemp_seg, tiemp_min, tiemp_hor;
		Graphics^ TPantalla;
		int MAX_ALTO;
		int MAX_ANCHO;
		SoundPlayer^ sonido1 = gcnew SoundPlayer("Sonido1.wav");
		SoundPlayer^ sonido2 = gcnew SoundPlayer("Sonido2.wav");
		CJuego* objJuego;
		Bitmap^ bmpJugador = gcnew Bitmap("Person_princ_final.png");
		Bitmap^ mundoIrresponsable = gcnew Bitmap("mapa_mundoIrresponsable.png");
		Bitmap^ mundoResponsable = gcnew Bitmap("mapa_mundoResponsable.png");
		Bitmap^ bmpVidas = gcnew Bitmap("vidas_e.png");
		Bitmap^ bmpBala = gcnew Bitmap("BalaCarta.png");
		Bitmap^ bmpAdversarios1 = gcnew Bitmap("enemigo_pobre.png");
		Bitmap^ bmpAdversarios2 = gcnew Bitmap("enemigo_rico.png");
		Bitmap^ bmpBasura = gcnew Bitmap("basura.png");
		Bitmap^ bmpMensaje = gcnew Bitmap("mensajes.png");
		Bitmap^ bmpAmbulancia = gcnew Bitmap("ambulancia.png");
		Bitmap^ bmpPolicia = gcnew Bitmap("policia_final.png");
		Bitmap^ bmpPlataforma = gcnew Bitmap("base_del_personaje.png");
		Bitmap^ bmpNivel = gcnew Bitmap("nivel.png");
		Bitmap^ bmpLetrero1 = gcnew Bitmap("letrero1.png");
		Bitmap^ bmpLetrero2 = gcnew Bitmap("letrero2.png");
		int vidas, dificultad;
		bool* ptrSalir;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 75;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormJuego::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &FormJuego::timer2_Tick);
			// 
			// FormJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 507);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FormJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormJuego";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormJuego::FormJuego_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &FormJuego::FormJuego_FormClosed);
			this->Load += gcnew System::EventHandler(this, &FormJuego::FormJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormJuego::presionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormJuego::soltarTecla);
			this->ResumeLayout(false);

		}
		
#pragma endregion
	private: System::Void FormJuego_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {	
		
	}
	private: System::Void FormJuego_Load(System::Object^ sender, System::EventArgs^ e) {
		if (dificultad == 2) {
			sonido1->PlayLooping();
		}
		else if (dificultad == 1)
			sonido2->PlayLooping();
	}
	private: System::Void FormJuego_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		*ptrSalir = true;
		sonido1->Stop();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		objJuego->DinamicaDelJuego(buffer, bmpJugador, mundoResponsable, mundoIrresponsable, bmpVidas, bmpBala, 0, 
			bmpAdversarios1, bmpAdversarios2, bmpBasura, bmpMensaje, bmpAmbulancia, bmpPolicia, bmpPlataforma, bmpNivel,
			bmpLetrero1, bmpLetrero2);

		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void presionarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
		case Keys::Left:
			objJuego->retornar_objJugador()->direccion = Direcciones::izquierda;
			break;
		case Keys::Right:
			objJuego->retornar_objJugador()->direccion = Direcciones::derecha;
			break;
		case Keys::Up:
			objJuego->retornar_objJugador()->direccion = Direcciones::arriba;
			break;
		case Keys::Down:
			objJuego->retornar_objJugador()->direccion = Direcciones::abajo;
			break;
		case Keys::Escape:
			this->Close();
			break;
		case Keys::Z:
			objJuego->retornar_objJugador()->disparar(categ1);
			break;
		case Keys::X:
			objJuego->retornar_objJugador()->disparar(categ2);
			break;
		case Keys::Enter:
			if (objJuego->retornar_result() == Resultado::ganar) {
				int enemEliminados = objJuego->retornar_enemEliminados();
				int puntajeFinal = objJuego->retornar_objJugador()->retornar_puntaje();
				int vidaFinal = objJuego->retornar_objJugador()->retonar_vidas();
				this->Close();
				if (dificultad == 1)
					MessageBox::Show("Felicitaciones " + nombre + ", usted ha ganado!! \n" + "Tiempo: " + tiemp_min+":"+tiemp_seg + "\nDificultad: Normal" + 
						"\nEnemigos Eliminados: " + enemEliminados + "\nPuntaje: " + puntajeFinal + "\nVida Inicial: "+ vidasJugador + "\tVida Final: " + vidaFinal, "Has ganado", MessageBoxButtons::OK, MessageBoxIcon::Information);
				else if (dificultad == 2)
					MessageBox::Show("Felicitaciones " + nombre + ", usted ha ganado!! \n" + "Tiempo: " + tiemp_min + ":" + tiemp_seg + "\nDificultad: Dificil" + 
						"\nEnemigos Eliminados: " + enemEliminados + "\nPuntaje: " + puntajeFinal + "\nVida Inicial: " + vidasJugador + "\tVida Final: " + vidaFinal, "Has ganado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else if (objJuego->retornar_result() == Resultado::perder) {
				this->Close();
				MessageBox::Show("Suerte para la siguiente oportunidad!!", "Has Perdido", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			break;
			
		}
	}
	private: System::Void soltarTecla(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		objJuego->retornar_objJugador()->direccion = Direcciones::ninguno;
	}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	tiemp_seg++;
	objJuego->cambiar_cambianTiempo(tiemp_seg, tiemp_min, tiemp_hor);
	if (tiemp_seg == 60) {
		tiemp_seg = 0;
		tiemp_min++;
		if (tiemp_min == 60) {
			tiemp_hor++;
			tiemp_min = 0;
		}
	}
	if (objJuego->retornar_result() == Resultado::ganar || objJuego->retornar_result() == Resultado::perder) {
		timer2->Stop();
	}
}
};
}
