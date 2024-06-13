#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <random>

#include <iostream>
#include <locale>
#include <windows.h>

#define N 50     // Длительность сигнала в шагах дискретизации
#define M 20    // Размер массивов для подсчета вероятности ложной тревоги
#define MM 15  // Размер массива для подсчета вероятности правильного обнаружения


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
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 349);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//help
		SetConsoleOutputCP(65001);
		// Массивы сигнала, импульсной характеристики и их смеси
		array<double>^ x = gcnew array<double>(N);
		array<double>^ k = gcnew array<double>(N);
		array<double>^ s = gcnew array<double>(N);

		float porog;// Значение порога обнаружения для вычисления вероятности правильного обнаружения
		float sym;
		array<double>^ mass_porog = gcnew array<double>(M);// Массив порогов
		array<double>^ veroa = gcnew array<double>(M);// Массив для вероятностей ложной тревоги
		array<double>^ d_prav = gcnew array<double>(MM);// Массив для вероятностей правильного обнаружения

		int i, j, n;
		long nn;
		float disp;// Оценка дисперсии шума на выходе системы
		float z, A;

		// Формирование полезного сигнала
		for (i = 0; i < N; i++) {
			s[i] = cos(2. * M_PI * i / N);
		}

		// Формирование импульсной характеристики согласованного фильтра
		for (i = 0; i < N; i++) {
			k[i] = s[N - 1 - i];
		}


		// Оценка дисперсии шума на выходе системы
		disp = 0;
		for (i = 0; i < 200; i++) {   // Цикл по 200 экспериментам
			for (j = 0; j < N; j++) {
				x[j] = gauss(0, 1);
			}
			z = sogl(x, k);
			disp = disp + z * z;
		}
		disp = disp / 200.;


		// Формирование массива порогов
		for (i = 0; i < M; i++) {
			mass_porog[i] = sqrt(disp) * (1.0 + 0.1 * i);
		}

		// Вычисление зависимости вероятности ложной тревоги от порога обнаружения
		for (nn = 0; nn < 30000L; nn++) {
			for (j = 0; j < N; j++) {
				x[j] = gauss(0, 1);
			}
			z = sogl(x, k);
			for (j = 0; j < M; j++) {
				if (z >= mass_porog[j]) {
					veroa[j]++;
				}
			}
		}
		for (j = 0; j < M; j++) {
			veroa[j] = veroa[j] / 30000.;
		}

		// Вывод порогов обнаружения и соответствующих им вероятностей ложных тревог
		for (i = 0; i < M; i++) {
			printf("\n порог обнаружения = %f\tвероятность ложной тревоги = %f ", mass_porog[i], veroa[i]);
		}

		// Ввод порога для вычисления зависимости вероятности правильного обнаружения от амплитуды сигнала
		printf("\n  Ввод порога обнаружения: ");
		scanf_s("%f", &porog);

		// Вычисление зависимости вероятности правильного обнаружения от амплитуды сигнала
		for (n = 0; n < MM; n++) {
			A = 0.2 + 0.05 * n;           // Амплитуда входного сигнала
			for (j = 0; j < 200; j++) {   // Цикл по 200 экспериментам
				for (i = 0; i < N; i++) {
					x[i] = gauss(0, 1) + A * s[i];
				}
				z = sogl(x, k);
				if (z >= porog) {
					d_prav[n] = d_prav[n] + 1. / 200.;
				}
			}
			printf("\n Амплитуда  = %f\tВероятность правильного обнаружения %f", A, d_prav[n]);
		}
	}

		   float sogl(array<double>^ x, array<double>^ k) {
			   int i;
			   float sym;
			   sym = 0;
			   for (i = 0; i < N; i++) {
				   sym = sym + x[i] * k[N - 1 - i];
			   }
			   return sym;
		   }


		   double gauss(double mean, double stddev)
		   {//Box muller method
			   static double n2 = 0.0;
			   static int n2_cached = 0;
			   if (!n2_cached)
			   {
				   double x, y, r;
				   do
				   {
					   x = 2.0 * rand() / RAND_MAX - 1;
					   y = 2.0 * rand() / RAND_MAX - 1;

					   r = x * x + y * y;
				   } while (r == 0.0 || r > 1.0);
				   {
					   double d = sqrt(-2.0 * log(r) / r);
					   double n1 = x * d;
					   n2 = y * d;
					   double result = n1 * stddev + mean;
					   n2_cached = 1;
					   return result;
				   }
			   }
			   else
			   {
				   n2_cached = 0;
				   return n2 * stddev + mean;
			   }
		   }
	};
}
