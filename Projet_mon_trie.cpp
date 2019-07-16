#include <fstream>
#include <iostream>
#include <chrono>
#include <array>

#include "liste.hpp"
#include "Projet_mon_trie.hpp"

//La procedure d'ouverture et de lecture du fichier est exactement la même que pour Hmap
int main(int argc, char const *argv[]){	
	int i;
	char c;
	gmn::trie tab[26];
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
		    		++tab[mot.front()-'a'].ajoutmot(++mot.begin(),mot.end());
		    		mot.clear();
		    	}
		    }
		}
		fichier.close();
	}
	auto apres = std::chrono::system_clock::now();
	auto duree = apres - avant;
	//std::cout << tab['e'-'a']["motion"] << "\n"; //Pour comparer avec les autres methodes
	std::cout << "Mon trie " << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duree).count() -16000 << "ms" << '\n'; //-16000 car mon processeur met environ 16000 ms a ouvrir et lire tout les mots, a remplacer par le temps que met votre machine pour ne pas fausser les resultats.
	return 0;
}