#include <iostream>

using namespace System;
using namespace System::Threading;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

#undef NULL
#define NULL 0

class Case{
	private:
		bool active;
		bool robot;
		int col_robot; //1:rouge 2:bleu 3:vert 0:jaune
		bool cible;
		int col_cible; //1:rouge 2:bleu 3:vert 0:jaune
		int type_cible;//1:planete 2:Lune 3:Croix 0:Rond
		bool mur_haut;
		bool mur_droite;
		bool mur_gauche;
		bool mur_bas;


	public:
		Case();

		void reinit();

		bool hasRobot();

		bool hasMur_haut();
		bool hasMur_bas(){
			return mur_bas;
		}
		bool hasMur_droite(){
			return mur_droite;
		}
		bool hasMur_gauche(){
			return mur_gauche;
		}

		void setMur_haut(bool mur){
			mur_haut = mur;
		}
		void setMur_bas(bool mur){
			mur_bas = mur;
		}
		void setMur_droite(bool mur){
			mur_droite = mur;
		}
		void setMur_gauche(bool mur){
			mur_gauche = mur;
		}

		void setRobot(bool rob);

		int getColRobot();
		void setColRobot(int c);
		bool hasCible();
		int getTypeCible();
		void setTypeCible(int t);
		int getColCible();
		void setColCible(int c);
		void setCible(bool c);

		void setActive(bool a);
		bool isActive();




};