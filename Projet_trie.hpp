#include <string>
#include <unordered_map>
#include <memory>

namespace gmn{

	class trie {
		private:
			std::unordered_map<char, std::unique_ptr<trie>> next_char_;
			int count_;
			
		public:

			int& operator[](const std::string& mot){
				trie *t=this;
				for(auto p = mot.begin();p!=mot.end();++p){
					if(t->next_char_[*p]==nullptr){
						t->next_char_[*p]=std::make_unique<trie>();
					}
					t=t->next_char_[*p].get();
				}
				return t->count_;
			}
	};

}