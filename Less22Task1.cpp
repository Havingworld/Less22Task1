#include <iostream>
#include <map>
#include <vector>
#include <string>


// Функция для добавления нового записи в справочник
void addEntry(std::map<std::string, std::vector<std::string>>& phoneBook, std::string& phone, std::string& name) {
    phoneBook[name].push_back(phone);
}

// Функция для получения фамилии по номеру телефона
void getNameByPhone(std::map<std::string, std::vector<std::string>>& phoneBook, std::string& phone) {
    bool bFound{ false };
    for (const std::pair<std::string, std::vector<std::string>>& item : phoneBook) {
        for (int i{ 0 }; i < item.second.size(); i++){
            if (item.second[i] == phone) {
                std::cout << item.first << "; ";
                bFound = true;
            }
        }
    }
    if (bFound) {
        std::cout << std::endl;
        return;
    } 
    std::cout << "Not found getNameByPhone" << std::endl;
}

// Функция для получения номеров телефона по фамилии
void getPhonesByName(std::map<std::string, std::vector<std::string>>& phoneBook, std::string& cName) {
    auto itf = phoneBook.find(cName);
    if (itf != phoneBook.end()) {
        for (auto& phone : itf->second) {
            std::cout << phone << "; ";
        }
        std::cout << std::endl;    
        return;
    }
    std::cout << "Not found getPhonesByName" << std::endl;
}

int main() {
    std:: map<std::string, std::vector<std::string>> phoneBook;
    std::string cInput{ "" };
    std::cout << "11-11-11 Lastname - for add an entry to the phonebook" << std::endl
        << "11-11-11 - for find out lastname by phone number" << std::endl
        << "Lastname - for find out phone number by lastname" << std::endl;

    while (cInput != "-1") {
        getline(std::cin, cInput);

        if (cInput == "-1") break;

        size_t pos = cInput.find(' '); //
        if (pos == std::string::npos) {
            // Запрос на получение телефона по фамилии
            if (cInput[0] > 64 && cInput[0] < 123){
                getPhonesByName(phoneBook, cInput);
            }
            else {
                getNameByPhone(phoneBook, cInput);
            }
        } else {
            std::string cPhone = cInput.substr(0, pos);
            std::string cName = cInput.substr(pos + 1);
            if (cName.empty()) {
                // Запрос на получение фамилии по телефону
                getNameByPhone(phoneBook, cPhone);
            } else {
                // Добавление новой записи в справочник
                addEntry(phoneBook, cPhone, cName);
            }
        }
    }
    return 0;
}