#include <fstream>
#include <iostream>
#include <chrono>
#include <array>

#include "liste.hpp"

int main(int argc, char const *argv[]){	
	int i;
	char c;
	std::string mot;
	std::array<std::string,599> nom = FICHIER;
	auto avant = std::chrono::system_clock::now();
	for(i=0;i<599;++i){
		std::ifstream fichier(nom[i], std::ifstream::in);
		while (fichier.good()){
		    c = fichier.get();
		    if((c>='a' && c<='z') || (c>='A' && c<='Z')){
		    	mot.push_back(tolower(c));
		    }
		    else{
		    	if(!mot.empty()){
		    		mot.clear();
		    	}
		    }
		}
		fichier.close();
	}
	auto apres = std::chrono::system_clock::now();
	auto duree = apres - avant;
	std::cout << "Temps lecture des fichier : " << std::chrono::duration_cast<std::chrono::milliseconds>(duree).count() << "ms" << '\n';
	//Sur mon ordinateur je met 16 000 ms environ, ce temps est a intervertir dans tout les autre fichier .cpp pour ne pas fausser les résultats
	return 0;
}