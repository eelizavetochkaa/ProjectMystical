#pragma once
#include <windows.h>
#include "../sqlite/sqlite3.h" 

namespace ProjectMystical {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class MyForm : public Form {
    public:
        MyForm(void);

    private:
        void InitializeComponent();
        void InitializeDatabase(); 
    };
}