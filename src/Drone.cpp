#include "Drone.hh"

/*!
    \file Drone.cpp
        \brief Definicje metod klasy Drone.

    Zawiera definicje metod klasy Drone.
*/

/*!
    Konstruktor z parametrem obiektu typu Drone. 
    Tworzy nieobroconego drona w podanym punkcie globalnym sceny.
    Nadaje dronowi domyslne ID.  

    \param [in] location - wektor okreslajacy poczatkowe polozenie srodka kadluba drona w ukladzie globalnym sceny. 

    \return Drona o srodku w ukladzie globalnym w punkcie, nieobroconego.        
*/

Drone::Drone(Vector3D const & location, unsigned int ID) : Scene_object(ID, "dron"){
    drone_location = location;
    orientation_angle = 0;
}

/*!
    Metoda zapisuje do pliku, o wygenerowanej automatycznie nazwie, dane o polozeniu wierzcholkow globalnych kadluba- prostopadloscianu, po uprzednim wyliczeniu ich. 
    Zapis odbywa sie w sposob umozliwajacy wyswietlenie wszystkich scian kadluba w Gnuplot.   
*/

void Drone::Calculate_and_save_to_file_fuselage(){
    fuselage.Transform_to_global_coords(drone_location);

    std::ofstream  FileStrm;
    Vector3D P1,P2;
    
    std::string name_of_file = "../datasets/Glb_crd_No_" + std::to_string(get_obj_ID()) + "_fuselage.dat";
    fuselage.update_Name_of_file_global(name_of_file);

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }
    
    P1 = (fuselage[0] + fuselage[7])/2;
    P2 = (fuselage[2] + fuselage[5])/2;

    FileStrm << P1 << std::endl
             << fuselage[6] << std::endl
             << fuselage[4] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;

    FileStrm << P1 << std::endl
             << fuselage[7] << std::endl
             << fuselage[5] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << fuselage[1] << std::endl
             << fuselage[3] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << fuselage[0] << std::endl
             << fuselage[2] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm << P1 << std::endl
             << fuselage[6] << std::endl
             << fuselage[4] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 

    FileStrm.close();
}

/*!
    Metoda zapisuje do pliku, o wygenerowanej automatycznie nazwie, dane o polozeniu wierzcholkow globalnych kamery przedniej- graniostoslupa, po uprzednim wyliczeniu ich. 
    Zapis odbywa sie w sposob umozliwajacy wyswietlenie wszystkich scian graniostoslupa w Gnuplot.   
*/

void Drone::Calculate_and_save_to_file_front_camera(Vector3D const & Trasnlation){
    double camera_scale_scale[3]={CAM_SCALE};
    Vector3D camera_scale(camera_scale_scale);
    front_camera.update_scale(camera_scale);

    front_camera.Transform_to_global_coords(Trasnlation, drone_location, fuselage.get_angle());
    
    std::ofstream  FileStrm;
    Vector3D P1,P2;
    
    std::string name_of_file = "../datasets/Glb_crd_No_" + std::to_string(get_obj_ID()) + "_front_camera.dat";
    front_camera.update_Name_of_file_global(name_of_file);

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }
    
    P1 = (front_camera[0] + front_camera[3])/2;
    P2 = (front_camera[6] + front_camera[9])/2;

    FileStrm << P1 << std::endl
             << front_camera[0] << std::endl
             << front_camera[6] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;

    FileStrm << P1 << std::endl
             << front_camera[1] << std::endl
             << front_camera[7] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 
     
    FileStrm << P1 << std::endl
             << front_camera[2] << std::endl
             << front_camera[8] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;       
      
    FileStrm << P1 << std::endl
             << front_camera[3] << std::endl
             << front_camera[9] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;       
      
    FileStrm << P1 << std::endl
             << front_camera[4] << std::endl
             << front_camera[10] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;                

    FileStrm << P1 << std::endl
             << front_camera[5] << std::endl
             << front_camera[11] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;     

    FileStrm << P1 << std::endl
             << front_camera[0] << std::endl
             << front_camera[6] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;
       
    FileStrm.close();
}


/*!
    Metoda zapisuje do pliku, o wygenerowanej automatycznie nazwie, dane o polozeniu wierzcholkow globalnych rotora- graniostoslupa froemnego szesciokatnego, po uprzednim wyliczeniu ich. 
    Zapis odbywa sie w sposob umozliwajacy wyswietlenie wszystkich scian rotora w Gnuplot.   
*/

void Drone::Calculate_and_save_to_file_rotor(unsigned int index, Vector3D const & Trasnlation){
    
    rotors[index].Transform_to_global_coords(Trasnlation, drone_location, fuselage.get_angle());

    std::ofstream  FileStrm;
    Vector3D P1,P2;
    
    std::string name_of_file = "../datasets/Glb_crd_No_" + std::to_string(get_obj_ID()) + "_rotor" + std::to_string(index) + ".dat";
    rotors[index].update_Name_of_file_global(name_of_file);

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }
    
    P1 = (rotors[index][0] + rotors[index][3])/2;
    P2 = (rotors[index][6] + rotors[index][9])/2;

    FileStrm << P1 << std::endl
             << rotors[index][0] << std::endl
             << rotors[index][6] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;

    FileStrm << P1 << std::endl
             << rotors[index][1] << std::endl
             << rotors[index][7] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl; 
     
    FileStrm << P1 << std::endl
             << rotors[index][2] << std::endl
             << rotors[index][8] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;       
      
    FileStrm << P1 << std::endl
             << rotors[index][3] << std::endl
             << rotors[index][9] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;       
      
    FileStrm << P1 << std::endl
             << rotors[index][4] << std::endl
             << rotors[index][10] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;                

    FileStrm << P1 << std::endl
             << rotors[index][5] << std::endl
             << rotors[index][11] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;     

    FileStrm << P1 << std::endl
             << rotors[index][0] << std::endl
             << rotors[index][6] << std::endl
             << P2 << std::endl
             << '#' << std::endl
             << std::endl;
       
    FileStrm.close();
}

/*!
    Metoda publiczna pozwalajaca w polaczony sposob zapisac wszystkie elementy drona do plikow. 
    Metoda wyznacza wektory przesuniecia rotorow i kamery w ukladzie prostopadloscianu.
*/

void Drone::Calculate_and_save_to_file_drone(){
    double Tval_rot2[3]={-1,1,1},Tval_rot3[3]={1,-1,1},Tval_rot4[3]={-1,-1,1},Tval_cam[3]={1,0,0}, T_offset[3] = {0,0,0.5};
    
    Vector3D rotor_scale = rotors[0].get_scale(), fuselage_scale = fuselage.get_scale();

    Vector3D Tr_rot2(Tval_rot2), Tr_rot3(Tval_rot3), Tr_rot4(Tval_rot4), Tr_cam(Tval_cam), Tr_offset(T_offset);

    Vector3D rotor_offset = rotor_scale * Tr_offset;

    Calculate_and_save_to_file_fuselage();

    Calculate_and_save_to_file_front_camera(fuselage_scale / 2 * Tr_cam);

    Calculate_and_save_to_file_rotor(0,fuselage_scale / 2 + rotor_offset);
    Calculate_and_save_to_file_rotor(1,fuselage_scale / 2 * Tr_rot2 + rotor_offset);
    Calculate_and_save_to_file_rotor(2,fuselage_scale / 2 * Tr_rot3 + rotor_offset);
    Calculate_and_save_to_file_rotor(3,fuselage_scale / 2 * Tr_rot4 + rotor_offset);

    drone_radius[0] = sqrt( pow(fuselage.get_scale()[0] / 2,2) + pow(fuselage.get_scale()[1] / 2,2) ) + rotors[0].get_scale()[0]/sqrt(4+2*sqrt(2))*sqrt((2+sqrt(2))/2);
}

/*!
    Metoda sluzaca do poruszania sie dornem w pionie, w gore i w dol.
    Metoda realizuje przelot w formie animacji, nasladujacej prawdziwa dynamike rotorow.

    \param [in] altitude - dlugosc na jaka ma sie wzniesc / z jakiej ma sie opuscic dron.
    \param [in] Link - lacze do Gnuplota.
*/

void Drone::go_verical(double const & altitude, PzG::LaczeDoGNUPlota & Link){
    for (int i = 0; i < FRAMES; ++i){
        if (altitude >= 0){
        rotors[0].update_angleZ(-10);
        rotors[1].update_angleZ(10);
        rotors[2].update_angleZ(10);
        rotors[3].update_angleZ(-10);
        }
        else{
            rotors[0].update_angleZ(-3);
            rotors[1].update_angleZ(3);
            rotors[2].update_angleZ(3);
            rotors[3].update_angleZ(-3);
        }
        drone_location[2]+=altitude/FRAMES;
        Calculate_and_save_to_file_drone();
        Link.Rysuj();
        usleep(20000);
    }
    Link.Rysuj();
}

/*!
    Metoda sluzaca do obracania w osi Z dornem o podany kat.
    Metoda realizuje obrot w formie animacji, nasladujacej prawdziwa dynamike rotorow.

    \param [in] user_angle - kat o jaki ma sie obrocic dron.
    \param [in] Link - lacze do Gnuplota.
*/

void Drone::rotate_drone(double const & user_angle, PzG::LaczeDoGNUPlota & Link){
    for (int i = 0; i < FRAMES; ++i){
        fuselage.update_angleZ(user_angle/FRAMES); 
        if((user_angle == 0)){
            rotors[0].update_angleZ(-5);
            rotors[1].update_angleZ(5);
            rotors[2].update_angleZ(5);
            rotors[3].update_angleZ(-5);
        }
        else if (user_angle > 0){
            rotors[0].update_angleZ(-10);
            rotors[1].update_angleZ(3);
            rotors[2].update_angleZ(3);
            rotors[3].update_angleZ(-10);
        }
        else{
            rotors[0].update_angleZ(-3);
            rotors[1].update_angleZ(10);
            rotors[2].update_angleZ(10);
            rotors[3].update_angleZ(-3);
        }
        Calculate_and_save_to_file_drone();
        usleep(20000);
        Link.Rysuj();
    } 
}

/*!
    Metoda sluzaca do poruszania sie dornem w poziomie.
    Metoda realizuje przelot w formie animacji, nasladujacej prawdziwa dynamike rotorow.

    \param [in] distance - odleglosc na jaka ma polecec dron.
    \param [in] user_angle - Kat o jaki ma obrocic sie dron.
    \param [in] Link - lacze do Gnuplota.
*/

void Drone::go_horizontal(double const & distance, double const & user_angle, PzG::LaczeDoGNUPlota & Link){
    double unit_values[3]={1,0,0};
    Vector3D unit_vector(unit_values);
    
    rotate_drone(user_angle,Link);
    
    Matrix3x3 Rotation_matrix = Fill_matrix_OZ(orientation_angle);
    
    unit_vector = Rotation_matrix * unit_vector;
    
    Vector3D translation_vector = (unit_vector * distance) / FRAMES;
    
    for (int i = 0; i < FRAMES; ++i){
        drone_location = drone_location + translation_vector;
        rotors[0].update_angleZ(-5);
        rotors[1].update_angleZ(5);
        rotors[2].update_angleZ(5);
        rotors[3].update_angleZ(-5);
        Calculate_and_save_to_file_drone();
        Link.Rysuj();
        usleep(20000);
    }
    Link.Rysuj();
}

/*!
    Metoda sluzaca do wyznaczania linii reprezentujacej zaplanowany przelot drona.

    \param [in] distance - odleglosc na jaka ma polecec dron.
    \param [in] angle - Kat o jaki ma obrocic sie dron.
    \param [in] Link - lacze do Gnuplota.
*/

void Drone::plan_path(double const & angle, double const & distance, Vector3D const & position, PzG::LaczeDoGNUPlota & Link){
    std::ofstream  FileStrm;
    std::string name_of_file = "../datasets/path.dat";
    Vector3D path_point_location = position;
     
    orientation_angle += angle;

    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }

    FileStrm << path_point_location << std::endl;

    path_point_location[2] += ALTITUDE; 

    FileStrm << path_point_location << std::endl;

    double unit_values[3]={1,0,0};
    Vector3D unit_vector(unit_values);
    Matrix3x3 Rotation_matrix = Fill_matrix_OZ(orientation_angle);
    unit_vector = Rotation_matrix * unit_vector;
    path_point_location = path_point_location + (unit_vector*distance);

    FileStrm << path_point_location << std::endl;
   
    path_point_location[2] -= ALTITUDE; 

    FileStrm << path_point_location << std::endl;

    Link.Rysuj();

    FileStrm.close();
} 

/*!
    Metoda sluzaca do wyznaczania linii reprezentujacej przelot drona podczas predefiniowanego zwiadu.

    \param [in] Link - lacze do Gnuplota.
*/

void Drone::plan_reacon(PzG::LaczeDoGNUPlota & Link){
    std::ofstream  FileStrm;
    std::string name_of_file = "../datasets/path_reacon.dat";
    Vector3D path_point_location = drone_location;
     
    FileStrm.open(name_of_file);
    if (!FileStrm.is_open()){
      throw std::runtime_error(":(  Operacja otwarcia pliku do zapisu nie powiodla sie.");
    }

    FileStrm << path_point_location << std::endl;
    path_point_location[2] += ALTITUDE; 
    FileStrm << path_point_location << std::endl;

    double unit_values[3]={1,0,0};
    Vector3D unit_vector(unit_values);
    
    Matrix3x3 Rotation_matrix = Fill_matrix_OZ(orientation_angle);
    unit_vector = Rotation_matrix * unit_vector;
    path_point_location = path_point_location + (unit_vector * REACON_RADIUS);
    FileStrm << path_point_location << std::endl;
   
    Rotation_matrix = Fill_matrix_OZ(112.5);
    unit_vector = Rotation_matrix * unit_vector;
    path_point_location = path_point_location + (unit_vector * REACON_RADIUS/sqrt((2+sqrt(2))/2));
    FileStrm << path_point_location << std::endl;
   
    for (unsigned int i = 0;i < 7 ; ++i){
        Rotation_matrix = Fill_matrix_OZ(45);
        unit_vector = Rotation_matrix * unit_vector;
        path_point_location = path_point_location + (unit_vector * REACON_RADIUS/sqrt((2+sqrt(2))/2));
        FileStrm << path_point_location << std::endl;
    }
   
    Rotation_matrix = Fill_matrix_OZ(112.5);
    unit_vector = Rotation_matrix * unit_vector;
    path_point_location = path_point_location + (unit_vector * REACON_RADIUS);
    FileStrm << path_point_location << std::endl;
   
    path_point_location[2] -= ALTITUDE; 
    FileStrm << path_point_location << std::endl;

    Link.Rysuj();

    FileStrm.close();
} 

/*! 
    Zadany dodatkowy kat obrotu drona zostanie zsumowany z aktualnym katem obrotu drona.

    \param [in] additional_angle - dodtkowy kat, o ktory dron zostanie obrocony.
*/

void Drone::update_angle(double const & additional_angle){
     orientation_angle += additional_angle;
}

/*! 
    Metoda zwraca aktualny kat obrotu drona.

    \return Kat obrou drona, jako wartosc typu double.
*/

double Drone::get_angle() const{
    return orientation_angle;
}

/*! 
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    Pozwala pobrac nazwe pliku kadluba drona.

    \return Nazwe pliku zawierajacego dane o wierzcholkach kadluba.
*/

 std::string const & Drone::get_name_of_file(){
   return fuselage.Get_Name_of_file_global();
}

/*! 
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    Pozwala pobrac pozycje srodka kadluba drona.

    \return Wektor polozenia srodka kadluba drona.
*/

Vector3D const & Drone::get_position(){
      return drone_location;
} 


/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    Pozwala pobrac wektor reprezentujacy dane o promieniu drona.
    
    \return Vector3D zawierajacy dane o promieniu drona.
*/

Vector3D const & Drone::get_size(){
    return drone_radius;
}

/*!
    Metoda przeslaniajaca metode wirtualna z klasy Scene_object.
    Pozwala sprawdzić czy podany dron bedzie wchodzil w kolizje z innymi obietkem sceny. 
    
    \param[in] Obj_ptr - wskaznik na obiekt sceny.

    \return true - jesli dron koliduje z obiektem sceny.
    \return false - jesli dron nie koliduje z obiektem sceny.
*/

bool Drone::detect_collision(const std::shared_ptr<Scene_object> Obj_ptr){

    Vector3D temp;
    if(Obj_ptr->get_type() == "plaskowyz" || Obj_ptr->get_type() == "gora ze szczytem" || Obj_ptr->get_type() == "gora z grania"){
        if(Obj_ptr->get_position()[0] - Obj_ptr->get_size()[0] / 2 - drone_radius[0] - 1 <= get_position()[0] && Obj_ptr->get_position()[0] + Obj_ptr->get_size()[0] / 2 + drone_radius[0] + 1 >= get_position()[0]){
            if(Obj_ptr->get_position()[1] - Obj_ptr->get_size()[1] / 2 - drone_radius[0]  - 1 <= get_position()[1] && Obj_ptr->get_position()[1] + Obj_ptr->get_size()[1] / 2 + drone_radius[0]  + 1 >= get_position()[1]){
                std::cout << "Ladowisko niedostepne!" << std::endl << "Wykryto element powierzchni typu: " << Obj_ptr->get_type() << std::endl;
                return true;
            }
        }
    } 
   
    if(Obj_ptr->get_type() == "dron" && Obj_ptr.get() != this){
        if(sqrt( pow(get_position()[0]-Obj_ptr->get_position()[0],2) + pow(get_position()[1]- Obj_ptr->get_position()[1],2))<= (get_size()[0] + Obj_ptr->get_size()[0])){
            std::cout << "Ladowisko niedostepne!" << std::endl << "Wykryto element typu: " << Obj_ptr->get_type() << std::endl;
            return true;
        } 
    }
    return false; 
}

