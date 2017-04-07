#include <map>
#include <string>
#include <fstream>

const int OK = 0;
const int WRITE_ERROR = -1;
const int READ_ERROR = -2;
const int NOT_FOUND = -3;

typedef std::map<std::string, unsigned int> db_t;

int read_database(std::istream& connection, db_t& db)
{
	std::string name;
	int age;
	while(connection >> name >> age) db.emplace(name,age);
	return (connection.eof()) ? OK : READ_ERROR;
}
int write_database(std::ostream& connection, const db_t& db)
{
	for(auto &entry: db)
	{
		if(!connection.good()) return connection.good();
		connection << entry.first << " " << entry.second;
	}
	return connection.good() ? OK: WRITE_ERROR;
}
int atomic_update_person_age(const std::string& name, unsigned int age)
{
	int error;
	db_t db; 
	{
		std::ifstream database_file("database.txt");
		if((error = read_database(database_file, db)) < OK){
			return error;
		}
	}

	auto person = db.find(name);
	if(person != db.end())
	{
		db[name] = age;
	} else {
		return NOT_FOUND;
	}

	{
		std::ofstream database_file("database.txt");
		if((error = write_database(database_file, db)) < OK)
		{
			return error;
		}
	}
	
	return OK;
}
int atomic_rename_person(const std::string& oldname, const std::string& newname)
{
	int error;
	db_t db; 
	{
		std::ifstream database_file("database.txt");
		if((error = read_database(database_file, db)) < OK){
			return error;
		}
	}


	auto person = db.find(oldname);
	if(person != db.end())
	{
		int age = person->second;
		db.erase(person);
		db[newname] = age;
	} else {
		return NOT_FOUND;
	}

	{
		std::ofstream database_file("database.txt");
		if((error = write_database(database_file, db)) < OK)
		{
			return error;
		}
	}
	
	return OK;
}

int main(int argc, char *argv[])
{
	atomic_rename_person("Moooooo", "Cow");
	atomic_update_person_age("Cow", 1);
	return 0;
}

