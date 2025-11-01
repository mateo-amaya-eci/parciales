# EJERCICIO PUNTO 4 PARCIAL FINAL CORTE 2 
#### MATEO AMAYA : 1000107917 , INGENIERIA ELECTRONICA
#### PAULA MORALES : 1000108197 , INGENIERIA ELECTRONICA

Escriba el enlace del repositorio de la solución para el cuarto punto del parcial en este entregable o suba un archivo donde se encuentre dicho enlace.
Tenga en cuenta que los enunciados de los ejercicios 3 y 4 son los siguientes:

> **TERCER PUNTO**
Diseñe una clase de C++: 

1. Diseñe desde cero una clase llamada **Estudiante** que contenga: 

    1. Un atributo privado nombre (tipo std::string) 

    2. Un atributo privado programa(tipo int) 

    3. Un atributo privado promedio (tipo float) 

    4. Un atributo privado creditosAprobados (tipo int)  

2. Incluya: 

    1. Como mínimo un constructor que reciba todos los atributos. 

    2. Un método void registrarNota(float nota, int creditos) que actualice el promedio ponderado con base en los nuevos créditos. 

    3. Un método void agregarCreditos(int creditos) que incremente el número total de créditos aprobados. 

    4. Un método std::string obtenerResumen() que devuelva una descripción general del estudiante.

    5. Un metodo bool cumpleRequisitosGrado(int creditosRequeridos), devuelve true si el estudiante ha aprobado un número de créditos igual o superior al requerido para graduarse.
 
Diseñe solo el archivo.h. La parte de diseño incluye únicamente generar el contenido del archivo .h con la estructura de los atributos y funciones, sin ser necesario colocar detalles de implementación. 

3. Implemente a mano un método de su elección. 

4. Documente los métodos con estilo Doxygen.

> **CUARTO PUNTO**

Implemente en un archivo .cpp los métodos descritos en el archivo .h y desarrolle en otro archivo .cpp una aplicación que haga uso de la clase Estudiante, simulando la gestión de varios registros académicos. 

Para la aplicación tener en cuenta los siguientes criterios y estructura sugerida del programa. 

1. Use contenedores de la STL para almacenar multiples estudiantes. 

2. Simule el registro de notas, actualización de promedios y créditos aprobados. 

3. Permita consultar un resumen general de cada estudiante. 

4. Calcule el promedio general de los estudiantes registrados.

5. BONO: Genere un reporte .txt con el nombre, promedio y total de créditos de cada estudiante. 

5. Organice el proyecto siguiendo las buenas prácticas en cuanto al manejo de folders y archivos auxiliares como CMake y Doxygen. 

Subir la solución completa a un repositorio de github público, el enlace deberá ser consignado en un entregable que estará habilitado en la plataforma Moodle. 