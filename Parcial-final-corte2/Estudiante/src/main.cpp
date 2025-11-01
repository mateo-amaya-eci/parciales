#include <iostream>
#include <vector>
#include <fstream>
#include "Estudiante.h"

int main() {
    std::vector<Estudiante> estudiantes;

    char opcionInicial;
    std::cout << "\n========= BIENVENIDO AL PROGRAMA DE NOTA DE LOS ESTUDIANTES =========\n";
    std::cout << "¿Desea usar los estudiantes predefinidos o agregar nuevos estudiantes? (p/a): ";
    std::cin >> opcionInicial;

    if (opcionInicial == 'p' || opcionInicial == 'P') {
        // Estudiantes predefinidos
        estudiantes.push_back(Estudiante("Mateo Amaya", 101, 0.0f, 0));
        estudiantes.push_back(Estudiante("Paula Gomez", 102, 0.0f, 0));
        estudiantes.push_back(Estudiante("Carlos Garcia", 103, 0.0f, 0));

        estudiantes[0].registrarNota(5.0f, 4);
        estudiantes[0].registrarNota(4.8f, 4);

        estudiantes[1].registrarNota(2.0f, 1);
        estudiantes[1].registrarNota(3.0f, 3);

        estudiantes[2].registrarNota(4.5f, 3);
        estudiantes[2].registrarNota(4.0f, 4);

        std::cout << "Estudiantes predefinidos cargados exitosamente.\n";
    } else if (opcionInicial == 'a' || opcionInicial == 'A') {
        char opcionAgregar;
        do {
            std::string nombre;
            int id;

            std::cout << "Ingrese el nombre del estudiante: ";
            std::cin.ignore(); // Ignorar el salto de línea previo
            std::getline(std::cin, nombre);

            std::cout << "Ingrese el ID del estudiante: ";
            std::cin >> id;

            // Crear el estudiante
            Estudiante nuevoEstudiante(nombre, id, 0.0f, 0);

            // Registrar múltiples notas
            char opcionNota;
            do {
                float nota;
                int creditos;

                std::cout << "Ingrese una nota: ";
                std::cin >> nota;

                std::cout << "Ingrese los créditos de la nota: ";
                std::cin >> creditos;

                nuevoEstudiante.registrarNota(nota, creditos);

                std::cout << "¿Desea agregar otra nota para este estudiante? (s/n): ";
                std::cin >> opcionNota;
            } while (opcionNota == 's' || opcionNota == 'S');

            // Agregar al vector de estudiantes
            estudiantes.push_back(nuevoEstudiante);

            std::cout << "Estudiante agregado exitosamente.\n";
            std::cout << "¿Desea agregar otro estudiante? (s/n): ";
            std::cin >> opcionAgregar;
        } while (opcionAgregar == 's' || opcionAgregar == 'S');
    } else {
        std::cout << "Opción no válida. Saliendo del programa.\n";
        return 0;
    }

    // Mostrar resumen de estudiantes
    std::cout << " ===== Resumen de Estudiantes ===== " << std::endl;
    for (size_t i = 0; i < estudiantes.size(); ++i) {
        std::cout << "\nEstudiante" << std::endl;
        std::cout << estudiantes[i].obtenerResumen() << std::endl;
        std::cout << "Cumple requisitos de grado (3 créditos): "
                  << (estudiantes[i].cumpleRequisitosGrado(3) ? "Sí" : "No") << std::endl;
    }

    // Calcular estadísticas generales
    float sumPromedios = 0.0f;
    for (const auto& estudiante : estudiantes) {
        sumPromedios += estudiante.getPromedio();
    }
    float promedioGeneral = sumPromedios / estudiantes.size();
    std::cout << "\n========= ESTADÍSTICAS GENERALES =========" << std::endl;
    std::cout << "Promedio General de Estudiantes: " << promedioGeneral << std::endl;

    // Generar reporte en archivo
    std::ofstream reporte("reporte_estudiantes.txt");
    if (reporte.is_open()) {
        reporte << " REPORTE DE ESTUDIANTES \n";
        reporte << "=========================\n";
        for (const auto& estudiante : estudiantes) {
            reporte << "Nombre: " << estudiante.getNombre() << "\n";
            reporte << "Promedio: " << estudiante.getPromedio() << "\n";
            reporte << "Créditos: " << estudiante.getCreditosAprobados() << "\n";
            reporte << "------------------------\n";
        }

        reporte << "\nPromedio general: " << promedioGeneral << "\n";
        reporte.close();
        std::cout << "Reporte generado: reporte_estudiantes.txt" << std::endl;
    }

    return 0;
}