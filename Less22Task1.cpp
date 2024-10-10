#include <iostream>
#include <map>
#include <vector>
#include <string>


// Функция для добавления нового записи в справочник
void addEntry(std::map<std::string, std::vector<std::string>>& surnameToNumber, std::map<std::string, std::string>& numberToSurname, std::string& phone, std::string& name) {
    surnameToNumber[name].push_back(phone);
    numberToSurname[phone] = name;
}

// Функция для получения фамилии по номеру телефона
void getNameByPhone(std::map<std::string, std::string>& numberToSurname, std::string& phone) {
    auto itf = surnameToNumber.find(cName);
    if (itf != surnameToNumber.end()) {
        std::cout << itf->second << std::endl;
        return;
    } 
    std::cout << "Not found getNameByPhone" << std::endl;
}

// Функция для получения номеров телефона по фамилии
void getPhonesByName(std::map<std::string, std::vector<std::string>>& surnameToNumber, std::string& cName) {
    auto itf = surnameToNumber.find(cName);
    if (itf != surnameToNumber.end()) {
        for (auto& phone : itf->second) {
            std::cout << phone << "; ";
        }
        std::cout << std::endl;    
        return;
    }
    std::cout << "Not found getPhonesByName" << std::endl;
}

int main() {
    std::map<std::string, std::string> numberToSurname;
    std::map<std::string, std::vector<std::string>> surnameToNumber;
    std::string cInput{ "" };
    std::cout << "11-11-11 Surname - for add an entry to the phonebook" << std::endl
        << "11-11-11 - for find out surname by phone number" << std::endl
        << "Lastname - for find out phone number by surname" << std::endl;

    while (cInput != "-1") {
        getline(std::cin, cInput);

        if (cInput == "-1") break;

        size_t pos = cInput.find(' '); //
        if (pos == std::string::npos) {
            // Запрос на получение телефона по фамилии
            if (cInput[0] > 64 && cInput[0] < 123){
                getPhonesByName(surnameToNumber, cInput);
            }
            else {
                getNameByPhone(numberToSurname, cInput);
            }
        } else {
            std::string cPhone = cInput.substr(0, pos);
            std::string cName = cInput.substr(pos + 1);
            if (cName.empty()) {
                // Запрос на получение фамилии по телефону
                getNameByPhone(numberToSurname, cPhone);
            } else {
                // Добавление новой записи в справочник
                addEntry(surnameToNumber, numberToSurname,cPhone, cName);
            }
        }
    }
    return 0;
}
