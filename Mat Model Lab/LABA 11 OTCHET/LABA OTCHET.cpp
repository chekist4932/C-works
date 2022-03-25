#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <queue> //очередь
#include <string>
using namespace std;
void array2D(int** a, int N) //заполнение двумерного массива( a - входной 2д массив, N - размерность)
{
	srand(time(0));
	for (int i = 0; i < N; i++) // ЦИкл по строкам
	{
		for (int j = 0; j < N; j++) // Цикл по столбцам
		{
			//a[i][j] = 1;
			if (rand() % 2 == 0)
			{
				a[i][j] = -1;

			}
			else
			{
				a[i][j] = 1;

			}

			std::cout << a[i][j] << "\t";
		}

		std::cout << endl;

	}
}

int E_spin(int** a, int N, int Num_spin_x, int Num_spin_y)
{
	int J = 1;

	int E = 0; // энергия спина
	// 9 вариантов

	// 1 вар
	if (Num_spin_x > 0 && Num_spin_x < N - 1 && Num_spin_y > 0 && Num_spin_y < N - 1) // центральные
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] + // сосед слева
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] + // сосед справа 
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] + // сверху
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x]); // снизу

	}
	// 2 вар
	else if (Num_spin_x == 0 && Num_spin_y == 0) // нижний левый
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][N - 1] +
			a[Num_spin_y][Num_spin_x] * a[N - 1][Num_spin_x]);
	}
	// 3 вар
	else if (Num_spin_y == N - 1 && Num_spin_x > 0 && Num_spin_x < N - 1) // верх грань
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[0][Num_spin_x]);
	}
	// 4 вар
	else if (Num_spin_x == N - 1 && Num_spin_y == N - 1) // верх право
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[0][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][0]);
	}
	// 5 вар нижняя грань
	else if (Num_spin_y == 0 && Num_spin_x > 0 && Num_spin_x < N - 1)
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[N - 1][Num_spin_x]);
	}
	// 6 вар вверх лево
	else if (Num_spin_y == N - 1 && Num_spin_x == 0)
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[0][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][N - 1]);
	}
	// 7 вар низ право
	else if (Num_spin_x == N - 1 && Num_spin_y == 0) // нижний право
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][0] +
			a[Num_spin_y][Num_spin_x] * a[N - 1][Num_spin_x]);
	}
	// 8 вар лево грань
	else if (Num_spin_x == 0 && Num_spin_y > 0 && Num_spin_y < N - 1) // лево грань
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][N - 1]);
	}
	// 9 вар право грань
	else if (Num_spin_x == N - 1 && Num_spin_y > 0 && Num_spin_y < N - 1)
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][0]);
	}
	return E;
}

int E_system(int** a, int N) // энергия системы
{
	int E_sys = 0; // хранение энергии системы
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			E_sys += E_spin(a, N, j, i);
		}
	}
	E_sys = E_sys / 2;
	return E_sys;
}
// Ф-Я ПОДСЧЕТА НАМАГНИЧЕННОСТИ СИСТЕМЫ
int M_system(int** a, int N)
{
	int M_sys = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			M_sys += a[i][j];
		}
	}
	return M_sys;
}

void perebor2D(int** a, int N)
{
	// Кол-во кофигураций
	unsigned long long N_conf = pow(2, N * N);
	// динамический массив энергий всех конф
	int* E = new int[N_conf];
	// динамический массив намагниченностт всех конф
	int* M = new int[N_conf];
	E[0] = E_system(a, N);
	M[0] = M_system(a, N);

	int E_min, E_max;
	E_max = E_system(a, N);
	E_min = E_system(a, N);



	bool flag = 0;
	for (unsigned long long conf_num = 1; conf_num < N_conf; conf_num++) // перебор конфигураций
	{
		for (int i = 0; i < N; i++) // Строки
		{
			for (int j = 0; j < N; j++) // Столбцы
			{
				if (a[i][j] == 1)
				{
					a[i][j] = -1;
					flag = 1;
					break; // Остановка цикла j		
				}
				else if (a[i][j] == -1)
				{
					a[i][j] = 1;
				}

			}
			if (flag == 1)
			{
				flag = 0;
				break;
			}
		}
		if (E_system(a, N) < E_min)
		{
			E_min = E_system(a, N);
			//save_conf1(a, N);
		}
		if (E_system(a, N) > E_max)
		{
			E_max = E_system(a, N);
			//save_conf2(a, N);
		}
		E[conf_num] = E_system(a, N);
		M[conf_num] = M_system(a, N);
	}

	// TERMODIN VEL
	ofstream f;
	
		f.open("Complete enumeration.txt");
		f << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << "\n";
	

	double Z = 0; 	// статическая сумма 
	double E_MID = 0; // Сред энерг
	double M_MID = 0; 	// сред манг
	double M2_mid = 0; // среднеее квадрата магн
	double E2_mid = 0;
	for (double T = 0.0001; T < 5.01; T += 0.1) {
		Z = 0;
		E_MID = 0;
		M_MID = 0;
		M2_mid = 0;
		E2_mid = 0;
		for (unsigned long long conf_num = 0; conf_num < N_conf; conf_num++) {
			Z = Z + exp(-((E[conf_num] - E_min) / T));
			E_MID += E[conf_num] * exp(-((E[conf_num] - E_min) / T));
			M_MID += abs(M[conf_num]) * exp(-((E[conf_num] - E_min) / T));
			M2_mid += M[conf_num] * M[conf_num] * exp(-((E[conf_num] - E_min) / T));
			E2_mid += E[conf_num] * E[conf_num] * exp(-((E[conf_num] - E_min) / T));
		}

		E_MID /= Z;
		M_MID /= Z;
		M2_mid /= Z;
		E2_mid /= Z;
		double chi; // магн вопсриимч
		chi = (M2_mid - M_MID * M_MID) / T;
		double C; // Теплоемк
		C = (E2_mid - E_MID * E_MID) / (T * T);

		// ПОСЧИТАТЬ ТЕПЛОЕМКОСТЬ

		f << T << "\t" << E_MID / (N * N) << "\t" << M_MID / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	}

	cout << "E_min = " << E_min << "\n";
	cout << "E_max = " << E_max << "\n";
	f.close();
	delete[] E;
	delete[] M;

}

void metropolis(int** a, int N)
{
	int MC_steps = 10000;
	ofstream fo;

		fo.open("Metropolis.txt");
		fo << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << "\n";
	

	ofstream file_m("m.txt");

	double E_old = 0;
	double E_new = 0;
	double E_mid = 0; // Сред энерг
	double M_mid = 0; 	// сред манг
	double M2_mid = 0; // среднеее квадрата магн
	double E2_mid = 0; // сред кв энерг

	double E = 0;
	double M = 0;

	double f;
	double r;

	int random_spin_x, random_spin_y;

	// цикл по темп
	int check = 0;
	unsigned int count = 0;
	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		E_mid = 0;
		M_mid = 0;
		E2_mid = 0;
		M2_mid = 0;
		//термолизация
		for (int step = 1; step <= 10000; step++)
		{
			for (int k = 0; k < (N * N); k++)
			{
				E_old = E_system(a, N);

				// коорд случайного спина
				random_spin_x = rand() % N;
				random_spin_y = rand() % N;

				a[random_spin_x][random_spin_y] *= -1;

				E_new = E_system(a, N);

				if (E_new > E_old)
				{
					// вероятность
					f = exp(-(E_new - E_old) / T);
					// число от 0 до 1
					r = rand() / (double)RAND_MAX;
					if (r >= f) {
						a[random_spin_x][random_spin_y] *= -1;
					}

				}
			}
			M = M_system(a, N);
			file_m << count << "\t" << M << "\n";
			count++;
		}

		// Монте-Карло шаги
		for (int step = 1; step <= MC_steps; step++)
		{ // попытки переворотов
			for (int k = 0; k < (N * N); k++)
			{
				E_old = E_system(a, N);

				// коорд случайного спина
				random_spin_x = rand() % N;
				random_spin_y = rand() % N;

				a[random_spin_x][random_spin_y] *= -1;

				E_new = E_system(a, N);

				if (E_new > E_old)
				{
					// вероятность
					f = exp(-(E_new - E_old) / T);
					// число от 0 до 1
					r = rand() / (double)RAND_MAX;
					if (r >= f)
					{
						a[random_spin_x][random_spin_y] *= -1;
					}
				}
			}

			E = E_system(a, N);
			M = M_system(a, N);

			E_mid += (E - E_mid) / step; // текущее сред
			M_mid += (abs(M) - M_mid) / step;

			M2_mid += ((M * M) - M2_mid) / step;
			E2_mid += ((E * E) - E2_mid) / step;

		}

		double chi; // магн вопсриимч
		chi = (M2_mid - (M_mid * M_mid)) / T;
		double C; // Теплоемк
		C = (E2_mid - (E_mid * E_mid)) / (T * T);
		fo << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	}
	file_m.close();
	fo.close();
}

// Ф-Я СОХР КОНФИГУР В ФАЙЛ
void save_conf(int** a, int N)
{
	ofstream file_conf("config.txt");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			file_conf << i << "\t" << j << "\t" << 0 << "\t" << a[i][j] << endl;
		}
	}
	file_conf.close();
}

void wolf(int** a, int N)
{
	//создание динамического двумерного массива для маркировки
	int** cluster_mark;
	cluster_mark = new int* [N];
	for (int i = 0; i < N; i++)
	{
		cluster_mark[i] = new int[N];
	}

	//количество Монте-Карло шагов
	int MC_steps = 10000;

	//файл для хранения термодинамических величин
	ofstream fout("Wolf.txt");
	fout << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << endl;
	double C = 0; // Теплоемк
	double chi = 0; //магнитная восприимчивость
	double E = 0; //текущая энергия системы
	double M = 0; //текущая намагниченность системы
	double E_mid = 0; //средняя энергия
	double M_mid = 0; //средняя намагниченность
	double M2_mid = 0; //среднее квадрата намагниченности
	double E2_mid = 0;
	double f; //вероятность принятия конфигурации
	double r; //случайное число от 0 до 1

	//цикл по температуре
	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		f = 1 - exp(-2 / T);

		//обнуляем средние
		E_mid = 0;
		M_mid = 0;
		M2_mid = 0;
		E2_mid = 0;

		//Термализация
		for (int step = 1; step <= 10000; step++)
		{
			//изначально вся маркировка '0'
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cluster_mark[i][j] = 0;
				}
			}

			//очередь проверки соседей
			queue <int> check;

			//координаты
			int x, y;

			//выбираем зерно роста кластера
			x = rand() % N;
			y = rand() % N;

			//добавляем элемент в очередь для проверки соседей
			check.push(x);
			check.push(y);

			//цикл проверки соседей (пока очередь не пустая)
			while (check.empty() != 1)
			{
				x = check.front(); //обращение к первому элементу в очереди
				check.pop(); //убираем из очереди первый элемент
				y = check.front();
				check.pop();

				//маркируем элементы кластера
				cluster_mark[y][x] = 1;

				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей справа
				if (x == N - 1)
				{
					if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][0] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(0);
							check.push(y);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y][x + 1] && cluster_mark[y][x + 1] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][x + 1] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x + 1);
							check.push(y);
						}
					}
				}


				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей слева
				if (x == 0)
				{
					if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][N - 1] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(N - 1);
							check.push(y);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y][x - 1] && cluster_mark[y][x - 1] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][x - 1] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x - 1);
							check.push(y);
						}
					}
				}


				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей сверху
				if (y == N - 1)
				{
					if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[0][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(0);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y + 1][x] && cluster_mark[y + 1][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y + 1][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(y + 1);
						}
					}
				}


				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей снизу
				if (y == 0)
				{
					if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[N - 1][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(N - 1);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y - 1][x] && cluster_mark[y - 1][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y - 1][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(y - 1);
						}
					}
				}
			} //заканчивается while


			int new_val;

			if (rand() % 2 == 0)
			{
				new_val = -1;
			}
			else
			{
				new_val = 1;
			}

			//перезаписываем элементы в кластере
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (cluster_mark[i][j] == 1)
					{
						a[i][j] = new_val;
					}
				}
			}

		}//заканчиваются термализация


		//Монте-Карло шаги
		for (int step = 1; step <= MC_steps; step++)
		{
			//изначально вся маркировка '0'
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cluster_mark[i][j] = 0;
				}
			}

			//очередь проверки соседей
			queue <int> check;

			//координаты
			int x, y;

			//выбираем зерно роста кластера
			x = rand() % N;
			y = rand() % N;

			//добавляем элемент в очередь для проверки соседей
			check.push(x);
			check.push(y);

			//цикл проверки соседей (пока очередь не пустая)
			while (check.empty() != 1)
			{
				x = check.front(); //обращение к первому элементу в очереди
				check.pop(); //убираем из очереди первый элемент
				y = check.front();
				check.pop();

				//маркируем элементы кластера
				cluster_mark[y][x] = 1;

				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей справа
				if (x == N - 1)
				{
					if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][0] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(0);
							check.push(y);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y][x + 1] && cluster_mark[y][x + 1] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][x + 1] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x + 1);
							check.push(y);
						}
					}
				}


				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей слева
				if (x == 0)
				{
					if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][N - 1] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(N - 1);
							check.push(y);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y][x - 1] && cluster_mark[y][x - 1] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y][x - 1] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x - 1);
							check.push(y);
						}
					}
				}


				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей сверху
				if (y == N - 1)
				{
					if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[0][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(0);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y + 1][x] && cluster_mark[y + 1][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y + 1][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(y + 1);
						}
					}
				}


				//число от 0 до 1
				r = rand() / (double)RAND_MAX;

				//проверяем соседей снизу
				if (y == 0)
				{
					if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[N - 1][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(N - 1);
						}
					}
				}
				else
				{
					if (a[y][x] == a[y - 1][x] && cluster_mark[y - 1][x] == 0)
					{
						if (r > f)
						{
							//не включаем элемент в кластер
							cluster_mark[y - 1][x] = -1;
						}
						else
						{
							//включаем элемент в кластер
							check.push(x);
							check.push(y - 1);
						}
					}
				}
			} //заканчивается while


			int new_val;

			if (rand() % 2 == 0)
			{
				new_val = -1;
			}
			else
			{
				new_val = 1;
			}

			//перезаписываем элементы в кластере
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (cluster_mark[i][j] == 1)
					{
						a[i][j] = new_val;
					}
				}
			}


			E = E_system(a, N); //энергия на текущем МК шаге
			M = M_system(a, N); //намагниченность на текущем МК шаге

			E_mid += (E - E_mid) / step; //текущее среднее энергии
			M_mid += (abs(M) - M_mid) / step;  //текущее среднее намагниченности

			M2_mid += (M * M - M2_mid) / step; //текущее среднее квадрата намагниченности
			E2_mid += ((E * E) - E2_mid) / step;
		}//заканчиваются Монте-Карло шаги

		
		chi = (M2_mid - M_mid * M_mid) / T;
		C = (E2_mid - (E_mid * E_mid)) / (T * T);
		//выводим полученные значения в файл
		fout << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << endl;

	}//заканчивается цикл по температуре

	fout.close();

	// высвобождение памяти отводимой под двумерный динамический массив:
	for (int i = 0; i < N; i++)
		delete[] cluster_mark[i];
}

void clusters_ver(int** a, int N, double f)
{
	double r = 0; //случайное число от 0 до 1

	//создание динамического двумерного массива для маркировки
	int** cluster_mark;
	cluster_mark = new int* [N];
	for (int i = 0; i < N; i++)
	{
		cluster_mark[i] = new int[N];
	}

	//изначально вся маркировка '0'
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cluster_mark[i][j] = 0;
		}
	}

	int num_cluster = 1;

	//очередь проверки соседей
	queue <int> check;

	//координаты
	int x, y;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cluster_mark[i][j] == 0)
			{
				cluster_mark[i][j] = num_cluster;

				//добавляем элемент в очередь для проверки соседей
				check.push(j);
				check.push(i);

				//цикл проверки соседей (пока очередь не пустая)
				while (check.empty() != 1)
				{
					x = check.front(); //обращение к первому элементу в очереди
					check.pop(); //убираем из очереди первый элемент
					y = check.front();
					check.pop();

					//маркируем элементы кластера
					cluster_mark[y][x] = num_cluster;


					//число от 0 до 1
					r = rand() / (double)RAND_MAX;

					//проверяем соседей справа
					if (x == N - 1)
					{
						if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[y][0] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(0);
								check.push(y);
							}
						}
					}
					else
					{
						if (a[y][x] == a[y][x + 1] && cluster_mark[y][x + 1] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[y][x + 1] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(x + 1);
								check.push(y);
							}
						}
					}


					//число от 0 до 1
					r = rand() / (double)RAND_MAX;

					//проверяем соседей слева
					if (x == 0)
					{
						if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[y][N - 1] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(N - 1);
								check.push(y);
							}
						}
					}
					else
					{
						if (a[y][x] == a[y][x - 1] && cluster_mark[y][x - 1] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[y][x - 1] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(x - 1);
								check.push(y);
							}
						}
					}


					//число от 0 до 1
					r = rand() / (double)RAND_MAX;

					//проверяем соседей сверху
					if (y == N - 1)
					{
						if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[0][x] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(x);
								check.push(0);
							}
						}
					}
					else
					{
						if (a[y][x] == a[y + 1][x] && cluster_mark[y + 1][x] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[y + 1][x] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(x);
								check.push(y + 1);
							}
						}
					}


					//число от 0 до 1
					r = rand() / (double)RAND_MAX;

					//проверяем соседей снизу
					if (y == 0)
					{
						if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[N - 1][x] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(x);
								check.push(N - 1);
							}
						}
					}
					else
					{
						if (a[y][x] == a[y - 1][x] && cluster_mark[y - 1][x] == 0)
						{
							if (r > f)
							{
								//не включаем элемент в кластер
								cluster_mark[y - 1][x] = -1;
							}
							else
							{
								//включаем элемент в кластер
								check.push(x);
								check.push(y - 1);
							}
						}
					}
				}//заканчивается цикл while
				num_cluster++;

				//меняем '-1' на '0' в маркировке
				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < N; l++)
					{
						if (cluster_mark[k][l] == -1)
						{
							cluster_mark[k][l] = 0;
						}
					}
				}
			}//заканчивается условие if
		}//цикл j
	}//цикл i


	//меняем значения в каждом кластере
	for (int z = 1; z < num_cluster; z++)
	{
		int new_val;

		if (rand() % 2 == 0)
		{
			new_val = -1;
		}
		else
		{
			new_val = 1;
		}

		//перезаписываем элементы в кластере
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cluster_mark[i][j] == z)
				{
					a[i][j] = new_val;
				}
			}
		}
	}

	// высвобождение памяти отводимой под двумерный динамический массив:
	for (int i = 0; i < N; i++)
		delete[] cluster_mark[i];
}

///lab10
void Sw(int** a, int N)
{
	//количество Монте-Карло шагов
	int MC_steps = 10000;

	//файл для хранения термодинамических величин
	ofstream fo;

	fo.open("Sw.txt");
	fo << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << "\n";
	double C = 0; // Теплоемк
	double chi = 0; //магнитная восприимчивость
	double E = 0; //текущая энергия системы
	double M = 0; //текущая намагниченность системы
	double E_mid = 0; //средняя энергия
	double M_mid = 0; //средняя намагниченность
	double M2_mid = 0; //среднее квадрата намагниченности
	double E2_mid = 0; // сред кв энерг

	double f = 0; //вероятность принятия конфигурации

	//цикл по температуре
	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		f = 1 - exp(-2 / T);

		//обнуляем средние
		E_mid = 0;
		M_mid = 0;
		M2_mid = 0;
		E2_mid = 0;

		//Термализация
		for (int step = 1; step <= 10000; step++)
		{
			clusters_ver(a, N, f);
		}//заканчивается термализация


		//Монте-Карло шаги
		for (int step = 1; step <= MC_steps; step++)
		{
			clusters_ver(a, N, f);

			E = E_system(a, N); //энергия на текущем МК шаге
			M = M_system(a, N); //намагниченность на текущем МК шаге

			E_mid += (E - E_mid) / step; //текущее среднее энергии
			M_mid += (abs(M) - M_mid) / step;  //текущее среднее намагниченности

			E2_mid += ((E * E) - E2_mid) / step;
			M2_mid += ((M * M) - M2_mid) / step; //текущее среднее квадрата намагниченности

		}//заканчиваются Монте-Карло шаги

		
		chi = (M2_mid - M_mid * M_mid) / T;

		///посчитать теплоемкость C
		
		C = (E2_mid - (E_mid * E_mid)) / (T * T);

		//выводим полученные значения в файл
		fo << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	}//заканчивается цикл по температуре

	fo.close();
}

/*
void clusters_ver(int** a, int N, double f)
{
	double r; // случайное число от 0 до 1
	//маркировка кластера

	//создание динамического двумерного массива
	int** cluster_mark;
	cluster_mark = new int* [N];
	for (int i = 0; i < N; i++)
	{
		cluster_mark[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cluster_mark[i][j] = 0;
		}
	}
	int num_cluster = 1;

	//очередь проверки соседей
	queue <int> check;

	int x, y;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			if (cluster_mark[i][j] == 0)
			{
				cluster_mark[i][j] = num_cluster;
				//добавляем элемент в очередь для проверки соседей
				check.push(j);
				check.push(i);

				//цикл проверки соседей (пока очередь не пустая)
				while (check.empty() != 1)
				{
					x = check.front(); //обращение к первому элементу в очереди
					check.pop(); //убираем из очереди первый элемент
					y = check.front();
					check.pop();

					//маркируем элементы
					cluster_mark[y][x] = num_cluster;


					r = rand() / (double)RAND_MAX;
					//проверяем соседей справа
					if (x == N - 1)
					{


						if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
						{
							if (r > f)
							{
								cluster_mark[y][0] = -1;
							}
							else
							{
								check.push(0);
								check.push(y);
							}

						}
					}
					else
					{
						if (a[y][x] == a[y][x + 1] && cluster_mark[y][x + 1] == 0)
						{
							if (r > f)
							{
								cluster_mark[y][x + 1] = -1;
							}
							else
							{
								check.push(x + 1);
								check.push(y);
							}
						}
					}
					r = rand() / (double)RAND_MAX;
					//проверяем соседей слева
					if (x == 0)
					{
						if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
						{
							if (r > f)
							{
								cluster_mark[y][N - 1] = -1;
							}
							else
							{
								check.push(N - 1);
								check.push(y);
							}

						}
					}
					else
					{
						if (a[y][x] == a[y][x - 1] && cluster_mark[y][x - 1] == 0)
						{
							if (r > f)
							{
								cluster_mark[y][x - 1] = -1;
							}
							else
							{
								check.push(x - 1);
								check.push(y);
							}
						}
					}
					r = rand() / (double)RAND_MAX;
					//проверяем соседей сверху
					if (y == N - 1)
					{
						if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
						{
							if (r > f)
							{
								cluster_mark[0][x] = -1;
							}
							else
							{
								check.push(x);
								check.push(0);
							}

						}
					}
					else
					{
						if (a[y][x] == a[y + 1][x] && cluster_mark[y + 1][x] == 0)
						{
							if (r > f)
							{
								cluster_mark[y + 1][x] = -1;
							}
							else
							{
								check.push(x);
								check.push(y + 1);
							}
						}
					}
					r = rand() / (double)RAND_MAX;
					//проверяем соседей снизу
					if (y == 0)
					{
						if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
						{
							if (r > f)
							{
								cluster_mark[N - 1][x] = -1;
							}
							else
							{
								check.push(x);
								check.push(N - 1);
							}

						}
					}
					else
					{
						if (a[y][x] == a[y - 1][x] && cluster_mark[y - 1][x] == 0)
						{
							if (r > f)
							{
								cluster_mark[y - 1][x] = -1;
							}
							else
							{
								check.push(x);
								check.push(y - 1);
							}

						}
					}

				}
				num_cluster++;
				// Меняем -1 на 0
				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < N; l++)
					{
						if (cluster_mark[k][l] == -1)
						{
							cluster_mark[k][l] = 0;
						}
					}
				}
			} // конец условия if
		} // Цикл j
	} // Цикл i

	// Меняем зн в каждом кластере
	for (int z = 1; z < num_cluster; z++)
	{
		int new_val;
		if (rand() % 2 == 0)
		{
			new_val = -1;

		}
		else
		{
			new_val = 1;

		}
		// Перезапись эл в кластере
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cluster_mark[i][j] == 1)
				{
					a[i][j] = new_val;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (cluster_mark[i][j] == z)
				{
					a[i][j] = new_val;
				}

			}
		}

	}
	//вывод на экран маркировки - cut

	// высвобождение памяти отводимой под двумерный динамический массив:
	for (int i = 0; i < N; i++)
	{
		delete[] cluster_mark[i];
	}
}

void Sw(int** a, int N)
{

	int MC_steps = 10000;
	ofstream fo;

		fo.open("Sw.txt");
		fo << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << "\n";

	

	double E_mid = 0; // Сред энерг
	double M_mid = 0; 	// сред манг
	double M2_mid = 0; // среднеее квадрата магн
	double E2_mid = 0; // сред кв энерг

	double E;
	double M;

	double f;


	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		f = 1 - exp(-2 / T);
		E_mid = 0;
		M_mid = 0;
		E2_mid = 0;
		M2_mid = 0;

		// Термолизация
		for (int step = 1; step <= 1000; step++)
		{
			clusters_ver(a, N, f);
		} // Конец термолизации

		// Монте-Карло шаги
		for (int step = 1; step <= MC_steps; step++)
		{

			clusters_ver(a, N, f);

			E = E_system(a, N);
			M = M_system(a, N);

			E_mid += (E - E_mid) / step; // текущее сред
			M_mid += (abs(M) - M_mid) / step;

			M2_mid += ((M * M) - M2_mid) / step;
			E2_mid += ((E * E) - E2_mid) / step;

		} // Конец Монте-Карло шагов

		double chi; // магн вопсриимч
		chi = (M2_mid - (M_mid * M_mid)) / T;
		double C; // Теплоемк
		C = (E2_mid - (E_mid * E_mid)) / (T * T);
		fo << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	} // Конец цикла по темп
	fo.close();
}
*/

void menu(int** a, int N)
{
	cout << "\n>>\t" << "Sistem size = "  << N << "x" << N << "\n";
	int p;
	cout << "\nSelect the algorithm:\n\n" << "1. Complete enumeratoin\n" << "2. Metropolis\n" << "3. Wolf\n" << "4. Swedsen-Wang\n" << "5. All algorithms and exit\n" << "6. Exit\n" << ">>\t";
	
	cin >> p;

	switch (p)
	{
	case 1:
		cout << "\t>>\tComplete enumeratoin Started\n";
		perebor2D(a, N);
		cout << "\t>>\tComplete enumeratoin Finished" << "\n";
		menu(a, N);
		break;
	case 2:
		cout << "\t>>\tMetropolis Started\n";
		metropolis(a, N);
		cout << "\t>>\tMetropolis Finished\n";
		menu(a, N);
		break;
	case 3:
		cout << "\t>>\tWolf Started\n";
		wolf(a, N);
		cout << "\t>>\tWolf Finished\n";
		menu(a, N);
		break;
	case 4:
		cout << "\t>>\tSwendsen-Wang Started\n";
		Sw(a, N);
		cout << "\t>>\tSwendsen-Wang Finished\n";
		menu(a, N);
		break;
	case 5:
		cout << "\t>>\tAll algorithms and Exit\n";
		cout << "\t>>\tComplete enumeration Started\n";
		perebor2D(a, N);
		cout << "\t>>\tComplete enumeration Finished\n";
		cout << "\t>>\tMetropolis Started\n";
		metropolis(a, N);
		cout << "\t>>\tMetropolis Finished\n";
		cout << "\t>>\tWolf Started\n";
		wolf(a, N);
		cout << "\t>>\tWolf Finished\n";
		Sw(a, N);
		cout << "\t>>\tAll Finished\t>>\tExit\n";
		break;
	case 6:
		cout << "\t>>\tExit\n";
		break;
	
	default:
		cout << "\t>>\tincorrect number\n";
		menu(a, N);
		break;
	}
}

int main()
{
	srand(time(0));
	for (int N = 5; N < 6; ++N)
	{
		// Создание динамичесокго двумерного массива
		int** b;
		b = new int* [N];
		for (int i = 0; i < N; i++)
		{
			b[i] = new int[N];
		}
		array2D(b, N);
		int x, y;
		x = rand() % N;
		y = rand() % N;
		
		
		menu(b, N);
		
		
		for (int i = 0; i < N; i++)
		{
			delete[] b[i];
		}
	}

	return 0;
}
