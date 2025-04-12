#pragma once
#include "sqlite3.h"

namespace ProjectMystical {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			TestSQLite();
		}
	private:
		void TestSQLite() {
			// Указываем путь к БД (в папке проекта)
			String^ dbPath = "test.db";

			// Открываем/создаем БД
			sqlite3* db;
			String^ absolutePath = Path::Combine(Environment::CurrentDirectory, "test.db");
			MessageBox::Show("Ищем БД по пути:\n" + absolutePath, "Проверка пути");
			int rc = sqlite3_open("test.db", &db);

			if (rc == SQLITE_OK) {
				// Создаем таблицу
				const char* sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER, name TEXT);";
				rc = sqlite3_exec(db, sql, NULL, NULL, NULL);

				if (rc == SQLITE_OK) {
					MessageBox::Show("БД создана: " + dbPath);
				}
				else {
					MessageBox::Show("Ошибка SQL: " + gcnew String(sqlite3_errmsg(db)));
				}
				sqlite3_close(db);
			}
			else {
				MessageBox::Show("Ошибка открытия БД!");
			}
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
