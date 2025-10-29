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
	int cantidadProductosCarrito = 0; // Cu�ntos productos ha agregado

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
		{2, "Ana G�mez", "ana.gomez@email.com", "Pass456", "Calle 21 #35-50", "PayPal"},
		{3, "Carlos Ruiz", "carlos.ruiz@email.com", "Segura789", "Avenida Principal #100", "Transferencia bancaria"},
		{4, "Sof�a Mart�nez", "sofia.martinez@email.com", "Clave987", "Calle 8 #20-30", "Efectivo"},
		{5, "Diego Fern�ndez", "diego.fernandez@email.com", "Contra654", "Carrera 77 #40-60", "Tarjeta d�bito"}	
	};
	
		for(int i = 0; i < 5; i++)
		{
			u[i] = tempUsuarios[i];
		}
	
	Producto tempProductos [50] = {
		
		{1, "Laptop", "Port�til con pantalla Full HD y SSD de 512GB", 89999, 10},	
		{2, "Smartphone", "Tel�fono con c�mara de 108MP y carga r�pida", 49950, 20},
		{3, "Tablet", "Dispositivo con pantalla t�ctil de 10 pulgadas", 29999, 15},
		{4, "Auriculares", "Aud�fonos inal�mbricos con cancelaci�n de ruido", 12999, 25},
		{5, "Teclado", "Teclado mec�nico con iluminaci�n RGB", 8999, 30},
		{6, "Mouse", "Rat�n inal�mbrico con sensor �ptico de alta precisi�n", 5999, 50},
		{7, "Monitor", "Pantalla LED 4K de 27 pulgadas", 49900, 12},
		{8, "Impresora", "L�ser multifuncional con Wi-Fi", 17999, 18},
		{9, "C�mara", "C�mara digital con lente profesional", 79999, 8},
		{10, "Smartwatch", "Reloj inteligente con GPS y monitoreo card�aco", 19999, 22},
		{11, "Silla Gamer", "Silla ergon�mica ajustable con soporte lumbar", 29999, 14},
		{12, "Microondas", "Horno microondas con m�ltiples funciones", 12999, 40},
		{13, "Refrigerador", "Frigor�fico doble puerta con sistema No Frost", 119999, 5},
		{14, "Lavadora", "Lavadora autom�tica con capacidad de 10kg", 59999, 7},
		{15, "Cafetera", "Cafetera express con vaporizador de leche", 14999, 35},
		{16, "Drone", "Drone con c�mara 4K y estabilizador", 69999, 9},
		{17, "Bocina Bluetooth", "Altavoz port�til con sonido envolvente", 8999, 33},
		{18, "Videoc�mara", "Videoc�mara profesional con grabaci�n en 4K", 99999, 6},
		{19, "TV LED", "Televisor inteligente de 55 pulgadas con HDR", 74999, 11},
		{20, "Bater�a Externa", "Bater�a de 20000mAh con carga r�pida", 3999, 45},
		{21, "Disco Duro", "Disco duro externo de 2TB", 12999, 28},
		{22, "Memoria USB", "Pendrive de 128GB", 2999, 60},
		{23, "Router", "Router Wi-Fi 6 de alta velocidad", 19999, 16},
		{24, "Joystick", "Control inal�mbrico para videojuegos", 7999, 20},
		{25, "Fuente de Poder", "Fuente de alimentaci�n para PC de 750W", 8999, 17},
		{26, "SSD", "Unidad de almacenamiento SSD de 1TB", 14999, 32},
		{27, "Altavoces", "Par de bocinas est�reo con subwoofer", 13999, 23},
		{28, "Webcam", "C�mara web Full HD con micr�fono integrado", 6999, 37},
		{29, "Procesador", "CPU Intel i7 de �ltima generaci�n", 34999, 9},
		{30, "Motherboard", "Placa base compatible con procesadores modernos", 19999, 13},
		{31, "Memoria RAM", "M�dulo de RAM DDR4 de 16GB", 7999, 41},
		{32, "Fuente Solar", "Panel solar port�til con bater�a integrada", 24999, 4},
		{33, "Control Remoto", "Mando universal para TV y dispositivos", 2499, 50},
		{34, "Termostato", "Termostato digital programable", 9999, 22},
		{35, "Smart Lock", "Cerradura electr�nica con huella digital", 19999, 6},
		{36, "Proyector", "Proyector LED con resoluci�n Full HD", 29999, 12},
		{37, "Switch Ethernet", "Switch de red de 8 puertos", 5999, 38},
		{38, "Reloj Digital", "Reloj inteligente con pantalla AMOLED", 8999, 26},
		{39, "Luces LED", "Tiras LED RGB con control remoto", 3999, 55},
		{40, "Estabilizador", "Estabilizador de voltaje para dispositivos electr�nicos", 15999, 10},
		{41, "Cargador Inal�mbrico", "Base de carga inal�mbrica r�pida", 4999, 30},
		{42, "HDD Externo", "Disco duro port�til de 4TB", 17999, 15},
		{43, "Micr�fono", "Micr�fono profesional para grabaci�n", 14999, 7},
		{44, "Altavoz Inteligente", "Asistente de voz con altavoz integrado", 12999, 20},
		{45, "Antena Wi-Fi", "Amplificador de se�al inal�mbrico", 7999, 33},
		{46, "Climatizador", "Aire acondicionado port�til con control remoto", 29999, 5},
		{47, "Raspberry Pi", "Kit de desarrollo con Raspberry Pi 4", 12999, 19},
		{48, "Capturadora", "Placa de captura de video en alta resoluci�n", 19999, 8},
		{49, "Smart Plug", "Enchufe inteligente compatible con asistentes virtuales", 3999, 42},
		{50, "Timbre Inteligente", "Timbre con c�mara y conexi�n a Wi-Fi", 14999, 10}
	};
	
		for(int i = 0; i < 50; i++)
		{
			p[i] = tempProductos[i];
		}
	
	Comentario tempComentarios[50] = {
	
		 {1, "Laptop", "Juan P�rez", "Excelente rendimiento; muy r�pida. �Me encanta!", "01/05/2025"},
         {2, "Smartphone", "Ana G�mez", "Buena c�mara pero la bater�a dura poco.", "03/05/2025"},
         {3, "Tablet", "Carlos Ruiz", "No me gust�; pantalla de baja calidad.", "05/05/2025"},
         {4, "Auriculares", "Sof�a Mart�nez", "Sonido aceptable pero el material parece fr�gil.", "06/05/2025"},
         {5, "Teclado", "Diego Fern�ndez", "Muy buen teclado mec�nico; excelente respuesta.", "08/05/2025"},
         {6, "Mouse", "Ana G�mez", "El sensor no es tan preciso como esperaba.", "10/05/2025"},
         {7, "Monitor", "Carlos Ruiz", "Colores vibrantes y buena resoluci�n. Muy satisfecho.", "12/05/2025"},
         {8, "Impresora", "Juan P�rez", "Tarda mucho en imprimir; no me convence.", "13/05/2025"},
         {9, "C�mara", "Sof�a Mart�nez", "Incre�ble calidad de imagen; fotos s�per n�tidas.", "15/05/2025"},
         {10, "Smartwatch", "Diego Fern�ndez", "Buena bater�a; pero la pantalla no es muy brillante.", "18/05/2025"},
         {11, "Silla Gamer", "Luc�a Rodr�guez", "Comodidad espectacular; perfecto para largas sesiones de juego.", "20/05/2025"},
         {12, "Microondas", "Andr�s Ram�rez", "Calienta bien pero hace mucho ruido.", "22/05/2025"},
         {13, "Refrigerador", "Mar�a Garc�a", "Espacioso y enfr�a r�pido; muy recomendado.", "24/05/2025"},
         {14, "Lavadora", "Javier Mart�nez", "Lava bien pero el ciclo es muy largo.", "26/05/2025"},
         {15, "Cafetera", "Carolina L�pez", "Hace caf� delicioso; f�cil de usar.", "28/05/2025"},
         {16, "Drone", "Daniel Castro", "Muy divertido pero la bater�a dura poco.", "30/05/2025"},
         {17, "Bocina Bluetooth", "Paola Herrera", "Sonido potente y buena conexi�n Bluetooth.", "01/06/2025"},
         {18, "Videoc�mara", "Esteban Rojas", "Perfecta para grabaciones profesionales.", "03/06/2025"},
         {19, "TV LED", "Fernanda S�nchez", "Imagen excelente pero el sonido podr�a mejorar.", "05/06/2025"},
         {20, "Bater�a Externa", "Camilo Torres", "Carga bien pero es un poco pesada.", "07/06/2025"},
         {21, "Disco Duro", "Gabriela Su�rez", "Gran capacidad de almacenamiento; funciona r�pido.", "09/06/2025"},
         {22, "Memoria USB", "Ra�l Espinosa", "Buen tama�o pero la velocidad de transferencia es baja.", "11/06/2025"},
         {23, "Router", "Ver�nica Mendoza", "Se�al potente; cubre toda la casa.", "13/06/2025"},
         {24, "Joystick", "Fabio Jim�nez", "Comodo y resistente; ideal para gaming.", "15/06/2025"},
         {25, "Fuente de Poder", "Ricardo Vargas", "Funciona bien pero los cables son muy cortos.", "17/06/2025"},
         {26, "SSD", "Silvia G�mez", "Velocidad incre�ble; mi PC va mucho m�s r�pido ahora.", "19/06/2025"},
         {27, "Altavoces", "Mart�n Aguilar", "Sonido envolvente; muy buena compra.", "21/06/2025"},
         {28, "Webcam", "Valentina P�rez", "Imagen clara pero el micr�fono es deficiente.", "23/06/2025"},
         {29, "Procesador", "Jos� Ram�rez", "Rendimiento impecable; ideal para gaming y dise�o.", "25/06/2025"},
         {30, "Motherboard", "Natalia Correa", "Buenas prestaciones pero la instalaci�n fue complicada.", "27/06/2025"},
         {31, "Memoria RAM", "Julio Fern�ndez", "Expande muy bien el rendimiento del sistema.", "29/06/2025"},
         {32, "Fuente Solar", "Amanda Castro", "Energ�a confiable pero la bater�a es peque�a.", "01/07/2025"},
         {33, "Control Remoto", "Pedro Duarte", "F�cil de usar; reconoce muchos dispositivos.", "03/07/2025"},
         {34, "Termostato", "Isabela Medina", "Regula bien la temperatura; intuitivo de usar.", "05/07/2025"},
         {35, "Smart Lock", "Oscar Rodr�guez", "Seguridad y tecnolog�a en un solo dispositivo.", "07/07/2025"},
         {36, "Proyector", "Cristina Vargas", "Imagen n�tida pero requiere una sala oscura.", "09/07/2025"},
         {37, "Switch Ethernet", "Mario Hern�ndez", "Buena velocidad de conexi�n; estable.", "11/07/2025"},
         {38, "Reloj Digital", "Sof�a Ram�rez", "Pantalla atractiva pero la bater�a dura poco.", "13/07/2025"},
         {39, "Luces LED", "Andrea Guti�rrez", "Buenas opciones de colores; buen dise�o.", "15/07/2025"},
         {40, "Estabilizador", "Pablo Medina", "Protege bien contra variaciones de voltaje.", "17/07/2025"},
         {41, "Cargador Inal�mbrico", "Patricia L�pez", "Carga r�pido pero requiere posicionamiento preciso.", "19/07/2025"},
         {42, "HDD Externo", "Gonzalo Espinoza", "Mucho espacio; resistente y confiable.", "21/07/2025"},
         {43, "Micr�fono", "Elena Herrera", "Calidad de sonido profesional; ideal para podcast.", "23/07/2025"},
         {44, "Altavoz Inteligente", "Diego Soto", "Responde bien a comandos de voz; �til en casa.", "25/07/2025"},
         {45, "Antena Wi-Fi", "Miguel Rojas", "Amplifica bien la se�al pero el rango es limitado.", "27/07/2025"},
         {46, "Climatizador", "Estefan�a Carrillo", "Enfr�a r�pido pero es algo ruidoso.", "29/07/2025"},
         {47, "Raspberry Pi", "Manuel Vargas", "Perfecto para proyectos electr�nicos y programaci�n.", "31/07/2025"},
         {48, "Capturadora", "Luisa Mej�a", "Ideal para streaming y grabaciones en alta calidad.", "02/08/2025"},
         {49, "Smart Plug", "Victoria Torres", "Muy pr�ctico; f�cil de conectar y configurar.", "04/08/2025"},
         {50, "Timbre Inteligente", "Federico Montoya", "Buena c�mara; �til para seguridad.", "06/08/2025"}
	
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
	cout<<"Ingrese su contrase�a: ";
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
			cout<<"Usuario y/o contrase�a invalidos. Por favor intente de nuevo."<<endl;
			
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
					cout<<"Cantidad no v�lida o insuficiente en stock."<<endl;
				}
				break;
			}
		}

		if (aux == 0)
			{
				cout << "No se encontr� un producto con ese ID." << endl;
			}
		
		system("pause"); system("cls");
		
		cout << "\n�Desea agregar otro producto? \n\n1. Si\n2. No\n\nOpcion: ";
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
		cout<<"El carrito est� vac�o." <<endl;
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
