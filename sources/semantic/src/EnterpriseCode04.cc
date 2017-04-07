#include <map>
#include <string>
#include <fstream>
#include <functional>

const int OK = 0;
const int WRITE_ERROR = -1;
const int READ_ERROR = -2;
const int NOT_FOUND = -3;

typedef std::map<std::string, unsigned int> db_t;
typedef std::map<std::string, unsigned int>::iterator dbi_t;

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
int atomic_update(const std::string & name, const std::function<int(db_t &, dbi_t &)> &action)
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
	if(person != db.end()){
		if((error = action(db, person)) != OK) return error;
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

int atomic_update_person_age(const std::string& name, unsigned int age)
{
	return atomic_update(name, [&](db_t & db, dbi_t &){
		db[name] = age;
		return OK;
	});
}
int atomic_rename_person(const std::string& oldname, const std::string& newname)
{
	return atomic_update(oldname, [&newname](db_t db, dbi_t & it){
		int age = it->second;
		db.erase(it);
		db[newname] = age;
		return OK;
	});
}

int main(int argc, char *argv[])
{
	atomic_rename_person("Moooooo", "Cow");
	atomic_update_person_age("Cow", 1);
	return 0;
}

