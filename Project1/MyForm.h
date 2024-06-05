#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define N 3000 // Число отрезков для вычисления плотности распределения вероятности 
#define M 100000L // Число экспериментов
//float sl_vel(float a, float b);


namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(29, 34);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(575, 287);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(58, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(610, 34);
			this->chart2->Name = L"chart2";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart2->Series->Add(series2);
			this->chart2->Size = System::Drawing::Size(575, 287);
			this->chart2->TabIndex = 3;
			this->chart2->Text = L"chart2";
			this->chart2->Click += gcnew System::EventHandler(this, &MyForm::chart2_Click);
			// 
			// chart3
			// 
			chartArea3->Name = L"ChartArea1";
			this->chart3->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart3->Legends->Add(legend3);
			this->chart3->Location = System::Drawing::Point(610, 340);
			this->chart3->Name = L"chart3";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chart3->Series->Add(series3);
			this->chart3->Size = System::Drawing::Size(575, 287);
			this->chart3->TabIndex = 5;
			this->chart3->Text = L"chart3";
			// 
			// chart4
			// 
			chartArea4->Name = L"ChartArea1";
			this->chart4->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chart4->Legends->Add(legend4);
			this->chart4->Location = System::Drawing::Point(29, 340);
			this->chart4->Name = L"chart4";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->chart4->Series->Add(series4);
			this->chart4->Size = System::Drawing::Size(575, 287);
			this->chart4->TabIndex = 4;
			this->chart4->Text = L"chart4";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(26, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Y(n)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 324);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"X(n)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1202, 642);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart3);
			this->Controls->Add(this->chart4);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//help
		double D = 5, a = 0.1;
		array<double>^ x = gcnew array<double>(N);
		array<double>^ y = gcnew array<double>(N);
		array<double>^ y1 = gcnew array<double>(N);
		array<double>^ y2 = gcnew array<double>(N);
		array<double>^ y3 = gcnew array<double>(N);
		array<double>^ ex = gcnew array<double>(N);
		array<double>^ r = gcnew array<double>(500); // массив для оценки корреляционной функции
		int N_realiz;// длительность реализации стационарного 
                     // фрагмента получившегося случайного процесса
		/*___*/
		array<double>^ c = gcnew array<double>(500);
		double aa;
		int n, P, m, k;
		y1 = randomis();
		y2 = zapazd(y1, 1);
		y3 = zapazd(y1, 2);
		
		for (int n = 0; n < N; n++)
		{
			y[n] = 2 * y1[n] - 3 * y2[n] + 6 * y3[3];
		}

		P = 2. / a;
		N_realiz = N - 2 * P;
			for (m = 0; m < 500; m++)
			{
				r[m] = 0.0;
				for (n = 0; n < (N_realiz - m - 1); n++)
					r[m] = r[m] + 1. / (N_realiz - m) * y[n] * y[n + m];
				chart2->Series[0]->Points->AddXY(m, r[m]);
			}

			for (m = 0; m < 500; m++)
			{
				r[m] = 0.0;
				for (n = 0; n < (N_realiz - m - 1); n++)
					r[m] = r[m] + 1. / (N_realiz - m) * y1[n] * y1[n + m];
				chart3->Series[0]->Points->AddXY(m, r[m]);
			}

		// Plot the probability density
		for (int n = 0; n < N; n++) {
			chart1->Series[0]->Points->AddXY(n, y[n]);
			
		}

		for (int n = 0; n < N; n++) {
			chart4->Series[0]->Points->AddXY(n, y1[n]);

		}
	}
		   array<double>^ zapazd(array<double>^ y1, int zapaz) //запаздывание
		   {
			   array<double>^ y2 = gcnew array<double>(N);

			   for (int n = 0; n < zapaz; n++) { y2[n] = 0; }

			   for (int n = zapaz; n < N; n++)
			   {
				   y2[n] = y1[n - zapaz];
			   }
			   return y2;

		   }
		   float gauss(float mu, float sigma) {
			   static float spare;
			   static bool hasSpare = false;

			   float ran;

			   if (hasSpare) {
				   hasSpare = false;
				   return spare * sigma + mu;
			   }

			   float u, v, s;
			   do {
				   u = 2.0 * (float)rand() / RAND_MAX - 1.0;
				   v = 2.0 * (float)rand() / RAND_MAX - 1.0;
				   s = u * u + v * v;
			   } while (s >= 1.0 || s == 0.0);

			   float fac = sqrt(-2.0 * log(s) / s);
			   spare = v * fac;
			   hasSpare = true;
			   ran = u * fac;

			   return ran * sigma + mu;
		   }

		   array<double>^ randomis() {
			   double D = 5, a = 0.1;
			   array<double>^ x = gcnew array<double>(N);
			   array<double>^ y = gcnew array<double>(N);
			   array<double>^ ex = gcnew array<double>(N);
			   array<double>^ r = gcnew array<double>(500); // массив для оценки корреляционной функции
			   int N_realiz;// длительность реализации стационарного 
			   // фрагмента получившегося случайного процесса
  /*___*/
			   array<double>^ c = gcnew array<double>(500);
			   double aa;
			   double rand;
			   int n, P, m, k;
			   for (n = 0; n < N; n++) {
				   ex[n] = gauss(0, 1);
			   }
			   P = 2. / a;
			   for (k = 0; k <= P; k++)
			   {
				   if (k != 0)
					   c[k] = sqrt(D) / sqrt(M_PI * a) * sin(a * k) / k;
				   else c[k] = sqrt(D) / sqrt(M_PI * a) * a;
			   }
			   for (n = 0; n < N; n++)
			   {
				   x[n] = 0.0;
				   for (k = -P; k <= P; k++)
				   {
					   if (k < 0) aa = c[-k];
					   else aa = c[k];

					   if (((n - k) >= 0) && ((n - k) < N))
						   x[n] = aa * ex[n - k] + x[n];
				   }

			   }
			   for (n = 0; n < (N - 2 * P); n++)
				   x[n] = x[n + P];
			   N_realiz = N - 2 * P;
			   return x;
			   
		   }
	private: System::Void chart2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
