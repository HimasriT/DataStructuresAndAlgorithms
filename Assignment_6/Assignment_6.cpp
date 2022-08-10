#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<climits>
using namespace std;
// Maximum hashtable size is 100
string hashTable[100];
int tablesize;
int current_load = 0;
int no_collisions = 0;
// Hash function for String
unsigned long djb2hash(string s)
{
	int len = s.length();
	unsigned long hash = 5381;
	int c;
	
	for(int i = 0; i < len; i++)
	{
		c = s[i];
		hash = ((hash << 5) + hash) + c;
	}
	return hash;
}
int Find_nearest_prime(int val)
{
	int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 47, 53, 59, 61, 67, 71, 79, 83, 89 };
	bool found = false;
	for (int i = 1; i < sizeof(primes) / sizeof(int); i++)
	{
		if (val > primes[i - 1] && val < primes[i])
		{
			return primes[i];
		}
	}
	return -1;
}
int QuadraticProbing(int hash)
{
	int new_hash = hash;
	int k = 1;
	while (hashTable[new_hash].compare("#") != 0)
	{
		new_hash = (hash + (k * k)) % tablesize;
		k++;
	}
	return new_hash;
}
bool hashfunction(string name)
{
	unsigned long hash_val = djb2hash(name);
	int hash = hash_val % tablesize;
	if (hashTable[hash].compare("#") == 0)
	{
		hashTable[hash] = name;
		current_load++;
		return true;
	}
	else
	{
		no_collisions++;
		//Quadratic Probing to handle collisions
		int new_hash = QuadraticProbing(hash);
		hashTable[new_hash] = name;
		current_load++;
		return true;
	}
	return false;
} 
void rehashing()
{
	cout << "\nRehashing happens at " << current_load << endl;
	cout << "\nThe table entries before the rehashing \n \n";
	for (int i = 0; i < tablesize; i++)
	{
		cout << hashTable[i] << " ";
	}
	cout << endl;
	int old = tablesize;
	// finding the nearest prime to increase the hash table size.
	tablesize = Find_nearest_prime(2 * tablesize);
	vector<string> old_values;
	for (int i = 0; i < old; i++)
	{
		if (hashTable[i].compare("#") != 0)
		{
			old_values.push_back(hashTable[i]);
			hashTable[i] = "#";
		}
	}
	current_load = 0;
	for (int i = 0; i < old_values.size(); i++)
	{
		hashfunction(old_values[i]);
	}
	return;
}
int main()
{
	ifstream myfile;
	myfile.open("input.txt");
	string name;
	tablesize = 31;
	for (int i = 0; i < 100; i++)
	{
		hashTable[i] = "#";
	}
	// reading the input from file
	while (getline(myfile, name))
	{
		// if load increases current size, rehashing 
		if (current_load > 0.5 * tablesize)
		{
			cout << "Number of collisions till the rehashing " << no_collisions<<endl;
			rehashing();
		} 
		hashfunction(name);
	}
	cout << "\n Total number of collisions " << no_collisions << endl;
	cout << "\n The final table entries are \n";
	for (int i = 0; i < tablesize; i++)
	{
		cout << hashTable[i] << " ";
	}
	cout << endl;
	myfile.close();
	return 0;
}