#include <iostream>
#include <string>

using namespace std;

class SesionUsuario 
{
private:
    string nombreUsuario;
    int tiempoLimiteSegundos;
    bool activa;

    void cerrarSesion() 
    {
        activa = false;
    }

public:
    SesionUsuario() 
    {
        nombreUsuario = "invitado";
        tiempoLimiteSegundos = 300;
        activa = true;
    }

    explicit SesionUsuario(const string& nombre) 
    {
        nombreUsuario = nombre;
        tiempoLimiteSegundos = 600;
        activa = true;
    }

    SesionUsuario(const string& nombre, int tiempo) 
    {
        nombreUsuario = nombre;
        if (tiempo > 0) 
        {
            tiempoLimiteSegundos = tiempo;
        }
        else
        {
            tiempoLimiteSegundos = 60;
        }
        activa = true;
    }

    ~SesionUsuario() 
    {
        if (activa) 
        {
            cerrarSesion();

            cout << "[AUDITORIA] La sesion de '" << nombreUsuario << "' se ha cerrado automaticamente al salir de ambito." << endl;
        }
    }

    string obtenerNombreUsuario() const 
    {
        return nombreUsuario;
    }

    bool estaActiva() const 
    {
        return activa;
    }

    void ampliarTiempo(int segundos) 
    {
        if (segundos > 0)
        {
            tiempoLimiteSegundos += segundos;
        }
    }
};

void realizarOperacion() 
{
    SesionUsuario sesionOperacion("anna");

    cout << "Operacion en curso para " << sesionOperacion.obtenerNombreUsuario() << endl;
}

int main() 
{
    SesionUsuario sesionInvitado;
    
    cout << "Usuario: " << sesionInvitado.obtenerNombreUsuario() << " | Activa: " << sesionInvitado.estaActiva() << endl;

    {
        SesionUsuario sesionBloque("marc", 0);

        sesionBloque.ampliarTiempo(120);
        sesionBloque.ampliarTiempo(-5);

        cout << "Dentro del bloque: " << sesionBloque.obtenerNombreUsuario() << endl;
    }

    realizarOperacion();

    return 0;
}