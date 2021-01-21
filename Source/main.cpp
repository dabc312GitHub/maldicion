#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include <memory>
#include <utility>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef vector<vector<ll>> matrizll;
typedef vector<ll> vectorll;

struct tarea_aea
{
    ll filas{}, dimensiones{};

    matrizll matrix_1;

    vectorll vec_filas;
    vectorll vec_dimensiones;

    tarea_aea(const vectorll& vec_filas, const vectorll& vec_dimensiones)
    {
        this->vec_filas = vec_filas;
        this->vec_dimensiones = vec_dimensiones;

        for (size_t i = 0; i < vec_filas.size(); i++)
        {
            for (size_t j = 0; j < vec_dimensiones.size(); j++)
            {
                generador(i, j);
            }
        }
    }

    void generador(ll i, ll j)
    {
        filas = vec_filas[i];
        dimensiones = vec_dimensiones[j];

        matrix_1.resize(filas);

        rellenarAleatorio(matrix_1);

        medirTiempoTotal();
    }

    void rellenarAleatorio(matrizll& m_vec) const
    {
        ll n = m_vec.size();
        for (size_t i = 0; i < filas; i++)
        {
            m_vec[i].resize(dimensiones);
            generate(m_vec[i].begin(), m_vec[i].end(), rand);
        }
    }

    static void distEuc(vectorll a, vectorll b)
    {
        ll sumZ = 0;
        for (size_t i = 0; i < a.size(); i++)
            sumZ += pow(b[i] - a[i], 2);
        sqrt(sumZ);
    }

    void medirTiempoTotal() {
        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();

        for (size_t i = 0; i < filas; i++)
        {
            for (size_t j = i + 1; j < filas; j++)
            {
                distEuc(matrix_1[i], matrix_1[j]);
            }
        }
//
        end = std::chrono::high_resolution_clock::now();
        int64_t duration =
                std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                        .count();

        std::cout  << std::setw(30)
                  << "Duration: " + std::to_string(duration) + " ns\n";
    }
};


int main() {
    srand(time(nullptr));

    vectorll filas{ 10000, 20000, 25000 };
    vectorll dimensiones{ 5, 10, 15, 20 };

    tarea_aea task(filas, dimensiones);
    return 0;
}