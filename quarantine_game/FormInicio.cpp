#include "FormInicio.h"

using namespace System;
using namespace Windows::Forms;

[STAThreadAttribute]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	QuarantineGame::FormInicio form;
	Application::Run(% form);
	
	return 0;
}