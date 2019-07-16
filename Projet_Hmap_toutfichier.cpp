#include <iostream>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <array>

#include "liste.hpp" //Contient le tableau de chaine de caractere FICHIER


using hmap = std::unordered_map<std::string, int>;


int main(int argc, char const *argv[]){
	int i;
	char c;
	hmap tab;
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
		    		++tab[mot]; //Ajout du string mot dans notre notre hmap
		    		mot.clear(); //On vide le mot
		    	}
		    }
		}
		fichier.close();
	}
	auto apres = std::chrono::system_clock::now();
	auto duree = apres - avant;
	//std::cout << tab["emotion"] << "\n"; //Pour afficher un mot en particulier et le comparer avec les autres methodes
	std::cout << "Unordered Map " << ": " << std::chrono::duration_cast<std::chrono::milliseconds>(duree).count() -16000 << "ms" << '\n';	//affichage du temps mis //-16000 car mon processeur met environ 16000 ms a ouvrir et lire tout les mots, a remplacer par le temps que met votre machine pour ne pas fausser les resultats.
	return 0;
}