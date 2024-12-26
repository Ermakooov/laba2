#include "tableCipher.h"
#include "tableCipher.cpp"
using namespace std;

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    int op;

    try {
        wcout << L"Введите ключ: ";
        wcin >> key;
        if(!wcin.good()) {
            throw runtime_error("Неправильный ключ");
        }

        TableCipher cipher(key);

        do {
            wcout << L"Какую операцию выберете (0-выход, 1-зашифрование, 2-расшифрование): ";
            wcin >> op;
            if(op > 2) {
                wcout << L"Ошибка\n";
            } else if(op > 0) {
                wcout << L"Введите текст: ";
                wcin >> text;
                    if(op == 1) {
                        wcout << cipher.encrypt(text) << endl;
                    } else {
                        wcout << cipher.decrypt(text) << endl;
                    }
                
            }
        } while(op != 0);
    } catch(const exception& e) {
        wcerr << L"Ошибка: " << e.what() << endl;
}
    return 0;
}
