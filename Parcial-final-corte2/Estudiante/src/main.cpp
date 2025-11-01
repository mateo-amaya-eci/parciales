#include <iostream>
#include <vector>
#include <fstream>
#include "Estudiante.h"

int main() {
    std::vector<Estudiante> estudiantes;

    estudiantes.push_back(Estudiante("Mateo Amaya", 101, 0.0f, 0));
    estudiantes.push_back(Estudiante("Paula Gomez", 102, 0.0f, 0));
    estudiantes.push_back(Estudiante("Carlos Garcia", 101, 0.0f, 0));

    estudiantes[0].registrarNota(5.0f,4);
    estudiantes[0].registrarNota(4.8f,4);

    estudiantes[1].registrarNota(2.0f,1);
    estudiantes[1].registrarNota(3.0f,3);

    estudiantes[2].registrarNota(4.5f,3);
    estudiantes[2].registrarNota(4.0f,4);

    char opcion;
    do {
    std::cout << "\n¿Desea agregar un nuevo estudiante? (s/n): ";
        std::cin >> opcion;

        if (opcion == 's' || opcion == 'S') {
            std::string nombre;
            int id;
            float nota;
            int creditos;

            std::cout << "Ingrese el nombre del estudiante: ";
            std::cin.ignore(); // Ignorar el salto de línea previo
            std::getline(std::cin, nombre);

            std::cout << "Ingrese el ID del estudiante: ";
            std::cin >> id;

            std::cout << "Ingrese la primera nota del estudiante: ";
            std::cin >> nota;

            std::cout << "Ingrese los créditos de la primera nota: ";
            std::cin >> creditos;

            // Crear el estudiante y registrar la primera nota
            Estudiante nuevoEstudiante(nombre, id, 0.0f, 0);
            nuevoEstudiante.registrarNota(nota, creditos);

            // Agregar al vector de estudiantes
            estudiantes.push_back(nuevoEstudiante);

            std::cout << "Estudiante agregado exitosamente.\n";
        }
    } while (opcion == 's' || opcion == 'S');

    std::cout << " ===== Resumen de Estudiantes ===== " << std::endl;

    for (size_t i = 0; i < estudiantes.size(); ++i) {
        std::cout << "\n Estudiante" <<std::endl;
        std::cout << estudiantes[i].obtenerResumen() << std::endl;
        std::cout << "cumple requisitos de grado: (120 creditos)"
                    << (estudiantes[i].cumpleRequisitosGrado(120) ? "Si" : "No") << std::endl;  

}

float sumPromedios = 0.0f;
for (const auto& estudiante : estudiantes) {
    sumPromedios += estudiante.getPromedio();
}
float promedioGeneral = sumPromedios / estudiantes.size();
std::cout << "\n ========= ESTADISTICAS GENERALES ======== " << std::endl;
std::cout << "Promedio General de Estudiantes: " << promedioGeneral << std::endl;

std::ofstream reporte("reporte_estudiantes.txt");
if (reporte.is_open()) {
    reporte << " REPORTE DE ESTUDIANTES \n";
    reporte << "=========================\n";
    for (const auto& estudiante : estudiantes) {
            reporte << "Nombre: " << estudiante.getNombre() << "\n";
            reporte << "Promedio: " << estudiante.getPromedio() << "\n";
            reporte << "Creditos: " << estudiante.getCreditosAprobados() << "\n";
            reporte << "------------------------\n";
        }
        
        reporte << "\nPromedio general: " << promedioGeneral << "\n";
        reporte.close();
        std::cout << "Reporte generado: reporte_estudiantes.txt" << std::endl;
    }
return 0;
}