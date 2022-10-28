#include "VentanaPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args){
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   ProjectForms::MyForm form;
   Application::Run(% form);
}