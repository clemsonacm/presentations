#include <map>
#include <string>
#include <fstream>

int read_database(std::istream& connection, std::map<std::string, unsigned int>& db)
{
	std::string name;
	int age;
	while(connection >> name >> age) db.emplace(name,age);
	return (connection.eof()) ? 0 : -2;
}
int write_database(std::ostream& connection, const std::map<std::string, unsigned int>& db)
{
	for(auto &entry: db)
	{
		if(!connection.good()) return connection.good();
		connection << entry.first << " " << entry.second;
	}
	return connection.good();
}
int atomic_update_person_age(const std::string& name, unsigned int age)
{
	int error;
	std::map<std::string, unsigned int> db; 
	{
		std::ifstream database_file("database.txt");
		if((error = read_database(database_file, db)) < 0){
			return error;
		}
	}

	auto person = db.find(name);
	if(person != db.end())
	{
		db[name] = age;
	} else {
		return -3;
	}

	{
		std::ofstream database_file("database.txt");
		if((error = write_database(database_file, db)) < 0)
		{
			return error;
		}
	}
	
	return 0;
}
int atomic_rename_person(const std::string& oldname, const std::string& newname)
{
	int error;
	std::map<std::string, unsigned int> db; 
	{
		std::ifstream database_file("database.txt");
		if((error = read_database(database_file, db)) < 0){
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
		return -3;
	}

	{
		std::ofstream database_file("database.txt");
		if((error = write_database(database_file, db)) < 0)
		{
			return error;
		}
	}
	
	return 0;
}

int main(int argc, char *argv[])
{
	atomic_rename_person("Moooooo", "Cow");
	atomic_update_person_age("Robert", 22);
	return 0;
}
