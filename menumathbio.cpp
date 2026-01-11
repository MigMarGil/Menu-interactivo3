#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

// Colores ANSI para terminal
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

// Estructura para almacenar matrices 2x2
struct Matrix2x2
{
    double a11, a12, a21, a22;

    Matrix2x2(double a11 = 0, double a12 = 0, double a21 = 0, double a22 = 0)
        : a11(a11), a12(a12), a21(a21), a22(a22) {}

    void display() const
    {
        cout << CYAN << "┌           ┐" << RESET << endl;
        cout << CYAN << "│ " << RESET << setw(5) << fixed << setprecision(2) << a11
             << " " << setw(5) << a12 << CYAN << " │" << RESET << endl;
        cout << CYAN << "│ " << RESET << setw(5) << a21
             << " " << setw(5) << a22 << CYAN << " │" << RESET << endl;
        cout << CYAN << "└           ┘" << RESET << endl;
    }

    double determinant() const
    {
        return a11 * a22 - a12 * a21;
    }

    Matrix2x2 inverse() const
    {
        double det = determinant();
        if (abs(det) < 1e-10)
        {
            cout << RED << "ERROR: Matriz singular (determinante = 0)" << RESET << endl;
            return Matrix2x2();
        }
        return Matrix2x2(a22 / det, -a12 / det, -a21 / det, a11 / det);
    }

    pair<double, double> eigenvalues() const
    {
        double trace = a11 + a22;
        double det = determinant();
        double discriminant = trace * trace - 4 * det;

        if (discriminant < 0)
        {
            cout << RED << "Valores propios complejos" << RESET << endl;
            return {0, 0};
        }

        double lambda1 = (trace + sqrt(discriminant)) / 2.0;
        double lambda2 = (trace - sqrt(discriminant)) / 2.0;
        return {lambda1, lambda2};
    }
};

// Clase para ecuaciones diferenciales
class DifferentialEquations
{
public:
    static void malthusModel()
    {
        cout << BOLD << BLUE << "\n=== LEY DE MALTHUS: CRECIMIENTO EXPONENCIAL ===" << RESET << endl;
        cout << "Ecuacion: dP/dt = rP" << endl;
        cout << "Solucion: P(t) = P0 * e^(rt)" << endl
             << endl;

        double P0, r, t;
        cout << "Ingrese poblacion inicial P0: ";
        cin >> P0;
        cout << "Ingrese constante de Malthus r: ";
        cin >> r;
        cout << "Ingrese tiempo t: ";
        cin >> t;

        double result = P0 * exp(r * t);

        cout << GREEN << "\nRESULTADO:" << RESET << endl;
        cout << "P(" << t << ") = " << P0 << " * e^(" << r << " * " << t << ")" << endl;
        cout << "P(" << t << ") = " << BOLD << result << RESET << endl;

        if (r > 0)
        {
            cout << YELLOW << "\nInterpretacion: La poblacion CRECE exponencialmente" << RESET << endl;
        }
        else if (r < 0)
        {
            cout << YELLOW << "\nInterpretacion: La poblacion DECRECE exponencialmente" << RESET << endl;
        }
        else
        {
            cout << YELLOW << "\nInterpretacion: La poblacion es CONSTANTE" << RESET << endl;
        }
    }

    static void newtonCooling()
    {
        cout << BOLD << BLUE << "\n=== LEY DE NEWTON DEL ENFRIAMIENTO ===" << RESET << endl;
        cout << "Ecuacion: dT/dt = k(T - Tamb)" << endl;
        cout << "Solucion: T(t) = Tamb + (T0 - Tamb) * e^(kt)" << endl
             << endl;

        double T0, Tamb, t;
        cout << "Ingrese temperatura inicial T0 (C): ";
        cin >> T0;
        cout << "Ingrese temperatura ambiente Tamb (C): ";
        cin >> Tamb;
        cout << "Ingrese tiempo t (minutos): ";
        cin >> t;

        // Calculamos k con datos adicionales si es necesario
        cout << "\nDesea calcular k con un punto adicional? (1=Si, 0=No): ";
        int calcK;
        cin >> calcK;

        double k;
        if (calcK)
        {
            double t1, T1;
            cout << "Ingrese tiempo t1: ";
            cin >> t1;
            cout << "Ingrese temperatura T1: ";
            cin >> T1;
            k = log((T1 - Tamb) / (T0 - Tamb)) / t1;
            cout << GREEN << "Constante k calculada: " << k << RESET << endl;
        }
        else
        {
            cout << "Ingrese constante k: ";
            cin >> k;
        }

        double result = Tamb + (T0 - Tamb) * exp(k * t);

        cout << GREEN << "\nRESULTADO:" << RESET << endl;
        cout << "T(" << t << ") = " << Tamb << " + (" << T0 << " - " << Tamb << ") * e^(" << k << " * " << t << ")" << endl;
        cout << "T(" << t << ") = " << BOLD << result << " C" << RESET << endl;

        if (result > Tamb)
        {
            cout << YELLOW << "\nEl cuerpo se esta ENFRIANDO" << RESET << endl;
        }
        else
        {
            cout << YELLOW << "\nEl cuerpo se esta CALENTANDO" << RESET << endl;
        }
    }

    static void linearEquation()
    {
        cout << BOLD << BLUE << "\n=== ECUACION LINEAL: dx/dt = -ax + b ===" << RESET << endl;
        cout << "Forma general: dx/dt + ax = b" << endl;
        cout << "Solucion: x(t) = (b/a)(1 - e^(-at)) si x(0) = 0" << endl
             << endl;

        double a, b, t;
        cout << "Ingrese coeficiente a (tasa de eliminacion): ";
        cin >> a;
        cout << "Ingrese coeficiente b (tasa de inoculacion): ";
        cin >> b;
        cout << "Ingrese tiempo t: ";
        cin >> t;

        double equilibrium = b / a;
        double result = equilibrium * (1 - exp(-a * t));

        cout << GREEN << "\nRESULTADO:" << RESET << endl;
        cout << "Equilibrio: x_eq = b/a = " << equilibrium << endl;
        cout << "x(" << t << ") = " << BOLD << result << RESET << endl;

        double limit = equilibrium;
        cout << YELLOW << "\nLimite cuando t -> infinito: " << limit << RESET << endl;

        cout << "\nGrafica aproximada (x vs t):" << endl;
        int width = 50;
        for (int i = 0; i <= 10; i++)
        {
            double ti = i * t / 10.0;
            double xi = equilibrium * (1 - exp(-a * ti));
            int bars = (int)(width * xi / equilibrium);
            cout << "t=" << setw(4) << ti << " | ";
            for (int j = 0; j < bars; j++)
                cout << CYAN << "█" << RESET;
            cout << " " << xi << endl;
        }
    }

    static void separableVariables()
    {
        cout << BOLD << BLUE << "\n=== ECUACIONES DE VARIABLES SEPARADAS ===" << RESET << endl;
        cout << "Forma: dy/dx = f(x) * g(y)" << endl;
        cout << "Metodo: Integral(1/g(y) dy) = Integral(f(x) dx)" << endl
             << endl;

        cout << "EJEMPLO RESUELTO: dy/dx = xy con y(0) = 3" << endl;
        cout << "\nPaso 1: Separar variables" << endl;
        cout << "  dy/y = x dx" << endl;

        cout << "\nPaso 2: Integrar ambos lados" << endl;
        cout << "  ln|y| = x^2/2 + C" << endl;

        cout << "\nPaso 3: Despejar y" << endl;
        cout << "  y = C * e^(x^2/2)" << endl;

        cout << "\nPaso 4: Imponer condicion inicial y(0) = 3" << endl;
        cout << "  3 = C * e^0 = C" << endl;
        cout << "  Por tanto C = 3" << endl;

        cout << GREEN << "\nSOLUCION FINAL: y = 3 * e^(x^2/2)" << RESET << endl;

        cout << "\nCalcular y para un valor de x? (1=Si, 0=No): ";
        int calc;
        cin >> calc;
        if (calc)
        {
            double x;
            cout << "Ingrese x: ";
            cin >> x;
            double y = 3 * exp(x * x / 2.0);
            cout << GREEN << "y(" << x << ") = " << y << RESET << endl;
        }
    }
};

// Clase para integrales
class Integrals
{
public:
    static void fundamentalTheorem()
    {
        cout << BOLD << BLUE << "\n=== TEOREMA FUNDAMENTAL DEL CALCULO ===" << RESET << endl;
        cout << "Si F'(x) = f(x), entonces:" << endl;
        cout << "Integral de a a b de f(x)dx = F(b) - F(a) = [F(x)]_a^b" << endl
             << endl;

        cout << "EJEMPLO 1: Integral de 0 a 1 de e^x dx" << endl;
        cout << "Primitiva: F(x) = e^x" << endl;
        double result1 = exp(1) - exp(0);
        cout << "Resultado: [e^x]_0^1 = e^1 - e^0 = " << GREEN << result1 << RESET << endl;

        cout << "\nEJEMPLO 2: Integral de 1 a 2 de 1/x dx" << endl;
        cout << "Primitiva: F(x) = ln(x)" << endl;
        double result2 = log(2) - log(1);
        cout << "Resultado: [ln(x)]_1^2 = ln(2) - ln(1) = " << GREEN << result2 << RESET << endl;
    }

    static void integrationByParts()
    {
        cout << BOLD << BLUE << "\n=== INTEGRACION POR PARTES ===" << RESET << endl;
        cout << "Formula: Integral(u dv) = uv - Integral(v du)" << endl
             << endl;

        cout << "EJEMPLO: Integral de x * e^(-x) dx" << endl;
        cout << "\nPaso 1: Elegir u y dv" << endl;
        cout << "  u = x          =>  du = dx" << endl;
        cout << "  dv = e^(-x)dx  =>  v = -e^(-x)" << endl;

        cout << "\nPaso 2: Aplicar la formula" << endl;
        cout << "  = x*(-e^(-x)) - Integral(-e^(-x) dx)" << endl;
        cout << "  = -x*e^(-x) + Integral(e^(-x) dx)" << endl;
        cout << "  = -x*e^(-x) - e^(-x)" << endl;

        cout << GREEN << "\nSOLUCION: -(x+1)*e^(-x) + C" << RESET << endl;

        cout << "\nEJEMPLO 2: Integral de ln(x) dx" << endl;
        cout << "  u = ln(x)  =>  du = (1/x)dx" << endl;
        cout << "  dv = dx    =>  v = x" << endl;
        cout << "  = x*ln(x) - Integral(x * (1/x) dx)" << endl;
        cout << "  = x*ln(x) - Integral(1 dx)" << endl;
        cout << "  = x*ln(x) - x" << endl;

        cout << GREEN << "\nSOLUCION: x*ln(x) - x + C" << RESET << endl;
    }

    static void rationalFunctions()
    {
        cout << BOLD << BLUE << "\n=== INTEGRACION DE FUNCIONES RACIONALES ===" << RESET << endl;
        cout << "Metodo: Descomposicion en fracciones simples" << endl
             << endl;

        cout << "EJEMPLO: Integral de (x-7)/(x^2-2x-3) dx de 0 a 1" << endl;
        cout << "\nPaso 1: Factorizar denominador" << endl;
        cout << "  x^2 - 2x - 3 = (x-3)(x+1)" << endl;

        cout << "\nPaso 2: Descomponer en fracciones simples" << endl;
        cout << "  (x-7)/((x-3)(x+1)) = A/(x-3) + B/(x+1)" << endl;
        cout << "  x-7 = A(x+1) + B(x-3)" << endl;

        cout << "\nPaso 3: Resolver sistema" << endl;
        cout << "  A + B = 1" << endl;
        cout << "  A - 3B = -7" << endl;
        cout << "  Solucion: A = -1/4, B = 27/4" << endl;

        cout << "\nPaso 4: Integrar" << endl;
        cout << "  = -1/4 * ln|x-3| + 27/4 * ln|x+1|" << endl;

        double result = -0.25 * log(2) + 6.75 * log(2) - (-0.25 * log(3));
        cout << GREEN << "\nRESULTADO: " << result << RESET << endl;
    }

    static void customIntegral()
    {
        cout << BOLD << BLUE << "\n=== CALCULADORA DE INTEGRALES ===" << RESET << endl;
        cout << "Seleccione tipo de funcion:" << endl;
        cout << "1. Polinomio: x^n" << endl;
        cout << "2. Exponencial: e^(ax)" << endl;
        cout << "3. Logaritmo: ln(x)" << endl;
        cout << "4. Racional: 1/(ax+b)" << endl;

        int choice;
        cout << "\nOpcion: ";
        cin >> choice;

        double a, b, n;

        switch (choice)
        {
        case 1:
            cout << "Ingrese exponente n: ";
            cin >> n;
            cout << "Ingrese limite inferior a: ";
            cin >> a;
            cout << "Ingrese limite superior b: ";
            cin >> b;
            if (abs(n + 1) < 1e-10)
            {
                double result = log(abs(b)) - log(abs(a));
                cout << GREEN << "Integral = ln|x| de " << a << " a " << b << " = " << result << RESET << endl;
            }
            else
            {
                double result = (pow(b, n + 1) - pow(a, n + 1)) / (n + 1);
                cout << GREEN << "Integral = x^" << n + 1 << "/" << n + 1 << " de " << a << " a " << b << " = " << result << RESET << endl;
            }
            break;

        case 2:
            cout << "Ingrese coeficiente a: ";
            cin >> a;
            cout << "Ingrese limite inferior: ";
            cin >> b;
            double upper;
            cout << "Ingrese limite superior: ";
            cin >> upper;
            {
                double result = (exp(a * upper) - exp(a * b)) / a;
                cout << GREEN << "Integral = e^(" << a << "x)/" << a << " de " << b << " a " << upper << " = " << result << RESET << endl;
            }
            break;

        case 3:
            cout << "Ingrese limite inferior a: ";
            cin >> a;
            cout << "Ingrese limite superior b: ";
            cin >> b;
            {
                double result = b * log(b) - b - (a * log(a) - a);
                cout << GREEN << "Integral = x*ln(x) - x de " << a << " a " << b << " = " << result << RESET << endl;
            }
            break;

        case 4:
            double coef, cons;
            cout << "Ingrese coeficiente a: ";
            cin >> coef;
            cout << "Ingrese constante b: ";
            cin >> cons;
            cout << "Ingrese limite inferior: ";
            cin >> a;
            cout << "Ingrese limite superior: ";
            cin >> b;
            {
                double result = (log(abs(coef * b + cons)) - log(abs(coef * a + cons))) / coef;
                cout << GREEN << "Integral = ln|" << coef << "x+" << cons << "|/" << coef << " de " << a << " a " << b << " = " << result << RESET << endl;
            }
            break;
        }
    }
};

// Clase para álgebra lineal
class LinearAlgebra
{
public:
    static void matrixOperations()
    {
        cout << BOLD << BLUE << "\n=== OPERACIONES CON MATRICES 2x2 ===" << RESET << endl;

        Matrix2x2 A;
        cout << "Ingrese elementos de la matriz A:" << endl;
        cout << "a11: ";
        cin >> A.a11;
        cout << "a12: ";
        cin >> A.a12;
        cout << "a21: ";
        cin >> A.a21;
        cout << "a22: ";
        cin >> A.a22;

        cout << "\nMatriz A:" << endl;
        A.display();

        cout << GREEN << "Determinante: " << A.determinant() << RESET << endl;

        if (abs(A.determinant()) > 1e-10)
        {
            cout << "\nMatriz Inversa A^(-1):" << endl;
            Matrix2x2 inv = A.inverse();
            inv.display();
        }

        auto [lambda1, lambda2] = A.eigenvalues();
        cout << GREEN << "\nValores propios:" << RESET << endl;
        cout << "  lambda_1 = " << BOLD << lambda1 << RESET << endl;
        cout << "  lambda_2 = " << BOLD << lambda2 << RESET << endl;

        if (lambda1 > lambda2)
        {
            cout << "\nVector propio asociado a lambda_1 = " << lambda1 << ":" << endl;
            calculateEigenvector(A, lambda1);
        }
    }

    static void calculateEigenvector(const Matrix2x2 &A, double lambda)
    {
        double a = A.a11 - lambda;
        double b = A.a12;
        double c = A.a21;
        double d = A.a22 - lambda;

        cout << "Resolver: (" << a << ")u1 + (" << b << ")u2 = 0" << endl;
        cout << "          (" << c << ")u1 + (" << d << ")u2 = 0" << endl;

        if (abs(b) > 1e-10)
        {
            double ratio = -a / b;
            cout << GREEN << "Relacion: u1 = " << ratio << " * u2" << RESET << endl;
            cout << "Ejemplo: u = (" << ratio << ", 1)" << endl;
        }
        else if (abs(a) > 1e-10)
        {
            cout << GREEN << "u2 puede ser cualquier valor" << RESET << endl;
            cout << "Ejemplo: u = (0, 1)" << endl;
        }
    }

    static void populationModel()
    {
        cout << BOLD << BLUE << "\n=== MODELO DE POBLACION CON ESTRUCTURA DE EDAD ===" << RESET << endl;
        cout << "Grupos: Jovenes (infertiles) y Adultos (fertiles)" << endl;
        cout << "Modelo: [p_(n+1)]   [  0    beta ] [p_n]" << endl;
        cout << "        [q_(n+1)] = [alpha1 alpha2] [q_n]" << endl
             << endl;

        double beta, alpha1, alpha2, p0, q0;

        cout << "Ingrese fertilidad beta: ";
        cin >> beta;
        cout << "Ingrese supervivencia jovenes alpha1: ";
        cin >> alpha1;
        cout << "Ingrese supervivencia adultos alpha2: ";
        cin >> alpha2;
        cout << "Ingrese poblacion inicial de jovenes p0: ";
        cin >> p0;
        cout << "Ingrese poblacion inicial de adultos q0: ";
        cin >> q0;

        Matrix2x2 A(0, beta, alpha1, alpha2);

        cout << "\nMatriz del modelo:" << endl;
        A.display();

        auto [lambda, mu] = A.eigenvalues();

        cout << GREEN << "\nValores propios:" << RESET << endl;
        cout << "  lambda = " << BOLD << lambda << RESET << endl;
        cout << "  mu = " << mu << endl;

        double R0 = alpha1 * beta;
        cout << YELLOW << "\nNumero reproductivo basico R0 = alpha1 * beta = " << R0 << RESET << endl;

        if (lambda > 1)
        {
            cout << GREEN << "\nLa poblacion CRECERA a largo plazo" << RESET << endl;
            cout << "Ritmo de crecimiento: se multiplica por " << BOLD << lambda << RESET << " cada ano" << endl;
        }
        else if (lambda < 1)
        {
            cout << RED << "\nLa poblacion DECRECERA (se extinguira)" << RESET << endl;
        }
        else
        {
            cout << YELLOW << "\nLa poblacion permanecera ESTABLE" << RESET << endl;
        }

        double ratio = beta / lambda;
        cout << "\nProporcion de jovenes a adultos a largo plazo: " << BOLD << ratio << RESET << endl;

        // Simular primeros años
        cout << "\nSimulacion de los primeros 10 anos:" << endl;
        cout << setw(5) << "Ano" << setw(15) << "Jovenes" << setw(15) << "Adultos" << setw(15) << "Total" << endl;
        cout << string(50, '-') << endl;

        double p = p0, q = q0;
        for (int n = 0; n <= 10; n++)
        {
            cout << setw(5) << n << setw(15) << fixed << setprecision(2) << p
                 << setw(15) << q << setw(15) << (p + q) << endl;

            double p_new = beta * q;
            double q_new = alpha1 * p + alpha2 * q;
            p = p_new;
            q = q_new;
        }
    }

    static void examProblem1()
    {
        cout << BOLD << MAGENTA << "\n=== PROBLEMA DE EXAMEN 1 ===" << RESET << endl;
        cout << "Poblacion: beta=2, alpha1=3/4, alpha2=1/2, (p0,q0)=(4,0)" << endl;

        Matrix2x2 A(0, 2, 0.75, 0.5);

        cout << "\nMatriz A:" << endl;
        A.display();

        // Año siguiente
        double p1 = 2 * 0;
        double q1 = 0.75 * 4 + 0.5 * 0;
        cout << GREEN << "\na) Densidad al ano siguiente: (" << p1 << ", " << q1 << ")" << RESET << endl;

        // Valores propios
        auto [lambda, mu] = A.eigenvalues();
        cout << "\nb) Valores propios: lambda = " << lambda << ", mu = " << mu << endl;

        cout << GREEN << "\nRitmo de crecimiento: x" << lambda << " (crecimiento del "
             << (lambda - 1) * 100 << "%)" << RESET << endl;

        double ratio = 2.0 / lambda;
        cout << "Proporcion jovenes/adultos: " << ratio << " (4 jovenes por cada 3 adultos)" << RESET << endl;
    }

    static void examProblem2()
    {
        cout << BOLD << MAGENTA << "\n=== PROBLEMA DE EXAMEN 2 ===" << RESET << endl;
        cout << "Poblacion: beta=4, alpha1=0.4, alpha2=0.6, (p0,q0)=(10,10)" << endl;

        Matrix2x2 A(0, 4, 0.4, 0.6);

        cout << "\nMatriz A:" << endl;
        A.display();

        // Primeros años
        double p1 = 4 * 10;
        double q1 = 0.4 * 10 + 0.6 * 10;
        cout << GREEN << "\nAno 1: (" << p1 << ", " << q1 << ")" << RESET << endl;

        double p2 = 4 * q1;
        double q2 = 0.4 * p1 + 0.6 * q1;
        cout << GREEN << "Ano 2: (" << p2 << ", " << q2 << ")" << RESET << endl;

        auto [lambda, mu] = A.eigenvalues();
        cout << "\nValores propios: lambda = " << lambda << ", mu = " << mu << endl;

        cout << GREEN << "\nLa poblacion CRECE multiplicandose por " << lambda << " cada ano" << RESET << endl;
        cout << "Proporcion: 2.5 jovenes por cada adulto (5 jovenes por cada 2 adultos)" << endl;
    }
};

// Clase principal del sistema
class MathematicsSystem
{
private:
    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void showHeader(const string &title)
    {
        cout << "\n";
        cout << BOLD << CYAN << string(70, '=') << RESET << endl;
        cout << BOLD << WHITE << "  " << title << RESET << endl;
        cout << BOLD << CYAN << string(70, '=') << RESET << endl;
    }

    void pause()
    {
        cout << "\n"
             << YELLOW << "Presione Enter para continuar..." << RESET;
        cin.ignore();
        cin.get();
    }

public:
    void run()
    {
        while (true)
        {
            clearScreen();
            showHeader("SISTEMA INTERACTIVO DE MATEMATICAS - RESUMEN COMPLETO");

            cout << "\n"
                 << BOLD << "MENU PRINCIPAL:" << RESET << endl;
            cout << "\n"
                 << BOLD << GREEN << "1. ECUACIONES DIFERENCIALES" << RESET << endl;
            cout << "   1.1 Ley de Malthus (Crecimiento Exponencial)" << endl;
            cout << "   1.2 Ley de Newton (Enfriamiento/Calentamiento)" << endl;
            cout << "   1.3 Ecuacion Lineal (Medicamento en sangre)" << endl;
            cout << "   1.4 Variables Separadas (Ejercicio resuelto)" << endl;

            cout << "\n"
                 << BOLD << BLUE << "2. INTEGRALES" << RESET << endl;
            cout << "   2.1 Teorema Fundamental del Calculo" << endl;
            cout << "   2.2 Integracion por Partes" << endl;
            cout << "   2.3 Funciones Racionales (Fracciones Simples)" << endl;
            cout << "   2.4 Calculadora de Integrales" << endl;

            cout << "\n"
                 << BOLD << MAGENTA << "3. ALGEBRA LINEAL" << RESET << endl;
            cout << "   3.1 Operaciones con Matrices" << endl;
            cout << "   3.2 Modelo de Poblacion con Estructura de Edad" << endl;
            cout << "   3.3 Problema de Examen 1 (Resuelto)" << endl;
            cout << "   3.4 Problema de Examen 2 (Resuelto)" << endl;

            cout << "\n"
                 << BOLD << RED << "0. SALIR" << RESET << endl;

            cout << "\n"
                 << BOLD << "Seleccione una opcion: " << RESET;

            string input;
            getline(cin, input);

            if (input.empty())
                continue;

            if (input == "0")
            {
                cout << BOLD << GREEN << "\nGracias por usar el Sistema de Matematicas." << RESET << endl;
                cout << BOLD << YELLOW << "Mucha suerte en tu examen - A por el 10!" << RESET << endl;
                break;
            }

            clearScreen();

            if (input == "1.1")
            {
                DifferentialEquations::malthusModel();
                pause();
            }
            else if (input == "1.2")
            {
                DifferentialEquations::newtonCooling();
                pause();
            }
            else if (input == "1.3")
            {
                DifferentialEquations::linearEquation();
                pause();
            }
            else if (input == "1.4")
            {
                DifferentialEquations::separableVariables();
                pause();
            }
            else if (input == "2.1")
            {
                Integrals::fundamentalTheorem();
                pause();
            }
            else if (input == "2.2")
            {
                Integrals::integrationByParts();
                pause();
            }
            else if (input == "2.3")
            {
                Integrals::rationalFunctions();
                pause();
            }
            else if (input == "2.4")
            {
                Integrals::customIntegral();
                pause();
            }
            else if (input == "3.1")
            {
                LinearAlgebra::matrixOperations();
                pause();
            }
            else if (input == "3.2")
            {
                LinearAlgebra::populationModel();
                pause();
            }
            else if (input == "3.3")
            {
                LinearAlgebra::examProblem1();
                pause();
            }
            else if (input == "3.4")
            {
                LinearAlgebra::examProblem2();
                pause();
            }
            else
            {
                cout << RED << "\nOpcion no valida. Por favor intente de nuevo." << RESET << endl;
                pause();
            }
        }
    }

    void showQuickReference()
    {
        showHeader("REFERENCIA RAPIDA DE FORMULAS");

        cout << BOLD << "\nECUACIONES DIFERENCIALES:" << RESET << endl;
        cout << "  Malthus:           dP/dt = rP  =>  P(t) = P0*e^(rt)" << endl;
        cout << "  Newton:            dT/dt = k(T-Tamb)  =>  T(t) = Tamb + (T0-Tamb)*e^(kt)" << endl;
        cout << "  Lineal:            dy/dx + p(x)y = q(x)  =>  y_g = y_h + y_p" << endl;
        cout << "  Variables Sep.:    dy/dx = f(x)*g(y)  =>  Integral(1/g(y) dy) = Integral(f(x) dx)" << endl;

        cout << BOLD << "\nINTEGRALES:" << RESET << endl;
        cout << "  Barrow:            Integral_a^b f(x)dx = [F(x)]_a^b = F(b) - F(a)" << endl;
        cout << "  Por partes:        Integral(u dv) = uv - Integral(v du)" << endl;
        cout << "  Potencia:          Integral(x^n dx) = x^(n+1)/(n+1) + C   (n != -1)" << endl;
        cout << "  Logaritmo:         Integral(1/x dx) = ln|x| + C" << endl;
        cout << "  Exponencial:       Integral(e^x dx) = e^x + C" << endl;
        cout << "  Lineal:            Integral(f(ax+b) dx) = (1/a)*F(ax+b)" << endl;

        cout << BOLD << "\nALGEBRA LINEAL:" << RESET << endl;
        cout << "  Ec. Caracteristica: det(A - lambda*I) = 0" << endl;
        cout << "  Vector propio:      (A - lambda*I)*u = 0" << endl;
        cout << "  Diagonalizacion:    A = P*D*P^(-1)  =>  A^n = P*D^n*P^(-1)" << endl;
        cout << "  Valores propios:    lambda = (trace +- sqrt(trace^2 - 4*det)) / 2" << endl;
        cout << "  Poblacion:          R0 = alpha1*beta" << endl;
        cout << "                      R0 > 1 => crece,  R0 < 1 => decrece" << endl;

        cout << BOLD << "\nCONSEJOS PARA EL EXAMEN:" << RESET << endl;
        cout << "  1. Lee el problema completo antes de empezar" << endl;
        cout << "  2. Identifica el tipo de ecuacion/problema" << endl;
        cout << "  3. Escribe la formula general antes de sustituir" << endl;
        cout << "  4. No olvides las condiciones iniciales" << endl;
        cout << "  5. Verifica las unidades en problemas aplicados" << endl;
        cout << "  6. Comprueba que lambda_+ > lambda_- en poblaciones" << endl;
        cout << "  7. Los vectores propios no son unicos (multiples escalares)" << endl;
        cout << "  8. Revisa los signos en integrales definidas" << endl;
    }
};

// Funciones adicionales de utilidad
void showExamProblems()
{
    cout << BOLD << CYAN << "\n=== PROBLEMAS DE EXAMEN COMPLETOS ===" << RESET << endl;

    cout << BOLD << "\nEXAMEN 1 - PROBLEMA 2:" << RESET << endl;
    cout << "Medicamento: dx/dt = -ax + b, x(0) = 0" << endl;
    cout << "  a) Equilibrios: x = b/a" << endl;
    cout << "  b) Solucion: x(t) = (b/a)(1 - e^(-at))" << endl;
    cout << "  c) Limite: x -> b/a cuando t -> infinito" << endl;

    cout << BOLD << "\nEXAMEN 1 - PROBLEMA 3:" << RESET << endl;
    cout << "Balsa: V(t) = 1200 - 120t, x(0) = 10g" << endl;
    cout << "  dx/dt = -100 * x/(1200-120t)" << endl;
    cout << "  Solucion: x(t) = 10(1-t/10)^(5/6)" << endl;
    cout << "  x(7) = 10(0.3)^(5/6) = 3.667 gramos" << endl;

    cout << BOLD << "\nEXAMEN 2 - PROBLEMA 3:" << RESET << endl;
    cout << "Captura: dx/dt = -(1/10)(x-9)(x-1), x(0) = 2" << endl;
    cout << "  Equilibrios: x = 9, x = 1" << endl;
    cout << "  Solucion: x(t) = (9 + 7e^(-4t/5))/(1 + 7e^(-4t/5))" << endl;
    cout << "  Limite: x -> 9 cuando t -> infinito" << endl;
}

void interactiveFormulasQuiz()
{
    cout << BOLD << BLUE << "\n=== QUIZ DE FORMULAS ===" << RESET << endl;
    cout << "Pon a prueba tus conocimientos!\n"
         << endl;

    vector<pair<string, string>> questions = {
        {"Cual es la solucion de dP/dt = rP?", "P(t) = P0*e^(rt)"},
        {"Formula de integracion por partes?", "Integral(u dv) = uv - Integral(v du)"},
        {"Ecuacion caracteristica para valores propios?", "det(A - lambda*I) = 0"},
        {"Primitiva de 1/x?", "ln|x| + C"},
        {"Condicion para crecimiento poblacional?", "lambda > 1 o R0 > 1"},
        {"Teorema Fundamental del Calculo?", "Integral_a^b f(x)dx = F(b) - F(a)"},
        {"Numero reproductivo basico R0?", "R0 = alpha1*beta"},
        {"Primitiva de e^x?", "e^x + C"}};

    int correct = 0;
    for (size_t i = 0; i < questions.size(); i++)
    {
        cout << BOLD << "Pregunta " << i + 1 << ": " << RESET << questions[i].first << endl;
        cout << "Respuesta: ";
        string answer;
        getline(cin, answer);

        cout << GREEN << "Respuesta correcta: " << questions[i].second << RESET << endl;
        cout << "Fue correcta tu respuesta? (s/n): ";
        char check;
        cin >> check;
        cin.ignore();
        if (check == 's' || check == 'S')
            correct++;
        cout << endl;
    }

    cout << BOLD << "Resultado: " << correct << "/" << questions.size() << RESET << endl;
    if (correct == questions.size())
    {
        cout << GREEN << "Perfecto! Estas listo para el examen!" << RESET << endl;
    }
    else if (correct >= questions.size() * 0.7)
    {
        cout << YELLOW << "Muy bien! Repasa un poco mas y estaras perfecto." << RESET << endl;
    }
    else
    {
        cout << RED << "Necesitas estudiar mas. Repasa la teoria!" << RESET << endl;
    }
}

void showTipsAndTricks()
{
    cout << BOLD << MAGENTA << "\n=== TIPS Y TRUCOS PARA EL EXAMEN ===" << RESET << endl;

    cout << BOLD << "\n1. ECUACIONES DIFERENCIALES:" << RESET << endl;
    cout << "   - Siempre identifica el TIPO antes de resolver" << endl;
    cout << "   - Variables separadas: busca f(x)*g(y)" << endl;
    cout << "   - Lineales: separa homogenea + particular" << endl;
    cout << "   - NO OLVIDES imponer condiciones iniciales!" << endl;

    cout << BOLD << "\n2. INTEGRALES:" << RESET << endl;
    cout << "   - Verifica si es inmediata o necesita tecnica" << endl;
    cout << "   - Por partes: u = polinomio/log, dv = exponencial/trigo" << endl;
    cout << "   - Racionales: factoriza SIEMPRE el denominador primero" << endl;
    cout << "   - Barrow: cuidado con los signos!" << endl;

    cout << BOLD << "\n3. ALGEBRA LINEAL:" << RESET << endl;
    cout << "   - Ecuacion caracteristica: expande bien el determinante" << endl;
    cout << "   - Vector propio: no es unico, hay infinitos" << endl;
    cout << "   - Poblacion: lambda_+ es el mayor valor propio" << endl;
    cout << "   - Proporcion: beta/lambda_+ da jovenes por adulto" << endl;

    cout << BOLD << "\n4. ESTRATEGIA DE EXAMEN:" << RESET << endl;
    cout << "   - Lee TODOS los problemas primero" << endl;
    cout << "   - Empieza por el mas facil" << endl;
    cout << "   - Deja espacio para correciones" << endl;
    cout << "   - Revisa unidades en problemas aplicados" << endl;
    cout << "   - Si te atascas, pasa al siguiente" << endl;

    cout << BOLD << "\n5. ERRORES COMUNES:" << RESET << endl;
    cout << "   - Olvidar la constante de integracion C" << endl;
    cout << "   - Confundir lambda con mu (orden importa!)" << endl;
    cout << "   - Signos incorrectos al separar variables" << endl;
    cout << "   - No simplificar fracciones algebraicas" << endl;
    cout << "   - Olvidar valores absolutos en logaritmos" << endl;
}

void practiceMode()
{
    cout << BOLD << GREEN << "\n=== MODO PRACTICA ===" << RESET << endl;
    cout << "\nSelecciona tipo de practica:" << endl;
    cout << "1. Ecuaciones Diferenciales" << endl;
    cout << "2. Integrales" << endl;
    cout << "3. Algebra Lineal" << endl;

    int choice;
    cout << "\nOpcion: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        cout << BOLD << "\nPRACTICA: Resuelve dy/dx = 2xy con y(0) = 1" << RESET << endl;
        cout << "\nPaso 1: Separar variables" << endl;
        cout << "  dy/y = 2x dx" << endl;
        cout << "\nPaso 2: Integrar" << endl;
        cout << "  ln|y| = x^2 + C" << endl;
        cout << "\nPaso 3: Despejar" << endl;
        cout << "  y = C*e^(x^2)" << endl;
        cout << "\nPaso 4: Aplicar y(0) = 1" << endl;
        cout << "  1 = C*e^0 = C" << endl;
        cout << GREEN << "\nSolucion: y = e^(x^2)" << RESET << endl;
        break;

    case 2:
        cout << BOLD << "\nPRACTICA: Calcula Integral de x*ln(x) dx" << RESET << endl;
        cout << "\nTecnica: Integracion por partes" << endl;
        cout << "  u = ln(x)  =>  du = (1/x)dx" << endl;
        cout << "  dv = x dx  =>  v = x^2/2" << endl;
        cout << "\nAplicar:" << endl;
        cout << "  = (x^2/2)*ln(x) - Integral((x^2/2)*(1/x) dx)" << endl;
        cout << "  = (x^2/2)*ln(x) - Integral(x/2 dx)" << endl;
        cout << "  = (x^2/2)*ln(x) - x^2/4" << endl;
        cout << GREEN << "\nSolucion: (x^2/2)*ln(x) - x^2/4 + C" << RESET << endl;
        break;

    case 3:
        cout << BOLD << "\nPRACTICA: Encuentra valores propios de A = [2 1; 1 2]" << RESET << endl;
        cout << "\nPaso 1: Ecuacion caracteristica" << endl;
        cout << "  det(A - lambda*I) = 0" << endl;
        cout << "  |(2-lambda)    1      |" << endl;
        cout << "  |   1      (2-lambda)| = 0" << endl;
        cout << "\nPaso 2: Expandir" << endl;
        cout << "  (2-lambda)^2 - 1 = 0" << endl;
        cout << "  4 - 4*lambda + lambda^2 - 1 = 0" << endl;
        cout << "  lambda^2 - 4*lambda + 3 = 0" << endl;
        cout << "\nPaso 3: Resolver" << endl;
        cout << "  (lambda - 3)(lambda - 1) = 0" << endl;
        cout << GREEN << "\nSolucion: lambda1 = 3, lambda2 = 1" << RESET << endl;
        break;
    }
}

// Funcion principal
int main()
{
    cout << BOLD << CYAN;
    cout << R"(
    ╔═══════════════════════════════════════════════════════════════╗
    ║                                                               ║
    ║        SISTEMA INTERACTIVO DE MATEMATICAS v2.0               ║
    ║                                                               ║
    ║        Ecuaciones Diferenciales + Integrales + Algebra       ║
    ║                                                               ║
    ║                 Preparacion para el EXAMEN                   ║
    ║                                                               ║
    ╚═══════════════════════════════════════════════════════════════╝
    )" << RESET
         << endl;

    cout << BOLD << WHITE << "\n  Presione Enter para comenzar..." << RESET;
    cin.get();

    while (true)
    {
        cout << "\n"
             << BOLD << BLUE << "MENU PRINCIPAL:" << RESET << endl;
        cout << "1. Sistema Interactivo (Calculadoras y Ejercicios)" << endl;
        cout << "2. Referencia Rapida de Formulas" << endl;
        cout << "3. Problemas de Examen Resueltos" << endl;
        cout << "4. Quiz de Formulas" << endl;
        cout << "5. Tips y Trucos" << endl;
        cout << "6. Modo Practica" << endl;
        cout << "0. Salir" << endl;

        cout << BOLD << "\nSeleccione opcion: " << RESET;
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 0)
        {
            cout << BOLD << GREEN << "\nGracias por usar el sistema!" << RESET << endl;
            cout << BOLD << YELLOW << "Exito en tu examen - A por el 10!" << RESET << endl;
            break;
        }

        switch (choice)
        {
        case 1:
        {
            MathematicsSystem system;
            system.run();
            break;
        }
        case 2:
        {
            MathematicsSystem system;
            system.showQuickReference();
            cout << YELLOW << "\nPresione Enter para continuar..." << RESET;
            cin.get();
            break;
        }
        case 3:
            showExamProblems();
            cout << YELLOW << "\nPresione Enter para continuar..." << RESET;
            cin.get();
            break;
        case 4:
            interactiveFormulasQuiz();
            cout << YELLOW << "\nPresione Enter para continuar..." << RESET;
            cin.get();
            break;
        case 5:
            showTipsAndTricks();
            cout << YELLOW << "\nPresione Enter para continuar..." << RESET;
            cin.get();
            break;
        case 6:
            practiceMode();
            cout << YELLOW << "\nPresione Enter para continuar..." << RESET;
            cin.get();
            break;
        default:
            cout << RED << "Opcion invalida" << RESET << endl;
        }
    }

    return 0;
}