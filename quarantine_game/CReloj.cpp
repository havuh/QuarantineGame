#include "CReloj.h"

CReloj::CReloj() {
	seg = min = hor = 0;
}
CReloj::~CReloj(){}
int CReloj::retornar_seg() { return seg; }
int CReloj::retornar_min() { return min; }
int CReloj::retornar_hor() { return hor; }
void CReloj::iniciar_reloj(int segundos, int minutos, int horas) {
	seg = segundos;
	min = minutos;
	hor = horas;
}
bool CReloj::seTerminoJuego(int JuegMin, int JuegSeg) {
	if (JuegMin == min) {
		if (JuegSeg == seg) {
			return true;
		}
		else false;
	}
	else false;
}
void CReloj::dibujar_reloj(BufferedGraphics^ buffer, int _tiempo) {
	int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;

	if (seg >= 0) {
		System::String^ s;
		System::String^ m;
		if (60 - seg >= 10) {
			s = System::String::Format("{0}:", 60 - seg);
		}
		else {
			s = System::String::Format("0{0}:", 60 - seg);
		}
		if (_tiempo > 10 )
			m = System::String::Format("{0}", (_tiempo - 1) - min);
		else
			m = System::String::Format("0{0}", (_tiempo - 1) - min);

		if (min == _tiempo) {
			s = "00:";
			m = "00";
		}
		System::String^ texto = "T I M E";
		Font^ font = gcnew Font("Arial Black", 20);
		Font^ font2 = gcnew Font("Arial Black", 30);
		float y = 40, x = MAX_W / 2 + 60;
		SolidBrush^ solidBrush = gcnew SolidBrush(Color::Yellow);
		SolidBrush^ solidBrush2 = gcnew SolidBrush(Color::White);

		SolidBrush^ rectangulo = gcnew SolidBrush(Color::Black);
		Rectangle forma = Rectangle(x - 165, y - 15, 200, 100);
		Rectangle forma2 = Rectangle(x - 160, y - 10, 190, 90);

		StringFormat^ format = gcnew StringFormat();
		format->FormatFlags = StringFormatFlags::DirectionRightToLeft;
		buffer->Graphics->FillRectangle(rectangulo, forma);
		buffer->Graphics->DrawRectangle(Pens::Yellow, forma2);
		buffer->Graphics->DrawString(texto, font, solidBrush2, x - 10, y, format);
		buffer->Graphics->DrawString(m, font2, solidBrush, x - 60, y + 20, format);
		buffer->Graphics->DrawString(s, font2, solidBrush, x + 5, y + 20, format);
	}
	
}