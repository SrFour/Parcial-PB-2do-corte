#include <iostream>
#include <string>
using namespace std;

struct Usuario
{
    int idUsuario;
    string nombre;
    string correoElectronico;
    string contrasena;
    string direccion;
    string metodoDePago;		
};

struct Producto
{
    int idProducto;
    string nombre;
    string descripcion;
    double precio;
    int stock;
};

struct CarritoDeCompras
{
    int idCarrito;
    Usuario usuario;
    Producto productos[50];
    double subtotal;
    double impuestos;	
};

struct OrdenDeCompra
{
    int idOrden;
    Producto productos[50];
    double subtotal;
    double impuestos;
    double envio;
    double total;	
};

struct Categoria
{
    int idCategoria;
    string nombre;	
};

struct Comentario
{
    int idComentario;
    string producto;
    string usuario;
    string comentario;
    string fecha;
};

void inicializar(Usuario u[5], Producto p[50], Comentario c[50]);
int  iniciarSesion(Usuario u[5]);
void listarProductos(Producto p[50]);
void mostrarComentarios(Comentario c[50]);
void listarUsuarios(Usuario u[5]);
void carritoCompras(Producto p[50]);
void mostrarCarrito();

int main()
{
    cout << "Bienvenido a Tecnonline" << endl;

    int opc;
    do {
        cout << "\n----- MENU PRINCIPAL -----\n";
        cout << "1. Iniciar sesion\n";
        cout << "2. Salir\n";
        cout << "Opcion: ";
        cin >> opc;

        switch(opc)
        {
            case 1:
                cout << "Función de inicio de sesión aún no implementada.\n";
                break;
            case 2:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }

    } while(opc != 2);

    return 0;
}

