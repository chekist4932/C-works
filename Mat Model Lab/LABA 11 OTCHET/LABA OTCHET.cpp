#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <queue> //�������
#include <string>
using namespace std;
void array2D(int** a, int N) //���������� ���������� �������( a - ������� 2� ������, N - �����������)
{
	srand(time(0));
	for (int i = 0; i < N; i++) // ���� �� �������
	{
		for (int j = 0; j < N; j++) // ���� �� ��������
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

	int E = 0; // ������� �����
	// 9 ���������

	// 1 ���
	if (Num_spin_x > 0 && Num_spin_x < N - 1 && Num_spin_y > 0 && Num_spin_y < N - 1) // �����������
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] + // ����� �����
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] + // ����� ������ 
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] + // ������
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x]); // �����

	}
	// 2 ���
	else if (Num_spin_x == 0 && Num_spin_y == 0) // ������ �����
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][N - 1] +
			a[Num_spin_y][Num_spin_x] * a[N - 1][Num_spin_x]);
	}
	// 3 ���
	else if (Num_spin_y == N - 1 && Num_spin_x > 0 && Num_spin_x < N - 1) // ���� �����
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[0][Num_spin_x]);
	}
	// 4 ���
	else if (Num_spin_x == N - 1 && Num_spin_y == N - 1) // ���� �����
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[0][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][0]);
	}
	// 5 ��� ������ �����
	else if (Num_spin_y == 0 && Num_spin_x > 0 && Num_spin_x < N - 1)
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[N - 1][Num_spin_x]);
	}
	// 6 ��� ����� ����
	else if (Num_spin_y == N - 1 && Num_spin_x == 0)
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[0][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][N - 1]);
	}
	// 7 ��� ��� �����
	else if (Num_spin_x == N - 1 && Num_spin_y == 0) // ������ �����
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][0] +
			a[Num_spin_y][Num_spin_x] * a[N - 1][Num_spin_x]);
	}
	// 8 ��� ���� �����
	else if (Num_spin_x == 0 && Num_spin_y > 0 && Num_spin_y < N - 1) // ���� �����
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x + 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][N - 1]);
	}
	// 9 ��� ����� �����
	else if (Num_spin_x == N - 1 && Num_spin_y > 0 && Num_spin_y < N - 1)
	{
		E = -J * (a[Num_spin_y][Num_spin_x] * a[Num_spin_y + 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][Num_spin_x - 1] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y - 1][Num_spin_x] +
			a[Num_spin_y][Num_spin_x] * a[Num_spin_y][0]);
	}
	return E;
}

int E_system(int** a, int N) // ������� �������
{
	int E_sys = 0; // �������� ������� �������
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
// �-� �������� ��������������� �������
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
	// ���-�� �����������
	unsigned long long N_conf = pow(2, N * N);
	// ������������ ������ ������� ���� ����
	int* E = new int[N_conf];
	// ������������ ������ ��������������� ���� ����
	int* M = new int[N_conf];
	E[0] = E_system(a, N);
	M[0] = M_system(a, N);

	int E_min, E_max;
	E_max = E_system(a, N);
	E_min = E_system(a, N);



	bool flag = 0;
	for (unsigned long long conf_num = 1; conf_num < N_conf; conf_num++) // ������� ������������
	{
		for (int i = 0; i < N; i++) // ������
		{
			for (int j = 0; j < N; j++) // �������
			{
				if (a[i][j] == 1)
				{
					a[i][j] = -1;
					flag = 1;
					break; // ��������� ����� j		
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
	

	double Z = 0; 	// ����������� ����� 
	double E_MID = 0; // ���� �����
	double M_MID = 0; 	// ���� ����
	double M2_mid = 0; // �������� �������� ����
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
		double chi; // ���� ���������
		chi = (M2_mid - M_MID * M_MID) / T;
		double C; // ��������
		C = (E2_mid - E_MID * E_MID) / (T * T);

		// ��������� ������������

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
	double E_mid = 0; // ���� �����
	double M_mid = 0; 	// ���� ����
	double M2_mid = 0; // �������� �������� ����
	double E2_mid = 0; // ���� �� �����

	double E = 0;
	double M = 0;

	double f;
	double r;

	int random_spin_x, random_spin_y;

	// ���� �� ����
	int check = 0;
	unsigned int count = 0;
	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		E_mid = 0;
		M_mid = 0;
		E2_mid = 0;
		M2_mid = 0;
		//������������
		for (int step = 1; step <= 10000; step++)
		{
			for (int k = 0; k < (N * N); k++)
			{
				E_old = E_system(a, N);

				// ����� ���������� �����
				random_spin_x = rand() % N;
				random_spin_y = rand() % N;

				a[random_spin_x][random_spin_y] *= -1;

				E_new = E_system(a, N);

				if (E_new > E_old)
				{
					// �����������
					f = exp(-(E_new - E_old) / T);
					// ����� �� 0 �� 1
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

		// �����-����� ����
		for (int step = 1; step <= MC_steps; step++)
		{ // ������� �����������
			for (int k = 0; k < (N * N); k++)
			{
				E_old = E_system(a, N);

				// ����� ���������� �����
				random_spin_x = rand() % N;
				random_spin_y = rand() % N;

				a[random_spin_x][random_spin_y] *= -1;

				E_new = E_system(a, N);

				if (E_new > E_old)
				{
					// �����������
					f = exp(-(E_new - E_old) / T);
					// ����� �� 0 �� 1
					r = rand() / (double)RAND_MAX;
					if (r >= f)
					{
						a[random_spin_x][random_spin_y] *= -1;
					}
				}
			}

			E = E_system(a, N);
			M = M_system(a, N);

			E_mid += (E - E_mid) / step; // ������� ����
			M_mid += (abs(M) - M_mid) / step;

			M2_mid += ((M * M) - M2_mid) / step;
			E2_mid += ((E * E) - E2_mid) / step;

		}

		double chi; // ���� ���������
		chi = (M2_mid - (M_mid * M_mid)) / T;
		double C; // ��������
		C = (E2_mid - (E_mid * E_mid)) / (T * T);
		fo << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	}
	file_m.close();
	fo.close();
}

// �-� ���� �������� � ����
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
	//�������� ������������� ���������� ������� ��� ����������
	int** cluster_mark;
	cluster_mark = new int* [N];
	for (int i = 0; i < N; i++)
	{
		cluster_mark[i] = new int[N];
	}

	//���������� �����-����� �����
	int MC_steps = 10000;

	//���� ��� �������� ����������������� �������
	ofstream fout("Wolf.txt");
	fout << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << endl;
	double C = 0; // ��������
	double chi = 0; //��������� ���������������
	double E = 0; //������� ������� �������
	double M = 0; //������� ��������������� �������
	double E_mid = 0; //������� �������
	double M_mid = 0; //������� ���������������
	double M2_mid = 0; //������� �������� ���������������
	double E2_mid = 0;
	double f; //����������� �������� ������������
	double r; //��������� ����� �� 0 �� 1

	//���� �� �����������
	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		f = 1 - exp(-2 / T);

		//�������� �������
		E_mid = 0;
		M_mid = 0;
		M2_mid = 0;
		E2_mid = 0;

		//������������
		for (int step = 1; step <= 10000; step++)
		{
			//���������� ��� ���������� '0'
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cluster_mark[i][j] = 0;
				}
			}

			//������� �������� �������
			queue <int> check;

			//����������
			int x, y;

			//�������� ����� ����� ��������
			x = rand() % N;
			y = rand() % N;

			//��������� ������� � ������� ��� �������� �������
			check.push(x);
			check.push(y);

			//���� �������� ������� (���� ������� �� ������)
			while (check.empty() != 1)
			{
				x = check.front(); //��������� � ������� �������� � �������
				check.pop(); //������� �� ������� ������ �������
				y = check.front();
				check.pop();

				//��������� �������� ��������
				cluster_mark[y][x] = 1;

				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� ������
				if (x == N - 1)
				{
					if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[y][0] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y][x + 1] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x + 1);
							check.push(y);
						}
					}
				}


				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� �����
				if (x == 0)
				{
					if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[y][N - 1] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y][x - 1] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x - 1);
							check.push(y);
						}
					}
				}


				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� ������
				if (y == N - 1)
				{
					if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[0][x] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y + 1][x] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x);
							check.push(y + 1);
						}
					}
				}


				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� �����
				if (y == 0)
				{
					if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[N - 1][x] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y - 1][x] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x);
							check.push(y - 1);
						}
					}
				}
			} //������������� while


			int new_val;

			if (rand() % 2 == 0)
			{
				new_val = -1;
			}
			else
			{
				new_val = 1;
			}

			//�������������� �������� � ��������
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

		}//������������� ������������


		//�����-����� ����
		for (int step = 1; step <= MC_steps; step++)
		{
			//���������� ��� ���������� '0'
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cluster_mark[i][j] = 0;
				}
			}

			//������� �������� �������
			queue <int> check;

			//����������
			int x, y;

			//�������� ����� ����� ��������
			x = rand() % N;
			y = rand() % N;

			//��������� ������� � ������� ��� �������� �������
			check.push(x);
			check.push(y);

			//���� �������� ������� (���� ������� �� ������)
			while (check.empty() != 1)
			{
				x = check.front(); //��������� � ������� �������� � �������
				check.pop(); //������� �� ������� ������ �������
				y = check.front();
				check.pop();

				//��������� �������� ��������
				cluster_mark[y][x] = 1;

				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� ������
				if (x == N - 1)
				{
					if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[y][0] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y][x + 1] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x + 1);
							check.push(y);
						}
					}
				}


				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� �����
				if (x == 0)
				{
					if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[y][N - 1] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y][x - 1] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x - 1);
							check.push(y);
						}
					}
				}


				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� ������
				if (y == N - 1)
				{
					if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[0][x] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y + 1][x] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x);
							check.push(y + 1);
						}
					}
				}


				//����� �� 0 �� 1
				r = rand() / (double)RAND_MAX;

				//��������� ������� �����
				if (y == 0)
				{
					if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
					{
						if (r > f)
						{
							//�� �������� ������� � �������
							cluster_mark[N - 1][x] = -1;
						}
						else
						{
							//�������� ������� � �������
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
							//�� �������� ������� � �������
							cluster_mark[y - 1][x] = -1;
						}
						else
						{
							//�������� ������� � �������
							check.push(x);
							check.push(y - 1);
						}
					}
				}
			} //������������� while


			int new_val;

			if (rand() % 2 == 0)
			{
				new_val = -1;
			}
			else
			{
				new_val = 1;
			}

			//�������������� �������� � ��������
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


			E = E_system(a, N); //������� �� ������� �� ����
			M = M_system(a, N); //��������������� �� ������� �� ����

			E_mid += (E - E_mid) / step; //������� ������� �������
			M_mid += (abs(M) - M_mid) / step;  //������� ������� ���������������

			M2_mid += (M * M - M2_mid) / step; //������� ������� �������� ���������������
			E2_mid += ((E * E) - E2_mid) / step;
		}//������������� �����-����� ����

		
		chi = (M2_mid - M_mid * M_mid) / T;
		C = (E2_mid - (E_mid * E_mid)) / (T * T);
		//������� ���������� �������� � ����
		fout << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << endl;

	}//������������� ���� �� �����������

	fout.close();

	// ������������� ������ ��������� ��� ��������� ������������ ������:
	for (int i = 0; i < N; i++)
		delete[] cluster_mark[i];
}

void clusters_ver(int** a, int N, double f)
{
	double r = 0; //��������� ����� �� 0 �� 1

	//�������� ������������� ���������� ������� ��� ����������
	int** cluster_mark;
	cluster_mark = new int* [N];
	for (int i = 0; i < N; i++)
	{
		cluster_mark[i] = new int[N];
	}

	//���������� ��� ���������� '0'
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cluster_mark[i][j] = 0;
		}
	}

	int num_cluster = 1;

	//������� �������� �������
	queue <int> check;

	//����������
	int x, y;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (cluster_mark[i][j] == 0)
			{
				cluster_mark[i][j] = num_cluster;

				//��������� ������� � ������� ��� �������� �������
				check.push(j);
				check.push(i);

				//���� �������� ������� (���� ������� �� ������)
				while (check.empty() != 1)
				{
					x = check.front(); //��������� � ������� �������� � �������
					check.pop(); //������� �� ������� ������ �������
					y = check.front();
					check.pop();

					//��������� �������� ��������
					cluster_mark[y][x] = num_cluster;


					//����� �� 0 �� 1
					r = rand() / (double)RAND_MAX;

					//��������� ������� ������
					if (x == N - 1)
					{
						if (a[y][x] == a[y][0] && cluster_mark[y][0] == 0)
						{
							if (r > f)
							{
								//�� �������� ������� � �������
								cluster_mark[y][0] = -1;
							}
							else
							{
								//�������� ������� � �������
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
								//�� �������� ������� � �������
								cluster_mark[y][x + 1] = -1;
							}
							else
							{
								//�������� ������� � �������
								check.push(x + 1);
								check.push(y);
							}
						}
					}


					//����� �� 0 �� 1
					r = rand() / (double)RAND_MAX;

					//��������� ������� �����
					if (x == 0)
					{
						if (a[y][x] == a[y][N - 1] && cluster_mark[y][N - 1] == 0)
						{
							if (r > f)
							{
								//�� �������� ������� � �������
								cluster_mark[y][N - 1] = -1;
							}
							else
							{
								//�������� ������� � �������
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
								//�� �������� ������� � �������
								cluster_mark[y][x - 1] = -1;
							}
							else
							{
								//�������� ������� � �������
								check.push(x - 1);
								check.push(y);
							}
						}
					}


					//����� �� 0 �� 1
					r = rand() / (double)RAND_MAX;

					//��������� ������� ������
					if (y == N - 1)
					{
						if (a[y][x] == a[0][x] && cluster_mark[0][x] == 0)
						{
							if (r > f)
							{
								//�� �������� ������� � �������
								cluster_mark[0][x] = -1;
							}
							else
							{
								//�������� ������� � �������
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
								//�� �������� ������� � �������
								cluster_mark[y + 1][x] = -1;
							}
							else
							{
								//�������� ������� � �������
								check.push(x);
								check.push(y + 1);
							}
						}
					}


					//����� �� 0 �� 1
					r = rand() / (double)RAND_MAX;

					//��������� ������� �����
					if (y == 0)
					{
						if (a[y][x] == a[N - 1][x] && cluster_mark[N - 1][x] == 0)
						{
							if (r > f)
							{
								//�� �������� ������� � �������
								cluster_mark[N - 1][x] = -1;
							}
							else
							{
								//�������� ������� � �������
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
								//�� �������� ������� � �������
								cluster_mark[y - 1][x] = -1;
							}
							else
							{
								//�������� ������� � �������
								check.push(x);
								check.push(y - 1);
							}
						}
					}
				}//������������� ���� while
				num_cluster++;

				//������ '-1' �� '0' � ����������
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
			}//������������� ������� if
		}//���� j
	}//���� i


	//������ �������� � ������ ��������
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

		//�������������� �������� � ��������
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

	// ������������� ������ ��������� ��� ��������� ������������ ������:
	for (int i = 0; i < N; i++)
		delete[] cluster_mark[i];
}

///lab10
void Sw(int** a, int N)
{
	//���������� �����-����� �����
	int MC_steps = 10000;

	//���� ��� �������� ����������������� �������
	ofstream fo;

	fo.open("Sw.txt");
	fo << "#T" << "\t" << "<E>/N" << "\t" << "<M>/N" << "\t" << "chi/N" << "\t" << "C/N" << "\n";
	double C = 0; // ��������
	double chi = 0; //��������� ���������������
	double E = 0; //������� ������� �������
	double M = 0; //������� ��������������� �������
	double E_mid = 0; //������� �������
	double M_mid = 0; //������� ���������������
	double M2_mid = 0; //������� �������� ���������������
	double E2_mid = 0; // ���� �� �����

	double f = 0; //����������� �������� ������������

	//���� �� �����������
	for (double T = 0.0001; T < 5.01; T += 0.01)
	{
		f = 1 - exp(-2 / T);

		//�������� �������
		E_mid = 0;
		M_mid = 0;
		M2_mid = 0;
		E2_mid = 0;

		//������������
		for (int step = 1; step <= 10000; step++)
		{
			clusters_ver(a, N, f);
		}//������������� ������������


		//�����-����� ����
		for (int step = 1; step <= MC_steps; step++)
		{
			clusters_ver(a, N, f);

			E = E_system(a, N); //������� �� ������� �� ����
			M = M_system(a, N); //��������������� �� ������� �� ����

			E_mid += (E - E_mid) / step; //������� ������� �������
			M_mid += (abs(M) - M_mid) / step;  //������� ������� ���������������

			E2_mid += ((E * E) - E2_mid) / step;
			M2_mid += ((M * M) - M2_mid) / step; //������� ������� �������� ���������������

		}//������������� �����-����� ����

		
		chi = (M2_mid - M_mid * M_mid) / T;

		///��������� ������������ C
		
		C = (E2_mid - (E_mid * E_mid)) / (T * T);

		//������� ���������� �������� � ����
		fo << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	}//������������� ���� �� �����������

	fo.close();
}

/*
void clusters_ver(int** a, int N, double f)
{
	double r; // ��������� ����� �� 0 �� 1
	//���������� ��������

	//�������� ������������� ���������� �������
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

	//������� �������� �������
	queue <int> check;

	int x, y;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			if (cluster_mark[i][j] == 0)
			{
				cluster_mark[i][j] = num_cluster;
				//��������� ������� � ������� ��� �������� �������
				check.push(j);
				check.push(i);

				//���� �������� ������� (���� ������� �� ������)
				while (check.empty() != 1)
				{
					x = check.front(); //��������� � ������� �������� � �������
					check.pop(); //������� �� ������� ������ �������
					y = check.front();
					check.pop();

					//��������� ��������
					cluster_mark[y][x] = num_cluster;


					r = rand() / (double)RAND_MAX;
					//��������� ������� ������
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
					//��������� ������� �����
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
					//��������� ������� ������
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
					//��������� ������� �����
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
				// ������ -1 �� 0
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
			} // ����� ������� if
		} // ���� j
	} // ���� i

	// ������ �� � ������ ��������
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
		// ���������� �� � ��������
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
	//����� �� ����� ���������� - cut

	// ������������� ������ ��������� ��� ��������� ������������ ������:
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

	

	double E_mid = 0; // ���� �����
	double M_mid = 0; 	// ���� ����
	double M2_mid = 0; // �������� �������� ����
	double E2_mid = 0; // ���� �� �����

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

		// ������������
		for (int step = 1; step <= 1000; step++)
		{
			clusters_ver(a, N, f);
		} // ����� ������������

		// �����-����� ����
		for (int step = 1; step <= MC_steps; step++)
		{

			clusters_ver(a, N, f);

			E = E_system(a, N);
			M = M_system(a, N);

			E_mid += (E - E_mid) / step; // ������� ����
			M_mid += (abs(M) - M_mid) / step;

			M2_mid += ((M * M) - M2_mid) / step;
			E2_mid += ((E * E) - E2_mid) / step;

		} // ����� �����-����� �����

		double chi; // ���� ���������
		chi = (M2_mid - (M_mid * M_mid)) / T;
		double C; // ��������
		C = (E2_mid - (E_mid * E_mid)) / (T * T);
		fo << T << "\t" << E_mid / (N * N) << "\t" << M_mid / (N * N) << "\t" << chi / (N * N) << "\t" << C / (N * N) << "\n";

	} // ����� ����� �� ����
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
		// �������� ������������� ���������� �������
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
