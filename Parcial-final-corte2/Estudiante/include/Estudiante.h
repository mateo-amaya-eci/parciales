#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>

class Estudiante {
    private:
        std::string nombre;
        int programa;
        float promedio;
        int creditosAprobados;
    public:
        Estudiante(const std::string& nombre, int programa, float promedio, int creditosAprobados);
        void registrarNota(float nota, int creditos);
        void agregarCreditos(int creditos);
        std::string obtenerResumen() ;
        bool cumpleRequisitosGrado(int creditosRequeridos);

        std::string getNombre() const{return nombre;}
        float getPromedio() const{return promedio;}
        int getCreditosAprobados() const{return creditosAprobados;}
};

#endif 