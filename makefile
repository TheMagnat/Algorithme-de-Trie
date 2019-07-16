CC=g++

tout:
	$(CC) -o hmap -O3 Projet_Hmap_toutfichier.cpp
	$(CC) -o triestandard -O3 Projet_trie.cpp
	$(CC) -o montrie -O3 Projet_mon_trie.cpp
	$(CC) -o lecturevide -O3 Projet_lecturevide.cpp

hmap: Projet_Hmap_toutfichier.cpp liste.hpp
	$(CC) -o hmap -O3 Projet_Hmap_toutfichier.cpp

trie: Projet_trie.cpp Projet_trie.hpp liste.hpp
	$(CC) -o triestandard -O3 Projet_trie.cpp

montrie: Projet_mon_trie.cpp Projet_mon_trie.hpp liste.hpp
	$(CC) -o montrie -O3 Projet_mon_trie.cpp

lecturevide: Projet_lecturevide.cpp liste.hpp
	$(CC) -o lecturevide -O3 Projet_lecturevide.cpp

clean:
	rm hmap triestandard montrie lecturevide