#include "stdafx.h"
#include "Case.h"

Case::Case(){
	active = true;
	robot = false;
	col_robot = 0;
	cible = false;
	col_cible = 0;
	type_cible = 0;
	mur_haut = false;
	mur_bas = false;
	mur_droite = false;
	mur_gauche = false;
}

void Case::reinit(){
	active = true;
	robot = false;
	col_robot = 0;
	cible = false;
	col_cible = 0;
	type_cible = 0;
	mur_haut = false;
	mur_bas = false;
	mur_droite = false;
	mur_gauche = false;
}

bool Case::hasMur_haut(){
	return mur_haut;
}

bool Case::hasRobot(){
	return robot;
}

void Case::setRobot(bool rob){
	robot = rob;
}

int Case::getColRobot(){
	return col_robot;
}

void Case::setColRobot(int c){
	col_robot = c;
}

bool Case::hasCible(){
	return cible;
}

int Case::getTypeCible(){
	return type_cible;
}

void Case::setTypeCible(int t){
	type_cible = t;
}

int Case::getColCible(){
	return col_cible;
}

void Case::setColCible(int c){
	col_cible = c;
}

void Case::setCible(bool c){
	cible = c;
}

bool Case::isActive(){
	return active;
}

void Case::setActive(bool a){
	active = a;
}