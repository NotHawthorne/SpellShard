#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class GameStrings{
public:
	class RaceStrings {
	private: map<int,string> list;
	public: RaceStrings  (map<int,string>); map<int,string> GameStrings::RaceStrings ::getList(); RaceStrings (); };
	class ClassStrings { 
	private: map<int,string> list;
	public: ClassStrings (map<int,string>); map<int,string> GameStrings::ClassStrings::getList(); ClassStrings(); };
	class ItemPrefixStrings { 
	private: map<int,string> list;
	public: ItemPrefixStrings (map<int,string>); map<int,string> GameStrings::ItemPrefixStrings::getList(); ItemPrefixStrings(); };
};

GameStrings::RaceStrings::RaceStrings()                    { map<int,string> n_list; list = n_list; }
GameStrings::RaceStrings::RaceStrings                      ( map<int, string> n_list ) { list = n_list; }
map<int, string> GameStrings::RaceStrings::getList()       { return list; }

GameStrings::ClassStrings::ClassStrings()                  { map<int,string> n_list; list = n_list; }
GameStrings::ClassStrings::ClassStrings                    ( map<int, string> n_list ) { list = n_list; }
map<int, string> GameStrings::ClassStrings::getList()      { return list; }

GameStrings::ItemPrefixStrings::ItemPrefixStrings()        { map<int,string> n_list; list = n_list; }
GameStrings::ItemPrefixStrings::ItemPrefixStrings          ( map<int, string> n_list ) { list = n_list; }
map<int, string> GameStrings::ItemPrefixStrings::getList() { return list; }

GameStrings::RaceStrings  racestrings;
GameStrings::ClassStrings classstrings;
GameStrings::ItemPrefixStrings prefixstrings;

void LoadAllStrings() 
{
	map<int,string>          rc_m;
	map<int,string>          cl_m;
	map<int,string>          pf_m;

	//RACES
	rc_m[1] =                "Terran";
	rc_m[2] =                "Chaos";         //REPLACE
	rc_m[3] =                "Ratonga";       //REPLACE
	rc_m[4] =                "Nymph";
	rc_m[5] =                "Gibberlings";   //REPLACE
	rc_m[6] =                "Abberation";
	rc_m[7] =                "Nephalem";
	rc_m[8] =                "Minotaur";
	rc_m[10]=                "Half-Giant";
	rc_m[11]=                "Construct";

	//CLASSES
	cl_m[0] =                "Game Master";   //GM CLASS

	cl_m[1] =                "Fighter";       //BASE CLASS
	cl_m[2] =                "Thief";         //BASE CLASS
	cl_m[3] =                "Arcanist";      //BASE CLASS
	cl_m[4] =                "Cleric";        //BASE CLASS

	cl_m[5] =                "Alchemist";
	cl_m[6] =                "Amazon";
	cl_m[7] =                "Bard";
	cl_m[8] =                "Berserker";
	cl_m[9] =                "Bokor";
	cl_m[10]=                "Champion of Ayena";
	cl_m[11]=                "Changeling";
	cl_m[12]=                "Dancer";
	cl_m[13]=                "Diabolist";
	cl_m[14]=                "Disciple of Vynne";
	cl_m[15]=                "Disruptor";
	cl_m[16]=                "Dragoon";
	cl_m[17]=                "Enchanter";
	cl_m[18]=                "Geomancer";
	cl_m[19]=                "Guardian";
	cl_m[20]=                "Lancer";
	cl_m[21]=                "Liturgist";
	cl_m[22]=                "Necromancer";
	cl_m[23]=                "Primalist";
	cl_m[24]=                "Pugilist";
	cl_m[25]=                "Raider";
	cl_m[26]=                "Runepriest";
	cl_m[27]=                "Scribe";
	cl_m[28]=                "Seer";
	cl_m[29]=                "Sentinel";
	cl_m[30]=                "Sniper";
	cl_m[31]=                "Sorcerer";
	cl_m[32]=                "Spellbreaker";
	cl_m[33]=                "Stalker";
	cl_m[34]=                "Tamer";
	cl_m[35]=                "Templar";
	cl_m[36]=                "Tinkerer";
	cl_m[37]=                "Totemic";
	cl_m[38]=                "Trapper";
	cl_m[39]=                "Witch Doctor";
	cl_m[40]=                "Commander";     //This is where I stop caring about A-Z ordering

	racestrings  =           GameStrings::RaceStrings(rc_m);
	classstrings =           GameStrings::ClassStrings(cl_m);
	prefixstrings=           GameStrings::ItemPrefixStrings(pf_m);
}