#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Windows.h"
#include "ctype.h"
#include <SWI-cpp.h>
#include <SWI-Prolog.h>
#include <SWI-Stream.h>
#include "Case.h"


namespace RR_projet {

	using namespace std;
	using namespace System;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Case tab[16][16];
	int coordonneeRobot[4][2];
	int coordonneeCibleR[4][2];
	int coordonneeCibleB[4][2];
	int coordonneeCibleV[4][2];
	int coordonneeCibleJ[4][2];

	/// <summary>
	/// Description résumée de Form1
	///
	/// AVERTISSEMENT : si vous modifiez le nom de cette classe, vous devrez modifier la
	///          propriété 'Nom du fichier de ressources' de l'outil de compilation de ressource managée
	///          pour tous les fichiers .resx dont dépend cette classe. Dans le cas contraire,
	///          les concepteurs ne pourront pas interagir correctement avec les ressources
	///          localisées associées à ce formulaire.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Random^ R;
		int robotCible;
		int cibleX;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tb2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Label^  label35;
	public: 
		int cibleY;
		Form1(void)
		{
			R=gcnew Random();
			if(readConfig()->Equals("SWI_HOME_DIR=")){
				MessageBox::Show("Il vous faut éditer le fichier config.txt. Merci de remplir la première ligne par le chemin de votre SWI Prolog. (exemple: C:\\\\Program Files (x86)\\\\pl)");
				exit(1);
			}	
			initTab();
			initRobot();
			InitializeComponent();
			this->button1->Enabled = false;
			this->button2->Enabled = true;
			//
			//TODO : ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button1;


	protected: 

	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tb2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(27, 16);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(640, 640);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(694, 63);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(229, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Résolution";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(694, 16);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(229, 27);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Jeu";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(691, 228);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Liste des coups";
			// 
			// tb2
			// 
			this->tb2->Location = System::Drawing::Point(694, 189);
			this->tb2->Name = L"tb2";
			this->tb2->ReadOnly = true;
			this->tb2->Size = System::Drawing::Size(93, 20);
			this->tb2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(691, 164);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Nombres de coups";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(694, 113);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(229, 27);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Reinitialisation";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(691, 258);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 634);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(34, 669);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(75, 669);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"2";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 595);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"2";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(117, 669);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"3";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(162, 669);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"4";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(205, 669);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 15;
			this->label10->Text = L"5";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(248, 669);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"6";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(289, 669);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(13, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"7";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(366, 669);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(13, 13);
			this->label13->TabIndex = 18;
			this->label13->Text = L"9";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(327, 669);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 13);
			this->label14->TabIndex = 19;
			this->label14->Text = L"8";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(445, 669);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(19, 13);
			this->label15->TabIndex = 20;
			this->label15->Text = L"11";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(486, 669);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(19, 13);
			this->label16->TabIndex = 21;
			this->label16->Text = L"12";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(567, 669);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(19, 13);
			this->label17->TabIndex = 22;
			this->label17->Text = L"14";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(528, 669);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(19, 13);
			this->label18->TabIndex = 23;
			this->label18->Text = L"13";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(603, 669);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(19, 13);
			this->label19->TabIndex = 24;
			this->label19->Text = L"15";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(406, 669);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(19, 13);
			this->label20->TabIndex = 25;
			this->label20->Text = L"10";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(643, 669);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(19, 13);
			this->label21->TabIndex = 26;
			this->label21->Text = L"16";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(8, 30);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(19, 13);
			this->label22->TabIndex = 40;
			this->label22->Text = L"16";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(8, 271);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(19, 13);
			this->label23->TabIndex = 39;
			this->label23->Text = L"10";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(8, 113);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(19, 13);
			this->label24->TabIndex = 36;
			this->label24->Text = L"14";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(8, 71);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(19, 13);
			this->label25->TabIndex = 38;
			this->label25->Text = L"15";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(8, 148);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(19, 13);
			this->label26->TabIndex = 37;
			this->label26->Text = L"13";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(8, 189);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(19, 13);
			this->label27->TabIndex = 35;
			this->label27->Text = L"12";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(8, 228);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(19, 13);
			this->label28->TabIndex = 34;
			this->label28->Text = L"11";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(8, 347);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(13, 13);
			this->label29->TabIndex = 33;
			this->label29->Text = L"8";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(8, 310);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(13, 13);
			this->label30->TabIndex = 32;
			this->label30->Text = L"9";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(8, 390);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(13, 13);
			this->label31->TabIndex = 31;
			this->label31->Text = L"7";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(8, 435);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(13, 13);
			this->label32->TabIndex = 30;
			this->label32->Text = L"6";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(8, 479);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(13, 13);
			this->label33->TabIndex = 29;
			this->label33->Text = L"5";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(8, 518);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(13, 13);
			this->label34->TabIndex = 28;
			this->label34->Text = L"4";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(8, 559);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(13, 13);
			this->label35->TabIndex = 27;
			this->label35->Text = L"3";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(941, 702);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label28);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label35);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->tb2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Rasenden Roboter IA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion

	private: System::Void initTab(){
				 for(int i = 0; i<16;i++){		
				tab[i][0].setMur_haut(true);
				tab[i][15].setMur_bas(true);
				tab[15][i].setMur_droite(true);
				tab[0][i].setMur_gauche(true);
			}//fBord

			tab[7][8].setActive(false);
			tab[7][7].setActive(false);
			tab[8][7].setActive(false);
			tab[8][8].setActive(false);
			

			//carré milieu
			tab[7][6].setMur_bas(true);
			tab[8][6].setMur_bas(true);
			tab[6][7].setMur_droite(true);
			tab[6][8].setMur_droite(true);
			tab[9][7].setMur_gauche(true);
			tab[9][8].setMur_gauche(true);
			tab[7][9].setMur_haut(true);
			tab[8][9].setMur_haut(true);
			//fCarré milieu

			//AutreMur
			//mur droite gauche
			tab[3][0].setMur_droite(true);
			tab[4][0].setMur_gauche(true);
			tab[8][0].setMur_droite(true);
			tab[9][0].setMur_gauche(true);
			tab[5][1].setMur_droite(true);
			tab[6][1].setMur_gauche(true);
			tab[12][1].setMur_droite(true);
			tab[13][1].setMur_gauche(true);
			tab[0][2].setMur_droite(true);
			tab[1][2].setMur_gauche(true);
			tab[9][2].setMur_droite(true);
			tab[10][2].setMur_gauche(true);
			tab[5][4].setMur_droite(true);
			tab[6][4].setMur_gauche(true);
			tab[11][5].setMur_droite(true);
			tab[12][5].setMur_gauche(true);
			tab[2][6].setMur_droite(true);
			tab[3][6].setMur_gauche(true);
			tab[13][6].setMur_droite(true);
			tab[14][6].setMur_gauche(true);
			tab[1][9].setMur_droite(true);
			tab[2][9].setMur_gauche(true);
			tab[4][9].setMur_droite(true);
			tab[5][9].setMur_gauche(true);
			tab[14][9].setMur_droite(true);
			tab[15][9].setMur_gauche(true);
			tab[8][10].setMur_droite(true);
			tab[9][10].setMur_gauche(true);
			tab[12][11].setMur_droite(true);
			tab[13][11].setMur_gauche(true);
			tab[6][12].setMur_droite(true);
			tab[7][12].setMur_gauche(true);
			tab[9][13].setMur_droite(true);
			tab[10][13].setMur_gauche(true);
			tab[1][14].setMur_droite(true);
			tab[2][14].setMur_gauche(true);
			tab[5][15].setMur_droite(true);
			tab[6][15].setMur_gauche(true);
			tab[11][15].setMur_droite(true);
			tab[12][15].setMur_gauche(true);
			//fmurdroitegauche
			//murhautbas
			tab[0][3].setMur_bas(true);
			tab[0][4].setMur_haut(true);
			tab[0][10].setMur_bas(true);
			tab[0][11].setMur_haut(true);
			tab[1][2].setMur_bas(true);
			tab[1][3].setMur_haut(true);
			tab[1][8].setMur_bas(true);
			tab[1][9].setMur_haut(true);
			tab[2][5].setMur_bas(true);
			tab[2][6].setMur_haut(true);
			tab[2][14].setMur_bas(true);
			tab[2][15].setMur_haut(true);
			tab[5][1].setMur_bas(true);
			tab[5][2].setMur_haut(true);
			tab[5][8].setMur_bas(true);
			tab[5][9].setMur_haut(true);
			tab[6][3].setMur_bas(true);
			tab[6][4].setMur_haut(true);
			tab[6][12].setMur_bas(true);
			tab[6][13].setMur_haut(true);
			tab[8][9].setMur_bas(true);
			tab[8][10].setMur_haut(true);
			tab[10][2].setMur_bas(true);
			tab[10][3].setMur_haut(true);
			tab[10][12].setMur_bas(true);
			tab[10][13].setMur_haut(true);
			tab[11][4].setMur_bas(true);
			tab[11][5].setMur_haut(true);
			tab[12][1].setMur_bas(true);
			tab[12][2].setMur_haut(true);
			tab[13][11].setMur_bas(true);
			tab[13][12].setMur_haut(true);
			tab[14][5].setMur_bas(true);
			tab[14][6].setMur_haut(true);
			tab[14][9].setMur_bas(true);
			tab[14][10].setMur_haut(true);
			tab[15][3].setMur_bas(true);
			tab[15][4].setMur_haut(true);
			tab[15][10].setMur_bas(true);
			tab[15][11].setMur_haut(true);
			//fmurhautbas
			//fAutreMur
			//fMur

			//cible
			//planeterouge
			tab[1][2].setCible(true);
			tab[1][2].setTypeCible(1);
			tab[1][2].setColCible(1);
			//planetebleu
			tab[5][9].setCible(true);
			tab[5][9].setTypeCible(1);
			tab[5][9].setColCible(2);
			//planeteverte
			tab[11][5].setCible(true);
			tab[11][5].setTypeCible(1);
			tab[11][5].setColCible(3);
			//planetejaune
			tab[14][9].setCible(true);
			tab[14][9].setTypeCible(1);
			tab[14][9].setColCible(4);
			//croixverte
			tab[5][1].setCible(true);
			tab[5][1].setTypeCible(3);
			tab[5][1].setColCible(3);
			//croixrouge
			tab[10][2].setCible(true);
			tab[10][2].setTypeCible(3);
			tab[10][2].setColCible(1);
			//croixbleu
			tab[10][13].setCible(true);
			tab[10][13].setTypeCible(3);
			tab[10][13].setColCible(2);
			//croixjaune
			tab[1][9].setCible(true);
			tab[1][9].setTypeCible(3);
			tab[1][9].setColCible(4);
			//lunerouge
			tab[6][12].setCible(true);
			tab[6][12].setTypeCible(2);
			tab[6][12].setColCible(1);
			//lunebleu
			tab[14][6].setCible(true);
			tab[14][6].setTypeCible(2);
			tab[14][6].setColCible(2);
			//luneverte
			tab[13][11].setCible(true);
			tab[13][11].setTypeCible(2);
			tab[13][11].setColCible(3);
			//lunejaune
			tab[6][4].setCible(true);
			tab[6][4].setTypeCible(2);
			tab[6][4].setColCible(4);
			//rondrouge
			tab[8][10].setCible(true);
			tab[8][10].setTypeCible(4);
			tab[8][10].setColCible(1);
			//rondbleu
			tab[2][6].setCible(true);
			tab[2][6].setTypeCible(4);
			tab[2][6].setColCible(2);
			//rondvert
			tab[2][14].setCible(true);
			tab[2][14].setTypeCible(4);
			tab[2][14].setColCible(3);
			//rondjaune
			tab[12][1].setCible(true);
			tab[12][1].setTypeCible(4);
			tab[12][1].setColCible(4);
			//fCible
			//tabCoordonnee
			coordonneeCibleR[0][0]=1;
			coordonneeCibleR[0][1]=2;
			coordonneeCibleR[1][0]=6;
			coordonneeCibleR[1][1]=12;
			coordonneeCibleR[2][0]=10;
			coordonneeCibleR[2][1]=2;
			coordonneeCibleR[3][0]=8;
			coordonneeCibleR[3][1]=10;

			coordonneeCibleB[0][0]=5;
			coordonneeCibleB[0][1]=9;
			coordonneeCibleB[1][0]=14;
			coordonneeCibleB[1][1]=6;
			coordonneeCibleB[2][0]=10;
			coordonneeCibleB[2][1]=13;
			coordonneeCibleB[3][0]=2;
			coordonneeCibleB[3][1]=6;

			coordonneeCibleV[0][0]=11;
			coordonneeCibleV[0][1]=5;
			coordonneeCibleV[1][0]=13;
			coordonneeCibleV[1][1]=11;
			coordonneeCibleV[2][0]=5;
			coordonneeCibleV[2][1]=1;
			coordonneeCibleV[3][0]=2;
			coordonneeCibleV[3][1]=14;

			coordonneeCibleJ[0][0]=14;
			coordonneeCibleJ[0][1]=9;
			coordonneeCibleJ[1][0]=6;
			coordonneeCibleJ[1][1]=4;
			coordonneeCibleJ[2][0]=1;
			coordonneeCibleJ[2][1]=9;
			coordonneeCibleJ[3][0]=12;
			coordonneeCibleJ[3][1]=1;

			/*tab[0][15].setRobot(true);
			tab[0][15].setColRobot(1);
			tab[9][12].setRobot(true);
			tab[9][12].setColRobot(2);
			tab[5][2].setRobot(true);
			tab[5][2].setColRobot(3);
			tab[15][1].setRobot(true);
			tab[15][1].setColRobot(4);*/
			 }

	 private:System::Void initRobot(){
				 int x;
				 int y;
				 bool ok = false;
				 for(int i=0;i<4;i++){
					 while(!ok){
						 x=R->Next(16);
						 y=R->Next(16);
						 if(!tab[x][y].hasCible()&&tab[x][y].isActive()&&!tab[x][y].hasRobot()){
							 tab[x][y].setRobot(true);
							 tab[x][y].setColRobot(i+1);
							 coordonneeRobot[i][0]=x;
							 coordonneeRobot[i][1]=y;
							 ok=true;
						 }
					 }
					 ok=false;
				 }
			 }
	 private: System::Void choix_cible(){
				  int choix;
				  int choix2;
				  choix = R->Next(4);
				  Graphics^ g;
				  g= panel1->CreateGraphics();
				  Bitmap^ myBitmap;
				  switch(choix){
					  case 0:
						robotCible = 0;
						myBitmap = gcnew Bitmap("testR.bmp");
						g->DrawImage(myBitmap, (7*40)+5,(7*40)+25 ,30,30);
						choix2 = R->Next(4);
						cibleX=coordonneeCibleR[choix2][0];
						cibleY=coordonneeCibleR[choix2][1];
						if(choix2 == 0)
							myBitmap = gcnew Bitmap("ciblePR.bmp");
						 else if(choix2 == 1)
							myBitmap = gcnew Bitmap("cibleLR.bmp");
						 else if(choix2 == 2)
							myBitmap = gcnew Bitmap("cibleCR.bmp");
						 else
							myBitmap = gcnew Bitmap("cibleRR.bmp");
						g->DrawImage(myBitmap, (8*40)+5,(7*40)+25 ,30,30);
						break;
					  case 1:
						robotCible = 1;
						myBitmap = gcnew Bitmap("testB.bmp");
						g->DrawImage(myBitmap, (7*40)+5,(7*40)+25 ,30,30);
						choix2 = R->Next(3);
						cibleX=coordonneeCibleB[choix2][0];
						cibleY=coordonneeCibleB[choix2][1];
						if(choix2 == 0)
							myBitmap = gcnew Bitmap("ciblePB.bmp");
						 else if(choix2 == 1)
							myBitmap = gcnew Bitmap("cibleLB.bmp");
						 else if(choix2 == 2)
							myBitmap = gcnew Bitmap("cibleCB.bmp");
						 else
							myBitmap = gcnew Bitmap("cibleRB.bmp");
						g->DrawImage(myBitmap, (8*40)+5,(7*40)+25 ,30,30);
						break;
					  case 2:
						robotCible = 2;
						myBitmap = gcnew Bitmap("testV.bmp");
						g->DrawImage(myBitmap, (7*40)+5,(7*40)+25 ,30,30);
						choix2 = R->Next(3);
						cibleX=coordonneeCibleV[choix2][0];
						cibleY=coordonneeCibleV[choix2][1];
						if(choix2 == 0)
							myBitmap = gcnew Bitmap("ciblePV.bmp");
						 else if(choix2 == 1)
							myBitmap = gcnew Bitmap("cibleLV.bmp");
						 else if(choix2 == 2)
							myBitmap = gcnew Bitmap("cibleCV.bmp");
						 else
							myBitmap = gcnew Bitmap("cibleRV.bmp");
						g->DrawImage(myBitmap, (8*40)+5,(7*40)+25 ,30,30);
						break;
					  case 3:
						robotCible = 3;
						myBitmap = gcnew Bitmap("testJ.bmp");
						g->DrawImage(myBitmap, (7*40)+5,(7*40)+25 ,30,30);
						choix2 = R->Next(3);
						cibleX=coordonneeCibleJ[choix2][0];
						cibleY=coordonneeCibleJ[choix2][1];
						if(choix2 == 0)
							myBitmap = gcnew Bitmap("ciblePJ.bmp");
						 else if(choix2 == 1)
							myBitmap = gcnew Bitmap("cibleLJ.bmp");
						 else if(choix2 == 2)
							myBitmap = gcnew Bitmap("cibleCJ.bmp");
						 else
							myBitmap = gcnew Bitmap("cibleRJ.bmp");
						g->DrawImage(myBitmap, (8*40)+5,(7*40)+25 ,30,30);
						break;
					  default:
						break;
				  }
			  }
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 
				 //draw plateau
				 panel1->BackColor = Color::White;
				 Graphics^ g;
				 g=panel1->CreateGraphics();
				 Pen^ myPen= gcnew Pen(Color::Black);
				 float x1 = 40;
				 float x2 = 40;
				 while(x1 <= 640){
					 if(x1 == 320){
						g->DrawLine(myPen,x1,0.0,x2,280.0);
						g->DrawLine(myPen,x1,360.0,x2,640.0);
					 }else{
						g->DrawLine(myPen,x1,0.0,x2,640.0);
					 }
					x1 = x2 += 40;
				 }
				 float y1 = 40;
				 float y2 = 40;
				 while(y1 <= 640){
					 if(y1 == 320){
						g->DrawLine(myPen,0.0,y1,280.0,y2);
						g->DrawLine(myPen,360.0,y1,640.0,y2);
					 }else{
						g->DrawLine(myPen,0.0,y1,640.0,y2);
					 }
					y1 = y2 += 40;
				 }
				 
				 /*g->DrawLine(myPen,279,279,361,279);
				 g->DrawLine(myPen,279,361,361,361);
				 g->DrawLine(myPen,279,279,279,361);
				 g->DrawLine(myPen,361,279,361,361);*/
				 //fin draw plateau
				 jeu();

			 }
	 private:
		 
		 void jeu(){

			//Mur
			//bord
			

			//construction mur
			for(int j=0;j<16;j++){
				 for(int i=0;i<16;i++){
					 //construction mur
					 if(tab[i][j].hasMur_haut()){
						 Pen^ myPen= gcnew Pen(Color::Black);
						 Graphics^ g;
						 g=panel1->CreateGraphics();
						 if(j==0)
							g->DrawLine(myPen,(i*40)-1,(j*40),((i+1)*40)-1,(j*40));
						 else
							g->DrawLine(myPen,(i*40)-1,(j*40)+1,((i+1)*40)-1,(j*40)+1);
					 }
					 if(tab[i][j].hasMur_bas()){
						 Pen^ myPen= gcnew Pen(Color::Black);
						 Graphics^ g;
						 g=panel1->CreateGraphics();
						 if(j==15){
							g->DrawLine(myPen,(i*40)-1,((j+1)*40)-3,((i+1)*40)-1,((j+1)*40)-3);
						 }
						 else
							g->DrawLine(myPen,(i*40)-1,((j+1)*40)-1,((i+1)*40)-1,((j+1)*40)-1);
					 }
					 if(tab[i][j].hasMur_droite()){
						 Pen^ myPen= gcnew Pen(Color::Black);
						 Graphics^ g;
						 g=panel1->CreateGraphics();
						 if(i==15){
							g->DrawLine(myPen,((i+1)*40)-3,(j*40)-1,((i+1)*40)-3,((j+1)*40)-1);
						 }
						 else
							g->DrawLine(myPen,((i+1)*40)-1,((j)*40)-1,((i+1)*40)-1,((j+1)*40)-1);
					 }
					 if(tab[i][j].hasMur_gauche()){
						 Pen^ myPen= gcnew Pen(Color::Black);
						 Graphics^ g;
						 g=panel1->CreateGraphics();
						 if(i==0)
							g->DrawLine(myPen,(i*40),(j*40)-1,(i*40),((j+1)*40)-1);
						 else
							g->DrawLine(myPen,(i*40)+1,(j*40)-1,(i*40)+1,((j+1)*40)-1);
					 }
					 //fin construction mur
					 //construction robot
					 
					 if(tab[i][j].hasCible()){
						 Graphics^ g;
						 g= panel1->CreateGraphics();
						 Bitmap^ myBitmap;
						 switch(tab[i][j].getTypeCible()){
							 case 1:
								 if(tab[i][j].getColCible() == 1)
									myBitmap = gcnew Bitmap("ciblePR.bmp");
								 else if(tab[i][j].getColCible() == 2)
									myBitmap = gcnew Bitmap("ciblePB.bmp");
								 else if(tab[i][j].getColCible() == 3)
									myBitmap = gcnew Bitmap("ciblePV.bmp");
								 else
									myBitmap = gcnew Bitmap("ciblePJ.bmp");
								 break;
							 case 2:
								 if(tab[i][j].getColCible() == 1)
									myBitmap = gcnew Bitmap("cibleLR.bmp");
								 else if(tab[i][j].getColCible() == 2)
									myBitmap = gcnew Bitmap("cibleLB.bmp");
								 else if(tab[i][j].getColCible() == 3)
									myBitmap = gcnew Bitmap("cibleLV.bmp");
								 else
									myBitmap = gcnew Bitmap("cibleLJ.bmp");
								 break;
							 case 3:
								 if(tab[i][j].getColCible() == 1)
									myBitmap = gcnew Bitmap("cibleCR.bmp");
								 else if(tab[i][j].getColCible() == 2)
									myBitmap = gcnew Bitmap("cibleCB.bmp");
								 else if(tab[i][j].getColCible() == 3)
									myBitmap = gcnew Bitmap("cibleCV.bmp");
								 else
									myBitmap = gcnew Bitmap("cibleCJ.bmp");
								 break;
							 case 4:
								 if(tab[i][j].getColCible() == 1){
									 myBitmap = gcnew Bitmap("cibleRR.bmp");}
								 else if(tab[i][j].getColCible() == 2){
									 myBitmap = gcnew Bitmap("cibleRB.bmp");}
								 else if(tab[i][j].getColCible() == 3){
									 myBitmap = gcnew Bitmap("cibleRV.bmp");}
								 else{
									 myBitmap = gcnew Bitmap("cibleRJ.bmp");}
								 break;
							 default:
								 break;
						 }
						 						
						 g->DrawImage(myBitmap, (i*40)+5,(j*40)+5 ,30,30);


					 }
					 if(tab[i][j].hasRobot()){
						 Graphics^ g;
						 g= panel1->CreateGraphics();
						 Bitmap^ myBitmap;
						 if(tab[i][j].getColRobot() == 1)
							myBitmap = gcnew Bitmap("testR.bmp");
						 else if(tab[i][j].getColRobot() == 2)
							myBitmap = gcnew Bitmap("testB.bmp");
						 else if(tab[i][j].getColRobot() == 3)
							myBitmap = gcnew Bitmap("testV.bmp");
						 else
							myBitmap = gcnew Bitmap("testJ.bmp");						
						 g->DrawImage(myBitmap, (i*40)+5 , (j*40)+5,30,30);
					 }
				 }
			}
		 }
		 private: System::Void deplacement(System::String^ s){
						
						cli::array<wchar_t,1>^ separator = gcnew cli::array<wchar_t,1>(2) ;
						separator[0]=',';
						separator[1]='|';
						cli::array<String^,1>^ tabcoor;
						tabcoor=s->Split(separator);
						int x=0;
						int y=1;
						int x2=2;
						int y2=3;
						int xtab;
						int ytab;
						int xtab2;
						int ytab2;
						Drawing::Rectangle rec1;
						Drawing::Rectangle rec2;
						while(y2<tabcoor->Length){
							xtab = Convert::ToInt32(tabcoor[x])-1;
							ytab = 16-Convert::ToInt32(tabcoor[y]);
							xtab2 = Convert::ToInt32(tabcoor[x2])-1;
							ytab2 = 16-Convert::ToInt32(tabcoor[y2]);
							tab[xtab][ytab].setRobot(false);
							tab[xtab2][ytab2].setRobot(true);
							tab[xtab2][ytab2].setColRobot(tab[xtab][ytab].getColRobot());
							rec1 = Drawing::Rectangle((xtab*40)+5 , (ytab*40)+5,30,30);
							rec2 = Drawing::Rectangle((xtab2*40)+5 , (ytab2*40)+5,30,30);
							panel1->Invalidate(rec1);
							panel1->Invalidate(rec2);
							panel1->Update();
							x+=2;
							y+=2;
							x2+=2;
							y2+=2;
							if(y2<tabcoor->Length)
								Sleep(1000);
							
						}

				  }

	private: System::String^ readConfig(){
				String^ res="SWI_HOME_DIR=";
				System::IO::StreamReader ^sr;
				try
				{
					// Ouverture du fichier et écriture du contenu du fichier sur la console
					sr = gcnew System::IO::StreamReader("config.txt");
					res += sr->ReadLine();
					// Remarque : on peut aussi utiliser ReadToEnd pour lire tout le fichier en une seule fois
				}
				finally
				{
					// Fermeture streamreader
					if (sr != nullptr) sr->Close();
				}
				
				return res;

			 }


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int argc;
				 String^ s;
				 char** argv =new char*[4];
				 argc = 4;

					argv[0] = "libpl.dll";
					argv[1] = "-G32m";
					argv[2] = "-L32m";
					argv[3] = "-T32m";

					putenv((char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(readConfig()));

					PL_initialise(argc, argv);

					if ( !PL_initialise(argc, argv) )
					PL_halt(1);
					try{
					//PlCall( "consult(swi('plwin.rc'))" );
					PlCall( "consult('case.pl')" );
					} catch ( PlException &ex )
					  { cerr << (char *) ex << endl;
					}
					
					try{
					//PlCall( "consult(swi('plwin.rc'))" );
					PlCall( "consult('Jeu_Rasende_roboter.pl')" );
					} catch ( PlException &ex )
					  { cerr << (char *) ex << endl;
					}
					try{
					//PlCall( "consult(swi('plwin.rc'))" );
					PlCall( "consult('jeu_1robot.pl')" );
					} catch ( PlException &ex )
					  { cerr << (char *) ex << endl;
					  }

					try{
					//PlCall( "consult(swi('plwin.rc'))" );

					/*
					int i =0;string tab[100];tab[0]=
					PlCall( "hanoi(4)" );cout<<"res:\n"<<tab[0];
					*/
					PlTermv av(13);
					av[0]=coordonneeRobot[1][0]+1;
					av[1]=16-coordonneeRobot[1][1];
					av[2]=coordonneeRobot[2][0]+1;
					av[3]=16-coordonneeRobot[2][1];
					av[4]=coordonneeRobot[0][0]+1;
					av[5]=16-coordonneeRobot[0][1];
					av[6]=coordonneeRobot[3][0]+1;
					av[7]=16-coordonneeRobot[3][1];
					if(robotCible==0)
						av[8]="rbtRouge";
					else if(robotCible==1)
						av[8]="rbtBleu";
					else if(robotCible==2)
						av[8]="rbtVert";
					else
						av[8]="rbtJaune";
					av[9]=cibleX+1;
					av[10]=16-cibleY;



					PlQuery q("jeu_1robot", av);
					int rval= PL_next_solution(q.qid);

					if ( !(rval) )
					{ term_t ex;

						if ( (ex = PL_exception(q.qid)) )
						  PlException(ex).cppThrow();
						else{
							label3->Text = "Impossible";
							button2->Enabled = true;
							button1->Enabled = false;
						}
					}else{
						try{
								s = gcnew String(((string) av[11]).c_str());
								cli::array<wchar_t,1>^ separator = gcnew cli::array<wchar_t,1>(1) ;
								separator[0]='|';
								cli::array<String^,1>^ affcoor;
								affcoor=s->Split(separator);
								for(int i=0;i<affcoor->Length;i++){
									label3->Text+=i+". ["+affcoor[i]+"]\n";
								}
								tb2->Text= gcnew String(((string) av[12]).c_str());
								deplacement(s);
								button1->Enabled = false;
								/*System::Drawing::Rectangle rec = System::Drawing::Rectangle(1,1,30,30);
								panel1->Invalidate(rec);*/
						}
						catch(PlTypeError &ex3){
						}
					}

					} catch ( PlTypeError &ex )
					{	cerr << (char *) ex << endl;
					}catch ( PlException &ex2 ){
						cerr << (char *) ex2 << endl;
					}





					//PL_halt( PL_toplevel() ? 0 : 1 );
					
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 label3->Text="";
			 choix_cible();
			 this->button1->Enabled = true;
			this->button2->Enabled = false;
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 label3->Text ="";
			 tb2->Text = "";
			 for(int i=0;i<16;i++){
				for(int j=0;j<16;j++){
					tab[i][j].reinit();
				}
			}
			initTab();
			initRobot();
			panel1->Refresh();
			this->button1->Enabled = false;
			this->button2->Enabled = true;
		 }
};
}

