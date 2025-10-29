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

	CarritoDeCompras carrito; // Carrito global del usuario actual
	int cantidadProductosCarrito = 0; // Cuántos productos ha agregado

void inicializar(Usuario u[5], Producto p[50], Comentario c[50]);
int  iniciarSesion(Usuario u[5]);
void listarProductos(Producto p[50]); // Productos por debajo de 15 unidades en stock
void mostrarComentarios(Comentario c[50]);
void listarUsuarios(Usuario u[50]); // Mostrar usuarios
void carritoCompras(Producto p[50]); // Adicionar productos
void mostrarCarrito(); 

int main()
{
	setlocale(LC_ALL, "spanish");
	
	Usuario usuarios [5];
	Producto productos [50];
	Comentario comentarios[50];

	inicializar(usuarios, productos, comentarios);
	
	carrito.subtotal = 0;
	carrito.impuestos = 0;
	cantidadProductosCarrito = 0;
	
		cout<<" Bienvenido a Tecnonline"<<endl;
		
			if(iniciarSesion(usuarios) == 1)
			{
				int opc = 0;
				
				do{
				
					system("pause");
					system("cls");
					
					cout<<"\n -----  PORTAL DE USUARIOS  -----"<<endl;
					cout<<"\n\t1. Listar Productos"<<endl;
					cout<<"\t2. Comentarios"<<endl;
					cout<<"\t3. Listar Usuarios"<<endl;
					cout<<"\t4. Ir al carrito"<<endl;
					cout<<"\t5. Ver carrito"<<endl;
					cout<<"\t6. Salir"<<endl;
					cout<<"\n\tOpcion: "; cin>>opc;
				
					switch(opc)
					{
						case 1: system("pause"); system("cls");
								listarProductos(productos);
								break;
						
						case 2: system("pause"); system("cls");
								mostrarComentarios(comentarios);
								break;
						
						case 3: system("pause"); system("cls");
								listarUsuarios(usuarios);
								break;
								
						case 4: system("pause"); system("cls");
								carritoCompras(productos);
								break;
						
						case 5: system("pause"); system("cls");
								mostrarCarrito();
								break;
								
						case 6: system("pause"); system("cls");
								cout<<"Saliendo del portal..."<<endl;
								system("pause"); system("cls");
								break;
						
						default: system("pause"); system("cls");
								 cout<<"Opcion invalida. Intente de nuevo."<<endl;
					}
					
				}while(opc != 6);
			}

	
	system("pause");
	return 0;
}

void inicializar(Usuario u[5], Producto p[50], Comentario c[50])
{
	setlocale(LC_ALL, "spanish");
	
	Usuario tempUsuarios [5] = {
	
		{1, "Juan Perez", "juan.perez@email.com", "Qwerty123", "Carrera 45 #10-20", "Tarjeta de credito"},
		{2, "Ana Gómez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"},
		{3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"},
		{4, "Sofía Martínez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"},
		{5, "Diego Fernández", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta débito"}	
	};
	
		for(int i = 0; i < 5; i++)
		{
			u[i] = tempUsuarios[i];
		}
	
	Producto tempProductos [50] = {
		
		{1, "Laptop", "Portátil con pantalla Full HD y SSD de 512GB", 89999, 10},	
		{2, "Smartphone", "Teléfono con cámara de 108MP y carga rápida", 49950, 20},
		{3, "Tablet", "Dispositivo con pantalla táctil de 10 pulgadas", 29999, 15},
		{4, "Auriculares", "Audífonos inalámbricos con cancelación de ruido", 12999, 25},
		{5, "Teclado", "Teclado mecánico con iluminación RGB", 8999, 30},
		{6, "Mouse", "Ratón inalámbrico con sensor óptico de alta precisión", 5999, 50},
		{7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12},
		{8, "Impresora", "Láser multifuncional con Wi-Fi", 17999, 18},
		{9, "Cámara", "Cámara digital con lente profesional", 79999, 8},
		{10, "Smartwatch", "Reloj inteligente con GPS y monitoreo cardíaco", 19999, 22},
		{11, "Silla Gamer", "Silla ergonómica ajustable con soporte lumbar", 29999, 14},
		{12, "Microondas", "Horno microondas con múltiples funciones", 12999, 40},
		{13, "Refrigerador", "Frigorífico doble puerta con sistema No Frost", 119999, 5},
		{14, "Lavadora", "Lavadora automática con capacidad de 10kg", 59999, 7},
		{15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35},
		{16, "Drone", "Drone con cámara 4K y estabilizador", 69999, 9},
		{17, "Bocina Bluetooth", "Altavoz portátil con sonido envolvente", 8999, 33},
		{18, "Videocámara", "Videocámara profesional con grabación en 4K", 99999, 6},
		{19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11},
		{20, "Batería Externa", "Batería de 20000mAh con carga rápida", 3999, 45},
		{21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28},
		{22, "Memoria USB", "Pendrive de 128GB", 2999, 60},
		{23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16},
		{24, "Joystick", "Control inalámbrico para videojuegos", 7999, 20},
		{25, "Fuente de Poder", "Fuente de alimentación para PC de 750W", 8999, 17},
		{26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32},
		{27, "Altavoces", "Par de bocinas estéreo con subwoofer", 13999, 23},
		{28, "Webcam", "Cámara web Full HD con micrófono integrado", 6999, 37},
		{29, "Procesador", "CPU Intel i7 de última generación", 34999, 9},
		{30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13},
		{31, "Memoria RAM", "Módulo de RAM DDR4 de 16GB", 7999, 41},
		{32, "Fuente Solar", "Panel solar portátil con batería integrada", 24999, 4},
		{33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50},
		{34, "Termostato", "Termostato digital programable", 9999, 22},
		{35, "Smart Lock", "Cerradura electrónica con huella digital", 19999, 6},
		{36, "Proyector", "Proyector LED con resolución Full HD", 29999, 12},
		{37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38},
		{38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26},
		{39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55},
		{40, "Estabilizador", "Estabilizador de voltaje para dispositivos electrónicos", 15999, 10},
		{41, "Cargador Inalámbrico", "Base de carga inalámbrica rápida", 4999, 30},
		{42, "HDD Externo", "Disco duro portátil de 4TB", 17999, 15},
		{43, "Micrófono", "Micrófono profesional para grabación", 14999, 7},
		{44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20},
		{45, "Antena Wi-Fi", "Amplificador de señal inalámbrico", 7999, 33},
		{46, "Climatizador", "Aire acondicionado portátil con control remoto", 29999, 5},
		{47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19},
		{48, "Capturadora", "Placa de captura de video en alta resolución", 19999, 8},
		{49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42},
		{50, "Timbre Inteligente", "Timbre con cámara y conexión a Wi-Fi", 14999, 10}
	};
	
		for(int i = 0; i < 50; i++)
		{
			p[i] = tempProductos[i];
		}
	
	Comentario tempComentarios[50] = {
	
		 {1, "Laptop", "Juan Pérez", "Excelente rendimiento; muy rápida. ¡Me encanta!", "01/05/2025"},
         {2, "Smartphone", "Ana Gómez", "Buena cámara pero la batería dura poco.", "03/05/2025"},
         {3, "Tablet", "Carlos Ruiz", "No me gustó; pantalla de baja calidad.", "05/05/2025"},
         {4, "Auriculares", "Sofía Martínez", "Sonido aceptable pero el material parece frágil.", "06/05/2025"},
         {5, "Teclado", "Diego Fernández", "Muy buen teclado mecánico; excelente respuesta.", "08/05/2025"},
         {6, "Mouse", "Ana Gómez", "El sensor no es tan preciso como esperaba.", "10/05/2025"},
         {7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resolución. Muy satisfecho.", "12/05/2025"},
         {8, "Impresora", "Juan Pérez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"},
         {9, "Cámara", "Sofía Martínez", "Increíble calidad de imagen; fotos súper nítidas.", "15/05/2025"},
         {10, "Smartwatch", "Diego Fernández", "Buena batería; pero la pantalla no es muy brillante.", "18/05/2025"},
         {11, "Silla Gamer", "Lucía Rodríguez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"},
         {12, "Microondas", "Andrés Ramírez", "Calienta bien pero hace mucho ruido.", "22/05/2025"},
         {13, "Refrigerador", "María García", "Espacioso y enfría rápido; muy recomendado.", "24/05/2025"},
         {14, "Lavadora", "Javier Martínez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"},
         {15, "Cafetera", "Carolina López", "Hace café delicioso; fácil de usar.", "28/05/2025"},
         {16, "Drone", "Daniel Castro", "Muy divertido pero la batería dura poco.", "30/05/2025"},
         {17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexión Bluetooth.", "01/06/2025"},
         {18, "Videocámara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "03/06/2025"},
         {19, "TV LED", "Fernanda Sánchez", "Imagen excelente pero el sonido podría mejorar.", "05/06/2025"},
         {20, "Batería Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "07/06/2025"},
         {21, "Disco Duro", "Gabriela Suárez", "Gran capacidad de almacenamiento; funciona rápido.", "09/06/2025"},
         {22, "Memoria USB", "Raúl Espinosa", "Buen tamaño pero la velocidad de transferencia es baja.", "11/06/2025"},
         {23, "Router", "Verónica Mendoza", "Señal potente; cubre toda la casa.", "13/06/2025"},
         {24, "Joystick", "Fabio Jiménez", "Comodo y resistente; ideal para gaming.", "15/06/2025"},
         {25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"},
         {26, "SSD", "Silvia Gómez", "Velocidad increíble; mi PC va mucho más rápido ahora.", "19/06/2025"},
         {27, "Altavoces", "Martín Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"},
         {28, "Webcam", "Valentina Pérez", "Imagen clara pero el micrófono es deficiente.", "23/06/2025"},
         {29, "Procesador", "José Ramírez", "Rendimiento impecable; ideal para gaming y diseño.", "25/06/2025"},
         {30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalación fue complicada.", "27/06/2025"},
         {31, "Memoria RAM", "Julio Fernández", "Expande muy bien el rendimiento del sistema.", "29/06/2025"},
         {32, "Fuente Solar", "Amanda Castro", "Energía confiable pero la batería es pequeña.", "01/07/2025"},
         {33, "Control Remoto", "Pedro Duarte", "Fácil de usar; reconoce muchos dispositivos.", "03/07/2025"},
         {34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "05/07/2025"},
         {35, "Smart Lock", "Oscar Rodríguez", "Seguridad y tecnología en un solo dispositivo.", "07/07/2025"},
         {36, "Proyector", "Cristina Vargas", "Imagen nítida pero requiere una sala oscura.", "09/07/2025"},
         {37, "Switch Ethernet", "Mario Hernández", "Buena velocidad de conexión; estable.", "11/07/2025"},
         {38, "Reloj Digital", "Sofía Ramírez", "Pantalla atractiva pero la batería dura poco.", "13/07/2025"},
         {39, "Luces LED", "Andrea Gutiérrez", "Buenas opciones de colores; buen diseño.", "15/07/2025"},
         {40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"},
         {41, "Cargador Inalámbrico", "Patricia López", "Carga rápido pero requiere posicionamiento preciso.", "19/07/2025"},
         {42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"},
         {43, "Micrófono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"},
         {44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; útil en casa.", "25/07/2025"},
         {45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la señal pero el rango es limitado.", "27/07/2025"},
         {46, "Climatizador", "Estefanía Carrillo", "Enfría rápido pero es algo ruidoso.", "29/07/2025"},
         {47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electrónicos y programación.", "31/07/2025"},
         {48, "Capturadora", "Luisa Mejía", "Ideal para streaming y grabaciones en alta calidad.", "02/08/2025"},
         {49, "Smart Plug", "Victoria Torres", "Muy práctico; fácil de conectar y configurar.", "04/08/2025"},
         {50, "Timbre Inteligente", "Federico Montoya", "Buena cámara; útil para seguridad.", "06/08/2025"}
	
	}; 
	
		for(int i = 0; i < 50; i++)
		{
			c[i] = tempComentarios[i];
		}
}

int iniciarSesion(Usuario u[5])
{
	setlocale(LC_ALL, "spanish");
	
	string nombre;
	string contrasena;
	int aux = 0;
	
	do{
	
	cout<<"\n -----  INICIO DE SESION  -----\n"<<endl;
	cout<<"\nIngrese su nombre de usuario: ";
	fflush(stdin); getline(cin, nombre);
	cout<<"Ingrese su contraseña: ";
	fflush(stdin); getline(cin, contrasena);
	
		for(int i = 0; i < 5; i++)
		{
			if(nombre == u[i].nombre && contrasena == u[i].contrasena)
			{
					cout<<"Inicio de sesion exitoso."<<endl; aux = 1;
					return 1;
			}
		}
	
		if(aux == 0)
		{
			cout<<"Usuario y/o contraseña invalidos. Por favor intente de nuevo."<<endl;
			
			system("pause");
			system("cls");
		}
	
	}while(aux == 0);
	
}

void listarProductos(Producto p[50])
{
	int x = 0;
	
	cout<<"\n -----  LISTA DE PRODUCTOS  -----\n"<<endl;
	
	for(int i = 0; i < 50; i++)
	{
		if(p[i].stock < 15)
		{
			cout<<"ID "<<p[i].idProducto<<" - "<<p[i].nombre 
			     <<" --- "<<p[i].stock<<" unidades."<<endl;
		}
	}
}



void mostrarComentarios(Comentario c[50])
{
    string fechaFiltro;
    int diaFiltro, mesFiltro, anioFiltro;

    cout<<"----- FILTRAR COMENTARIOS POR FECHA -----"<<endl;
    cout<<"Ingrese una fecha (dd/mm/yyyy): ";
    fflush(stdin); getline(cin, fechaFiltro);

    diaFiltro = stoi(fechaFiltro.substr(0, 2));
    mesFiltro = stoi(fechaFiltro.substr(3, 2));
    anioFiltro = stoi(fechaFiltro.substr(6, 4));

    cout<<"\n----- COMENTARIOS DESDE "<<fechaFiltro<<" -----\n";

    for(int i = 0; i < 50; i++)
    {
        int dia = stoi(c[i].fecha.substr(0, 2));
        int mes = stoi(c[i].fecha.substr(3, 2));
        int anio = stoi(c[i].fecha.substr(6, 4));
        
        if (
            (anio > anioFiltro) ||
            (anio == anioFiltro && mes > mesFiltro) ||
            (anio == anioFiltro && mes == mesFiltro && dia >= diaFiltro)
        )
        {
            cout<<"\nProducto: "<< c[i].producto <<endl;
            cout<<"Usuario: "<<c[i].usuario<<endl;
            cout<<"Comentario: "<<c[i].comentario<<endl;
            cout<<"Fecha: "<<c[i].fecha<<endl;
            cout<<"-----------------------------------------"<<endl;
        }
    }
}


void listarUsuarios(Usuario u[5])
{
	setlocale(LC_ALL, "spanish");
	
	cout<<"\n-----  USUARIOS  -----\n"<<endl;
	
	for(int i = 0; i < 5; i++)
	{
		string mayus = u[i].nombre;
				
		for (int j = 0; j < mayus.size(); j++)
		{
			mayus[j] = toupper(mayus[j]);
		}

		cout<<mayus<<" --- " <<u[i].correoElectronico<<endl;
	}
	
}

void carritoCompras(Producto p[50])
{
	setlocale(LC_ALL, "spanish");
	
	int id, cantidad;
	int aux;
	int opc;

	do {
		cout<<"\n ----- AGREGAR PRODUCTO AL CARRITO -----\n"<<endl;
		cout<<"\nIngrese el ID del producto: ";
		cin>>id;

		aux = 0;

		for (int i = 0; i < 50; i++)
		{
			if (p[i].idProducto == id)
			{
				aux = 1;
				cout<<"Producto: "<<p[i].nombre<<endl;
				cout<<"Precio: $"<<p[i].precio<<endl;
				cout<<"Stock disponible: "<<p[i].stock<<endl;
				cout<<"Cantidad a comprar: ";
				cin>>cantidad;

				if (cantidad <= p[i].stock && cantidad > 0)
				{
					carrito.productos[cantidadProductosCarrito] = p[i];
					carrito.productos[cantidadProductosCarrito].stock = cantidad; // stock = cantidad comprada
					carrito.subtotal += p[i].precio * cantidad;
					p[i].stock -= cantidad; // Descontar stock real
					cantidadProductosCarrito++;

					cout<<"Producto agregado correctamente al carrito."<<endl;
				}
				else
				{
					cout<<"Cantidad no válida o insuficiente en stock."<<endl;
				}
				break;
			}
		}

		if (aux == 0)
			{
				cout << "No se encontró un producto con ese ID." << endl;
			}
		
		system("pause"); system("cls");
		
		cout << "\n¿Desea agregar otro producto? \n\n1. Si\n2. No\n\nOpcion: ";
		cin>>opc;
		system("cls");

	}while (opc == 1);

	carrito.impuestos = carrito.subtotal * 0.19; // 19% de IVA
	
}

void mostrarCarrito()
{
	setlocale(LC_ALL, "spanish");
	
	cout<<"\n----- CARRITO DE COMPRAS -----\n"<<endl;

	if (cantidadProductosCarrito == 0)
	{
		cout<<"El carrito está vacío." <<endl;
		return;
	}

	for (int i = 0; i < cantidadProductosCarrito; i++)
	{
		cout<<i + 1<<". "<<carrito.productos[i].nombre
		     <<" x"<<carrito.productos[i].stock
		     <<" - $"<<carrito.productos[i].precio * carrito.productos[i].stock<<endl;
	}

	cout<<"\nSubtotal: $"<<carrito.subtotal<<endl;
	cout<<"Impuestos (19%): $" << carrito.impuestos<<endl;
	cout<<"Total: $"<<carrito.subtotal + carrito.impuestos<<endl;
}
