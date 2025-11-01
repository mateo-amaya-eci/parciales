#include "Estudiante.h"
#include <sstream>
#include <iostream>

Estudiante::Estudiante(const std::string& nombre, int programa, float promedio, int creditosAprobados)
    : nombre(nombre), programa(programa), promedio(promedio), creditosAprobados(creditosAprobados) {}

void Estudiante::registrarNota(float nota, int creditos){
    float nuevoPromedio= (promedio* creditosAprobados + nota* creditos) /(creditosAprobados + creditos);
    promedio= nuevoPromedio;
    agregarCreditos(creditos);
}
void Estudiante:: agregarCreditos(int creditos){
    creditosAprobados += creditos;
}

std::string Estudiante:: obtenerResumen(){
    std::ostringstream ss;
    ss << "Nombre: " << nombre << "\nPrograma: " << programa<< "\nPromedio: " << promedio << "\nCreditos Aprobados: " << creditosAprobados;
    return ss.str();
}

bool Estudiante:: cumpleRequisitosGrado(int creditosRequeridos){
    return creditosAprobados >= creditosRequeridos ;
}