#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;
const char *nombe_archivo = "archivo.dat";
const char *nombe_archivo_temp = "archivo_temp.dat";

struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;
};
 void ingresar_estudiante();
void abrir_estudiante();
 void modificar_estudiante();
 void eliminar_estudiante();
 void mostrar_estudiante_temp();
 //void eliminar_estudiante();
int main (){

int opc=0;
	system("cls");
cout <<"******menu******"<<endl;
cout <<"Ingresar estudiante................1"<<endl;
cout <<"Modificar estudiante...............2"<<endl;
cout <<"Eliminar estudiante................3"<<endl;
cout <<"Mostrar estudiantes................4"<<endl<<endl;
cout<<"digite la opcion que desea realizar:"<<endl;
cin>>opc;

switch(opc)
{
	case 1: ingresar_estudiante();
		break;
	case 2: modificar_estudiante();
		break;
	case 3 : eliminar_estudiante();
			mostrar_estudiante_temp();
		break;
	case 4 : abrir_estudiante();
			system("pause");
			main();
			break;	
}

	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Estudiante estudiante;
	
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		
		do{
			
			if (estudiante.codigo == cod){
			pos = indice;
			}
	
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );

    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);
		system("pause");
	system("cls");
	main ();
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
	
	Estudiante estudiante;
	
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );

    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);

		system("pause");
	system("cls");
	main ();
}


void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);



	}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
		system("pause");
	system("cls");
	main ();
	//buscar_indice();	
//	buscar_codigo();
}
void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	abrir_estudiante();
			system("pause");

	main ();
}
void eliminar_estudiante(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	FILE* archivo_temp = fopen(nombe_archivo_temp, "ab");

	
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
		fflush(stdin);
		

		abrir_estudiante();	
		
	int id=0;
	int ids=0;
		cout << "Ingrese el ID que desea eliminar: ";
    		cin >> id;	
			
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	
	do{	

	if(id == ids){
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	ids= ids+1;
	
	}
	
	
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo_temp );
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		ids= ids+1;
			if(id == ids){
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	ids= ids+1;
	
	}
		
	}while(feof(archivo)==0);
	
	fclose(archivo);	
	fclose(archivo_temp);
	
	
		
				
}
void mostrar_estudiante_temp(){

	FILE* archivo_temp = fopen(nombe_archivo_temp, "rb");
	if(!archivo_temp) {
		archivo_temp = fopen(nombe_archivo_temp, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo_temp );
	cout<<"*************Los nuevos registros son los sigunetes:************"<<endl<<endl;
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<< "NOMBRE"<<" "<<"APELLIDO"<<" "<<"TELEFONO"<<" "<<endl;	
		do{
		//	fread ( &estudiante, sizeof(Estudiante), 1, archivo_temp );
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<" | "<< estudiante.nombre<<" "<<estudiante.apellido<<" "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo_temp );
		registro += 1;	
		} while (feof( archivo_temp ) == 0);
		
    cout<<endl;
    
		fclose(archivo_temp);
		
			remove("archivo.dat");
	rename("archivo_temp.dat","archivo.dat");
	system("pause");
	main ();
	}
	

