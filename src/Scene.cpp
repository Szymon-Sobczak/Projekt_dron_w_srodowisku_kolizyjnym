#include "Scene.hh"

/*!
    \file Scene.cpp
        \brief Definicje metod klasy Scene.

    Zawiera definicje metod klasy Scene.
*/

/*!
    Konstruktor z parametrem obiektu typu Scene. 
    Tworzy scene z dwoma dronami w predefiniowanych miejscach oraz piecioma predefiniowanymi przeszkodami. 
    Dolacza pliki zawierajace dane o wierzcholkach globalnych elementow dronow i przszkod do Gnuplot oraz. 
    Ustala zakres rysowania w Gnuplot i grubosc rysowania linii.

    \param [in] Link - wskaznik na lacze do Gnuplota. 

    \return Scene zawierajaca dwa drony oraz 5 przeszkod.        
*/

Scene::Scene(PzG::LaczeDoGNUPlota * Link){
    Link_to_gnuplot = Link;
    Nbr_of_active_drone = 1;

    double val_ctr1[3]={150,150,3}, val_ctr2[3]={200,150,3};
    Vector3D center_of_drone1(val_ctr1), center_of_drone2(val_ctr2);

    add_new_drone(center_of_drone1);
    add_new_drone(center_of_drone2);

    double  val_ctr_pla0[3]={210,210,5}, val_scale0[3]={30,40,10},
            val_ctr_pla1[3]={130,70,10}, val_scale1[3]={60,40,20},
            val_ctr_pointed2[3]={100,230,45}, val_scale2[3]={60,40,90},
            val_ctr_pointed3[3]={80,130,25}, val_scale3[3]={60,60,50},
            val_ctr_long4[3]={230,110,15}, val_scale4[3]={60,40,30};
    
    Vector3D center_of_plateau0(val_ctr_pla0), scale_of_plateau0(val_scale0),
             center_of_plateau1(val_ctr_pla1), scale_of_plateau1(val_scale1),
             center_of_mnt_ptd2(val_ctr_pointed2), scale_of_mnt_ptd2(val_scale2),
             center_of_mnt_ptd3(val_ctr_pointed3), scale_of_mnt_ptd3(val_scale3),
             center_of_mnt_lng4(val_ctr_long4), scale_of_mnt_lng4(val_scale4);

    add_obstacle_plateau(center_of_plateau0, scale_of_plateau0);
    add_obstacle_plateau(center_of_plateau1, scale_of_plateau1);
    add_obstacle_mnt_pointed(center_of_mnt_ptd2, scale_of_mnt_ptd2);
    add_obstacle_mnt_pointed(center_of_mnt_ptd3, scale_of_mnt_ptd3);
    add_obstacle_mnt_long(center_of_mnt_lng4, scale_of_mnt_lng4);

    (*Link_to_gnuplot).ZmienTrybRys(PzG::TR_3D); /* Ustawienie trybu rysowania w gnuplot na 3D. */
    (*Link_to_gnuplot).UstawZakresY(0,300);      /* Uwstawienie zakresu osi OX, OY i OZ w Gnuplot */ 
    (*Link_to_gnuplot).UstawZakresX(0,300);
    (*Link_to_gnuplot).UstawZakresZ(0,150); 

    PzG::InfoPlikuDoRysowania *File_info_bed = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/bed.dat");
    File_info_bed -> ZmienKolor(4);
    File_info_bed -> ZmienSzerokosc(2); 
    
    Tab_of_properties_d1[0] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_0_fuselage.dat");
    Tab_of_properties_d1[1] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_0_rotor0.dat");
    Tab_of_properties_d1[2] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_0_rotor1.dat");
    Tab_of_properties_d1[3] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_0_rotor2.dat");
    Tab_of_properties_d1[4] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_0_rotor3.dat");
    Tab_of_properties_d1[5] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_0_front_camera.dat");

    Tab_of_properties_d2[0] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_1_fuselage.dat");
    Tab_of_properties_d2[1] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_1_rotor0.dat");
    Tab_of_properties_d2[2] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_1_rotor1.dat");
    Tab_of_properties_d2[3] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_1_rotor2.dat");
    Tab_of_properties_d2[4] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_1_rotor3.dat");
    Tab_of_properties_d2[5] = & (*Link_to_gnuplot).DodajNazwePliku("../datasets/Glb_crd_No_1_front_camera.dat");

    for (unsigned int i = 0; i < 6; ++i){
        Tab_of_properties_d1[i] -> ZmienSzerokosc(2);
        Tab_of_properties_d2[i] -> ZmienSzerokosc(2);
    } 
}

/*
    Usuwa pliki zawierajace dane o polozeniu wierzcholkow przeszkod znajdujacych sie na scenie. 
*/

Scene::~Scene(){
    for(std::shared_ptr<Scene_object> Obstacle : Obstacle_list){
       remove (Obstacle->get_name_of_file().c_str());
    } 
}

/*!
    Metoda pozwala ustawic, ktory z dron na scenie jest dronem aktywnym. 
    Metoda zmienia kolory dronow w zaleznosci od tego, ktory dron zostal wybrany jako aktywny.

    \param [in] active_drone - numer drona do aktywacji.
*/

void Scene::choose_drone(int active_drone){
    int Number = active_drone - 1;
    
    auto check_nbr = [Number](std::shared_ptr<Drone> Ptr) -> bool{ 
        return (Ptr->get_obj_ID() == Number); 
    };
    
    std::list<std::shared_ptr<Drone>>::iterator Drone_iterator = std::find_if(Drone_list.begin(), Drone_list.end(), check_nbr);
    
    if (Drone_iterator == Drone_list.end()){
        throw std::invalid_argument(":/ Podano bledny numer drona ");
    }

    Nbr_of_active_drone = active_drone;
        
    if (active_drone==1){
        for (unsigned int i = 0; i < 6; ++i){
            Tab_of_properties_d1[i] -> ZmienKolor(1);
            Tab_of_properties_d2[i] -> ZmienKolor(8);
        }  
    }

    if (active_drone==2){
        for (unsigned int i = 0; i < 6; ++i){
            Tab_of_properties_d1[i] -> ZmienKolor(8);
            Tab_of_properties_d2[i] -> ZmienKolor(1);
        }  
    }
}

/*!
    Metoda pozwala uzyskac dostep do dronow umieszczonych na liscie dronow. 

    \return Wskaznik na aktywnego drona. 
*/

std::shared_ptr <Drone> Scene::use_active_drone(){
    
    int Number = Nbr_of_active_drone - 1;
    
    auto check_nbr = [Number](std::shared_ptr<Drone> Ptr) -> bool{ 
        return (Ptr->get_obj_ID() == Number); 
    };
    
    std::list<std::shared_ptr<Drone>>::iterator Drone_iterator = std::find_if(Drone_list.begin(), Drone_list.end(), check_nbr);
    
    if (Drone_iterator == Drone_list.end()){
        throw std::invalid_argument(":/ Podano bledny numer drona ");
    }

    return *Drone_iterator;
}

/*!
    Dodaje do sceny obiekt - plaskowyz o okreslonej skali i w okreslonym miescju. 
    Dodaje nowy obiekt- plaskowyz do listy wszystkich przeszkod oraz do listy wszykisch obiektow sceny.

    \param [in] position - Wektor opisujacy srodek plaskowyzu. 
    \param [in] scale - skala plaskowyzu. 
*/

void Scene::add_obstacle_plateau(Vector3D const & position, Vector3D const & scale){
    std::shared_ptr<Plateau> tmp_ptr = std::make_shared<Plateau>(position, scale, Number_of_obstacles++);

    PzG::InfoPlikuDoRysowania *Temp_property = & (*Link_to_gnuplot).DodajNazwePliku(tmp_ptr->Get_Name_of_file_global().c_str());
    
    Temp_property-> ZmienSzerokosc(2); 
    Temp_property-> ZmienKolor(4);

    Obstacle_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);

    (*Link_to_gnuplot).Rysuj();
}  

/*!
    Dodaje do sceny obiekt - gore ze zboczem o okreslonej skali i w okreslonym miejscu. 
    Dodaje nowy obiekt- gore ze zboczem do listy przeszkod oraz do listy wszykisch obiektow sceny.

    \param [in] position - Wektor opisujacy srodek nachylonego boku gory ze zboczem. 
    \param [in] scale - skala gory ze zboczem. 
*/

void Scene::add_obstacle_mnt_long(Vector3D const & position, Vector3D const & scale){
    std::shared_ptr<Mnt_long> tmp_ptr = std::make_shared<Mnt_long>(position, scale, Number_of_obstacles++);

    PzG::InfoPlikuDoRysowania *Temp_property = & (*Link_to_gnuplot).DodajNazwePliku(tmp_ptr->Get_Name_of_file_global().c_str());
    Temp_property-> ZmienSzerokosc(2); 
    Temp_property-> ZmienKolor(4);

    Obstacle_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);

    (*Link_to_gnuplot).Rysuj();
}  

/*!
    Dodaje do sceny obiekt - gore ze szczytem o okreslonej skali i w okreslonym miejscu. 
    Dodaje nowy obiekt- gore ze szczytem do listy przeszkod oraz do listy wszykisch obiektow sceny.

    \param [in] position - Wektor opisujacy srodek gory ze szczytem. 
    \param [in] scale - skala gory ze zboczem. 
*/

void Scene::add_obstacle_mnt_pointed(Vector3D const & position, Vector3D const & scale){
    std::shared_ptr<Mnt_pointed> tmp_ptr = std::make_shared<Mnt_pointed>(position, scale, Number_of_obstacles++);

    PzG::InfoPlikuDoRysowania *Temp_property = & (*Link_to_gnuplot).DodajNazwePliku(tmp_ptr->Get_Name_of_file_global().c_str());
    Temp_property-> ZmienSzerokosc(2); 
    Temp_property-> ZmienKolor(4);

    Obstacle_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);

    (*Link_to_gnuplot).Rysuj();
} 

/*!
    Dodaje do sceny obiekt - drona w okreslonym miejscu. 
    Dodaje nowy obiekt- drona do listy dronow oraz do listy wszykisch obiektow sceny.

    \param [in] position - Wektor opisujacy pozycje drona. 
*/

void Scene::add_new_drone(Vector3D const & position){
    std::shared_ptr<Drone> tmp_ptr = std::make_shared<Drone>(position, Number_of_drones++);
    Drone_list.push_back(tmp_ptr);
    Objects_list.push_back(tmp_ptr);
}

/*!
    Metoda pozwala na wypisanie danych przeszkod znajdujacych sie aktualnie na liscie przeszkod na standardowe wyjscie.  
*/

void Scene::list_obstacles(){
    for(std::shared_ptr<Scene_object> Obstacle : Obstacle_list) {
      std::cout << "ID: " <<  Obstacle->get_obj_ID() << " "  << std::fixed << std::setprecision(2) << "(" << Obstacle->get_position()[0] << " " << Obstacle->get_position()[1] <<") - "<< Obstacle->get_type() << std::endl; 
    }
}

/*!
    Metoda pozwala usunac przeszkode ze sceny. 
    Usuwa przeszkode o okrelsonym ID z listy przeszkod oraz z listy wszystkich obiektow sceny. 
    Odlacza od Gnuplot oraz usuwa plik zawierajacy dane o usuwanej przeszkodzie. 

    \param [in] obstacle_ID - ID przeszkody do usuniecia
*/

void Scene::delete_obstacle(int obstacle_ID){

    auto check_obstacle = [obstacle_ID](std::shared_ptr<Scene_object> Ptr) -> bool{ 
        return (Ptr->get_obj_ID() == obstacle_ID && Ptr->get_type() != "dron" ); 
    };

    std::list<std::shared_ptr<Scene_object>>::iterator obs_iterator = 
    std::find_if(Obstacle_list.begin(),Obstacle_list.end(), check_obstacle);

    if (obs_iterator == Obstacle_list.end()) {
        throw std::invalid_argument(":/ Podano bledny numer ID przeszkody ");
    }

    std::list<std::shared_ptr<Scene_object>>::iterator obj_iterator = 
    std::find(Objects_list.begin(),Objects_list.end(), (*obs_iterator));
    
    if (obj_iterator == Objects_list.end()){
        throw std::invalid_argument(":/ Podano bledny numer drona ");
    }

    (*Link_to_gnuplot).UsunNazwePliku((*obs_iterator)->get_name_of_file().c_str());
    remove ((*obs_iterator)->get_name_of_file().c_str());
    Obstacle_list.erase(obs_iterator);
    Objects_list.erase(obj_iterator);
}

/*!
    Metoda pozwala sprawdzic czy dron o okreslonym ID, wchodzi w kolizje z innymi obiektami sceny. 

    \param [in] drone_ID - ID drona, ktory ma zostac sprawdzony pod katem kolizji z innymi obiektami sceny.

    \return true - jesli dron wchodzi w kolizje.
    \return false - jesli dron nie wchodzi w kolizje.
*/

bool Scene::check_if_drone_collides(int drone_ID){
    auto check_drone = [drone_ID](std::shared_ptr<Drone> Ptr) -> bool
			{return (Ptr->get_obj_ID() == drone_ID); };
    
    std::list<std::shared_ptr<Drone>>::iterator drone_iterator =
      std::find_if(Drone_list.begin(),Drone_list.end(), check_drone);
    
    if (drone_iterator == Drone_list.end()) {
        throw std::invalid_argument(":/ Podano bledny numer drona ");
    }

    for (std::shared_ptr<Scene_object> ObiektPtr : Objects_list){
        if((*drone_iterator)->detect_collision(ObiektPtr) == true)
            return true;
    }
    return false;
}