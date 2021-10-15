#include <iostream>
#include <map>
#include <set>

using namespace std;

bool isIsomorphic(string str1, string str2)
{
	// Two strings cannot be isomorphic if they have different lengths.
	if (str1.length() != str2.length())
		return false;

	map<char, char> map;

	// Use a set to keep track of already mapped characters.
	set<char> set;

	for (int i = 0; i < str1.length(); i++)
	{
		char c1 = str1[i], c2 = str2[i];
		
		// If c1 has been encountered before:
		if (map.find(c1) != map.end())
		{
			// Return false if first occurrence of c1 is mapped to
			// a different character.
			if (map[c1] != c2)
				return false;
		}

		// If c1 is encountered for the first time, it has not been mapped yet:
		else
		{
			// Return false if c2 is already mapped to some other char in str1
			if (set.find(c2) != set.end())
				return false;
				
				// All checks passed. So insert in the map, and the set.
			map[c1] = c2;
			set.insert(c2);
		}
	}
	return true;
}

// Driver code
int main()
{
	string str1 = "AAA";
	string str2 = "BBB";

	if (isIsomorphic(str1, str2))
		cout << str1 << " and " << str2 << " are isomorphic.";
	else
		cout << str1 << " and " << str2 << " are not isomorphic.";
}

/*AAA and BBB are isomorphic.*/
/*AAA and BBB are isomorphic.*/
