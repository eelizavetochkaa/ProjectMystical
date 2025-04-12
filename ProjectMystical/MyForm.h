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
	/// ������ ��� MyForm
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
			// ��������� ���� � �� (� ����� �������)
			String^ dbPath = "test.db";

			// ���������/������� ��
			sqlite3* db;
			String^ absolutePath = Path::Combine(Environment::CurrentDirectory, "test.db");
			MessageBox::Show("���� �� �� ����:\n" + absolutePath, "�������� ����");
			int rc = sqlite3_open("test.db", &db);

			if (rc == SQLITE_OK) {
				// ������� �������
				const char* sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER, name TEXT);";
				rc = sqlite3_exec(db, sql, NULL, NULL, NULL);

				if (rc == SQLITE_OK) {
					MessageBox::Show("�� �������: " + dbPath);
				}
				else {
					MessageBox::Show("������ SQL: " + gcnew String(sqlite3_errmsg(db)));
				}
				sqlite3_close(db);
			}
			else {
				MessageBox::Show("������ �������� ��!");
			}
		}
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
