#include <iostream>
#include <map>
#include <string>
#include <utility>

int									store_count, find_count;
std::map<std::string, std::string>	password_map;

void	store_password() {
	int			store_count;
	std::string	site, password;

	std::cin >> store_count >> find_count;

	for (int i = 0; i < store_count; i++) {
		std::cin >> site >> password;
		password_map.insert(std::make_pair(site, password));
	}
}

void	find_password() {
	std::string	site;
	std::map<std::string, std::string>::iterator	itor;

	for (int i = 0; i < find_count; i++) {
		std::cin >> site;
		itor = password_map.find(site);
		std::cout << itor->second << std::endl;
	}
}

int	main(void) {

	store_password();
	find_password();

	return 0;
}
