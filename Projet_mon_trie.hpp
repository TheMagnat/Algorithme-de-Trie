#include <vector>
#include <memory>

namespace gmn{

	class trie{
		private:
			std::array<std::unique_ptr<trie>,26> next_;
			int nb;

		public:
			int& ajoutmot(std::string::iterator d, std::string::iterator f){
				int c;
				trie *t=this;
				for(auto p = d;p!=f;++p){
					c=*p-'a';
					if(t->next_[c]==nullptr){
						t->next_[c]=std::make_unique<trie>();
					}
					t=t->next_[c].get();
				}
				return t->nb;
			}

			int operator[](const std::string& mot){
				int c;
				trie *t=this;
				for(auto p = mot.begin();p!=mot.end();++p){
					c=*p-'a';
					if(t->next_[c]==nullptr){
						t->next_[c]=std::make_unique<trie>();
					}
					t=t->next_[c].get();
				}
				return t->nb;
			}
	};
}