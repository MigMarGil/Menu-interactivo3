# Sistema Interactivo de Matemáticas v2.0

## Descripción

Sistema completo e interactivo en C++ para el estudio de Matemáticas del Grado en Biología. Incluye calculadoras, resolución paso a paso, problemas de examen resueltos y herramientas de práctica para preparar el examen final.

## Contenido del Sistema

### 1. Ecuaciones Diferenciales
- **Ley de Malthus** (Crecimiento exponencial de poblaciones)
- **Ley de Newton** (Enfriamiento y calentamiento)
- **Ecuaciones Lineales** (Administración de medicamentos)
- **Variables Separadas** (Ejercicios resueltos)

### 2. Integrales
- **Teorema Fundamental del Cálculo**
- **Integración por Partes**
- **Funciones Racionales** (Fracciones simples)
- **Calculadora de Integrales** (Polinomios, exponenciales, logaritmos)

### 3. Álgebra Lineal
- **Operaciones con Matrices 2x2**
- **Valores y Vectores Propios**
- **Modelos de Población con Estructura de Edad**
- **Problemas de Examen Resueltos**

### 4. Herramientas Adicionales
- **Referencia Rápida de Fórmulas**
- **Problemas de Examen Completos**
- **Quiz Interactivo de Fórmulas**
- **Tips y Trucos para el Examen**
- **Modo Práctica Guiado**

## Requisitos del Sistema

### Compilador
- **GCC** 7.0 o superior
- **Clang** 5.0 o superior
- **MSVC** 2017 o superior
- Soporte para C++17

### Sistema Operativo
- Linux (Ubuntu, Debian, Fedora, etc.)
- macOS (10.12 o superior)
- Windows (10 o superior)

### Terminal
- Terminal con soporte ANSI para colores (la mayoría de terminales modernas)
- Windows: PowerShell, Windows Terminal, o Git Bash

## Instalación

### Linux / macOS

```bash
# Clonar o descargar el archivo matematicas.cpp

# Compilar el programa
g++ -o matematicas matematicas.cpp -std=c++17 -O2

# Dar permisos de ejecución (opcional en Linux)
chmod +x matematicas

# Ejecutar
./matematicas
```

### Windows

#### Con MinGW/GCC:
```bash
g++ -o matematicas.exe matematicas.cpp -std=c++17 -O2
matematicas.exe
```

#### Con MSVC (Visual Studio):
```bash
cl /EHsc /std:c++17 matematicas.cpp
matematicas.exe
```

### Compilación con Make (opcional)

Crear un archivo `Makefile`:

```makefile
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
TARGET = matematicas

$(TARGET): matematicas.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) matematicas.cpp

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

Luego ejecutar:
```bash
make
make run
```

## Uso del Sistema

### Navegación

El sistema utiliza un menú jerárquico:

```
MENU PRINCIPAL
├── 1. Sistema Interactivo
│   ├── 1.1 Ley de Malthus
│   ├── 1.2 Ley de Newton
│   ├── 1.3 Ecuación Lineal
│   ├── 1.4 Variables Separadas
│   ├── 2.1 Teorema Fundamental
│   ├── 2.2 Integración por Partes
│   ├── 2.3 Funciones Racionales
│   ├── 2.4 Calculadora de Integrales
│   ├── 3.1 Operaciones con Matrices
│   ├── 3.2 Modelo de Población
│   ├── 3.3 Problema Examen 1
│   └── 3.4 Problema Examen 2
├── 2. Referencia Rápida
├── 3. Problemas de Examen
├── 4. Quiz de Fórmulas
├── 5. Tips y Trucos
└── 6. Modo Práctica
```

### Ejemplos de Uso

#### Ejemplo 1: Calcular Crecimiento de Población (Malthus)

```
1. Seleccionar: Sistema Interactivo
2. Ingresar: 1.1
3. Introducir datos:
   - Población inicial P0: 1000
   - Constante r: 0.05
   - Tiempo t: 10
4. Ver resultado: P(10) = 1648.72
5. Interpretación automática
```

#### Ejemplo 2: Resolver Modelo de Población con Edad

```
1. Seleccionar: Sistema Interactivo
2. Ingresar: 3.2
3. Introducir parámetros:
   - Fertilidad beta: 2
   - Supervivencia jóvenes alpha1: 0.75
   - Supervivencia adultos alpha2: 0.5
   - Población inicial: (4, 0)
4. Ver:
   - Valores propios
   - Predicción de crecimiento
   - Simulación 10 años
   - Proporción jóvenes/adultos
```

#### Ejemplo 3: Calcular Integral

```
1. Seleccionar: Sistema Interactivo
2. Ingresar: 2.4
3. Elegir tipo: Exponencial
4. Introducir:
   - Coeficiente a: 2
   - Límite inferior: 0
   - Límite superior: 1
5. Ver resultado con pasos
```

## Características Destacadas

### Colores y Formato
- **Verde**: Resultados correctos y soluciones
- **Amarillo**: Advertencias e interpretaciones
- **Rojo**: Errores y casos especiales
- **Azul**: Títulos y secciones
- **Cyan**: Matrices y estructuras
- **Magenta**: Problemas de examen

### Visualizaciones
- Matrices con formato ASCII art
- Gráficos de barras para funciones
- Tablas de simulación temporal
- Ecuaciones formateadas

### Cálculos Automáticos
- Determinantes de matrices
- Inversas de matrices 2x2
- Valores propios (eigenvalues)
- Vectores propios (eigenvectors)
- Integrales definidas
- Soluciones de ecuaciones diferenciales

## Problemas de Examen Incluidos

### Examen 1
**Problema 1**: Modelo de población con β=2, α₁=3/4, α₂=1/2
- Cálculo de densidad al año siguiente
- Valores propios
- Ritmo de crecimiento a largo plazo
- Proporción jóvenes/adultos

**Problema 2**: Administración de medicamento dx/dt = -ax + b
- Equilibrios
- Solución con condición inicial
- Límite cuando t → ∞

**Problema 3**: Contaminante en balsa con evaporación
- Justificación de ecuación diferencial
- Resolución con variables separadas
- Cantidad al cabo de 1 semana

### Examen 2
**Problema 1**: Población con β=4, α₁=0.4, α₂=0.6
- Matriz del modelo
- Población primeros años
- Valores y vectores propios
- Análisis de crecimiento

**Problema 2**: Ecuación lineal y' = 2y - 3e⁻ˣ
- Verificación de solución particular
- Solución general

**Problema 3**: Población con captura constante
- Equilibrios
- Solución con separación de variables
- Comportamiento límite

## Referencia Rápida de Fórmulas

### Ecuaciones Diferenciales
```
Malthus:           dP/dt = rP              →  P(t) = P₀e^(rt)
Newton:            dT/dt = k(T-Tₐₘᵦ)       →  T(t) = Tₐₘᵦ + (T₀-Tₐₘᵦ)e^(kt)
Lineal:            dy/dx + p(x)y = q(x)    →  y = yₕ + yₚ
Variables Sep.:    dy/dx = f(x)g(y)        →  ∫1/g(y)dy = ∫f(x)dx
```

### Integrales
```
Barrow:            ∫ₐᵇ f(x)dx = [F(x)]ₐᵇ = F(b) - F(a)
Por partes:        ∫u dv = uv - ∫v du
Potencia:          ∫xⁿ dx = x^(n+1)/(n+1) + C   (n ≠ -1)
Logaritmo:         ∫1/x dx = ln|x| + C
Exponencial:       ∫eˣ dx = eˣ + C
```

### Álgebra Lineal
```
Ec. Característica: det(A - λI) = 0
Vector propio:      (A - λI)u = 0
Diagonalización:    A = PDP⁻¹  →  Aⁿ = PDⁿP⁻¹
Valores propios:    λ = (traza ± √(traza² - 4·det)) / 2
Número reprod.:     R₀ = α₁β  (R₀ > 1 → crece, R₀ < 1 → decrece)
```

## Tips para el Examen

### Estrategia General
1. Lee todos los problemas antes de empezar
2. Comienza por el más fácil
3. Gestiona bien el tiempo (25-30 min por problema)
4. Deja espacio para correcciones
5. Revisa al final

### Errores Comunes a Evitar
- Olvidar la constante de integración C
- Confundir λ₊ con λ₋ (el orden importa)
- Signos incorrectos al separar variables
- No simplificar expresiones algebraicas
- Olvidar valores absolutos en logaritmos
- No imponer condiciones iniciales

### Por Tipo de Problema

**Ecuaciones Diferenciales:**
- Identifica el tipo antes de resolver
- Variables separadas: busca f(x)·g(y)
- Lineales: resuelve homogénea + particular
- Siempre impón condiciones iniciales

**Integrales:**
- Verifica si es inmediata o requiere técnica
- Por partes: u = polinomio/log, dv = exp/trigo
- Racionales: factoriza el denominador primero
- Revisa signos en integrales definidas

**Álgebra Lineal:**
- Expande bien el determinante
- Vector propio no es único (hay infinitos)
- λ₊ es el valor propio mayor
- Proporción: β/λ₊ da jóvenes por adulto

## Solución de Problemas

### El programa no compila

**Error**: `error: 'string' was not declared`
```bash
# Solución: Asegúrate de usar C++17
g++ -o matematicas matematicas.cpp -std=c++17
```

**Error**: `undefined reference to 'sqrt'`
```bash
# Solución: Enlaza la biblioteca matemática
g++ -o matematicas matematicas.cpp -std=c++17 -lm
```

### Los colores no se muestran

**Windows**: Usa PowerShell, Windows Terminal o Git Bash en lugar de CMD

**Linux/Mac**: Asegúrate de que tu terminal soporta ANSI colors
```bash
export TERM=xterm-256color
```

### El programa se cierra inmediatamente

```cpp
// Añade al final de main():
std::cout << "Presione Enter para salir...";
std::cin.get();
```

## Contribuciones

Este es un proyecto educativo. Si encuentras errores o quieres añadir funcionalidades:

1. Documenta claramente el problema o mejora
2. Mantén el estilo de código consistente
3. Añade comentarios explicativos
4. Prueba exhaustivamente

## Licencia

Proyecto educativo de uso libre para estudiantes del Grado en Biología.

## Autor

Desarrollado como herramienta de estudio para Matemáticas - UAB

## Contacto y Soporte

Para reportar errores o sugerencias:
- Crea un issue con descripción detallada
- Incluye sistema operativo y compilador usado
- Adjunta mensaje de error si aplica

---

## Guía Rápida de Inicio

```bash
# 1. Descargar o copiar matematicas.cpp

# 2. Compilar
g++ -o matematicas matematicas.cpp -std=c++17 -O2

# 3. Ejecutar
./matematicas

# 4. Explorar el menú principal
# 5. Usar calculadoras interactivas
# 6. Revisar problemas de examen
# 7. Practicar con el quiz

# Buena suerte en tu examen - A por el 10!
```

---

**Versión**: 2.0  
**Última actualización**: Enero 2026  
**Compatibilidad**: C++17+  
**Estado**: Estable y completo
