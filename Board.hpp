#include "Direction.hpp"
#include <vector>
#include <string>

using namespace std;

namespace ariel {
	
	class Board{
				
		private:
			vector<vector<string>> Board;
	
		public:
			void post(unsigned int row,unsigned int colum, Direction direct,const string &message);
			string read(unsigned int row,unsigned int colum, Direction direct,unsigned int length);
			void show();
	};
	
}
