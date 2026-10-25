Factorial Engine Pro

Sistema profesional de cálculo de factoriales de alta precisión

"Lenguaje" (https://img.shields.io/badge/Lenguaje-C-blue)
"Estándar" (https://img.shields.io/badge/Estándar-C11-orange)
"Versión" (https://img.shields.io/badge/Versión-1.0.0-green)

Descripción del proyecto

Factorial Engine Pro es una aplicación de consola desarrollada en lenguaje C para calcular factoriales mediante una implementación propia de aritmética de precisión arbitraria.

A diferencia de las implementaciones tradicionales que utilizan tipos enteros de tamaño fijo, este sistema representa los números mediante arreglos de dígitos decimales. De esta manera, puede calcular resultados que superan la capacidad de los tipos enteros convencionales de C.

El sistema incorpora cálculo individual de factoriales, generación de series, validación de entradas y control de la capacidad de almacenamiento.

Funcionalidades principales

- Cálculo de factoriales: calcula el factorial de un número entero no negativo.
- Aritmética de precisión arbitraria: representa los resultados mediante arreglos de dígitos decimales.
- Generación de series: calcula factoriales consecutivos desde cero hasta un límite indicado.
- Resultados exactos: conserva todos los dígitos del resultado dentro de la capacidad disponible.
- Validación de entradas: detecta números negativos, entradas inválidas y valores fuera del rango permitido.
- Control de capacidad: comprueba que el resultado no exceda la capacidad interna del arreglo.
- Interfaz interactiva: permite seleccionar las operaciones mediante un menú de consola.
- Código estructurado: separa las funciones de cálculo, validación y presentación de resultados.

Tecnologías utilizadas

- Lenguaje de programación C.
- Estándar C11.
- Compilador GCC.
- Visual Studio Code.
- Git y GitHub para el control de versiones.

Requisitos

- Un compilador compatible con C11, como GCC.
- Una terminal o consola de comandos.
- Windows, Linux u otro sistema operativo compatible.

Instalación y ejecución

1. Clonar el repositorio

Sustituye "TU_USUARIO" por tu nombre de usuario de GitHub.

git clone https://github.com/TU_USUARIO/Factorial-Engine-Pro.git

2. Entrar en la carpeta del proyecto

cd Factorial-Engine-Pro

3. Compilar el programa

gcc -std=c11 -Wall -Wextra -Wpedantic -O2 FactorialEngine.c -o FactorialEngine.exe

4. Ejecutar la aplicación

En PowerShell:

.\FactorialEngine.exe

Opciones del sistema

Opción| Función
1| Calcular el factorial de un número
2| Generar una serie de factoriales
0| Salir de la aplicación

Ejemplo de funcionamiento

========================================
       Factorial Engine Pro
                Version 1.0.0
========================================
1. Calculate a factorial
2. Generate a factorial series
0. Exit
========================================
Select an option: 1

Enter a non-negative integer (0-1000): 20

========================================
             FACTORIAL REPORT
========================================
20! = 2432902008176640000
Number of decimal digits: 19
========================================

Fundamento matemático

El factorial de un número entero no negativo es el producto de todos los enteros positivos menores o iguales que ese número.

Se representa mediante el símbolo "!".

Por definición:

- 0! = 1
- 1! = 1
- n! = n × (n - 1)! para n ≥ 2

Implementación técnica

El programa utiliza una estructura llamada "BigInteger", que contiene:

- Un arreglo para almacenar los dígitos decimales.
- Un campo que indica la cantidad de dígitos utilizados.

Los dígitos se almacenan en orden inverso, comenzando por las unidades.

Durante cada multiplicación, el sistema:

1. Multiplica cada dígito por el multiplicador.
2. Calcula el acarreo.
3. Almacena el dígito resultante.
4. Propaga el acarreo restante.
5. Comprueba que no se exceda la capacidad del arreglo.

Este método permite calcular factoriales sin depender del límite numérico de los tipos enteros convencionales.

Especificaciones técnicas

Característica| Valor
Lenguaje| C
Estándar| C11
Entrada máxima| 1000
Capacidad interna| 3000 dígitos decimales
Representación numérica| Arreglo de dígitos
Operaciones disponibles| Factorial individual y series

Complejidad algorítmica

El cálculo utiliza multiplicaciones sucesivas y trabaja sobre una representación decimal cuyo tamaño aumenta conforme crece el factorial.

- Tiempo aproximado: O(n² log n), considerando el crecimiento de los dígitos y las multiplicaciones sucesivas.
- Espacio para el resultado: O(n log n) dígitos en términos de n.

Casos de prueba recomendados

Entrada| Resultado esperado
0| 1
1| 1
5| 120
10| 3628800
20| 2432902008176640000
100| Resultado exacto de 158 dígitos
-5| Error de validación
1001| Error de rango

Mejoras futuras

- Implementación de pruebas automatizadas.
- Uso de memoria dinámica para admitir resultados mayores.
- Optimización de las operaciones aritméticas.
- Exportación de resultados a CSV o JSON.
- Integración continua con GitHub Actions.
- Incorporación de otras funciones matemáticas.
- Pruebas de rendimiento y documentación técnica ampliada.

Licencia

Este proyecto puede distribuirse bajo la licencia MIT si se incluye el archivo correspondiente y se cumplen sus condiciones.

Autor

Proyecto de portafolio enfocado en programación en C, algoritmos matemáticos, aritmética de precisión arbitraria y desarrollo de aplicaciones de consola.
