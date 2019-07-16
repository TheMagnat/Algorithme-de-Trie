#include <iostream>
#include <fstream>
#include <chrono>
#include <array>

#include "liste.hpp"
#include "Projet_trie.hpp"

using trie = gmn::trie;

//La procedure d'ouverture et de lecture du fichier est exactement la même que pour Hmap
int main(int argc, char const *argv[]){
	int i;
	char c;
	trie tab;
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
		    		++tab[mot];
		    		mot.clear();
		    	}
		    }
		}
		fichier.close();
	}
	auto apres = std::chrono::system_clock::now();
	auto duree = apres - avant;
	//std::cout << tab["emotion"] << "\n";	//Pour comparer avec les autres methodes
	std::cout << "Trie " << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duree).count()-16000 << "ms" << '\n';
	return 0;
}