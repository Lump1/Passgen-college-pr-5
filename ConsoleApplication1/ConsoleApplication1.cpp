#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;  

enum AllowedCondition {
	Lower,
	Upper,
	AllSymbols,
};

const string AllowedConditionStrings[] = {
	"97-122",
	"65-90",
	"33-126"
};

string getPass(string id, int M = 12);
char getRandomChar(std::vector<int> asciiVector);
int countPowModFormula(int num, int modNum, int powNum = 1);
std::vector<int> split(const std::string& s, const std::string& delimiter);

int main()  
{  
	string id = "lumpi-phosphate@gmail.com";

	for (int i = 0; i < 10; i++) {
		cout << getPass(id) << '\n';
	}
}  

string getPass(string id, int M) {  
	string result = "";

	int N = id.length();
	int P = countPowModFormula(N, 6, 2);
	int Q = countPowModFormula(N, 5, 3);

	std::vector<int> lower = split(AllowedConditionStrings[Lower], "-");
	std::vector<int> upper = split(AllowedConditionStrings[Upper], "-");
	std::vector<int> allChars = split(AllowedConditionStrings[AllSymbols], "-");

	for (int i = 1; i < M; i++) {
		if (i >= 1 && i <= Q + 1) {
			result += getRandomChar(lower);
		}
		if (i >= 1 + Q + 1 && 1 + Q + 1 + P) {
			result += getRandomChar(upper);
		}
		else {
			result += getRandomChar(allChars);
		}
	}

	return result;
}  

char getRandomChar(std::vector<int> asciiVector) {
	return static_cast<char>(rand() % (asciiVector[1] - asciiVector[0] + 1) + asciiVector[0]);
}

int countPowModFormula(int num, int modNum, int powNum) {  
  return static_cast<int>(fmod(pow(num, powNum), modNum));  
}

std::vector<int> split(const std::string& s, const std::string& delimiter) {
   std::vector<int> tokens;
   size_t pos = 0;
   std::string token;
   std::string temp = s;
   while ((pos = temp.find(delimiter)) != std::string::npos) {
       token = temp.substr(0, pos);
       tokens.push_back(std::stoi(token));
       temp.erase(0, pos + delimiter.length()); 
   }
   tokens.push_back(std::stoi(temp));

   return tokens;
}
