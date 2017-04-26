# Json2Xml - библиотека и тулза для конвертирования json в xml
	
## Особенности
* работает только с UTF-8 и однобайтными кодировками
* все числовые типы представлены через std::string
* тип bool представлен через std::string
* тип null представлен через std::string
* под капотом [RapidJSON](https://github.com/miloyip/rapidjson)

## Сборка
```
cmake CMakeLists.txt
make
```

## Как это работает
### Библиотека
Создаём объект конвертера. Создаём объект обработчика.
Передаём в метод конвертирования последний и поток json.
Примерно так:

```cpp
#include <Json2Xml/Converter.hpp>
#include <Json2Xml/NullHandler.hpp>
#include <iostream>
#include <fstream>

using namespace json2xml;
Converter C;
NullHandler NH;
std::ifstream in("first_test_05.json");

if (C.convert(in, NH)) {
	std::cout << "OK\n";
}

```
Есть такие обработчики:
* Json2Xml/NullHandler.hpp, ничего не делает
* Json2Xml/TestHandler.hpp, собирает информацию для тестирования
* Json2Xml/PrettyXMLHandler.hpp, красиво рисует xml

Если никакой не подошёл, то нужно создать свой наследовав Json2Xml/Handler.hpp.

Повлиять на название контейнеров и атрибутов можно передав в конструктор
конвертера объект Json2Xml/Option.hpp.

### Тулза
Json2Xml использует обработчик PrettyXMLHandler и по умолчанию читает stdin
и выдаёт результат на stdout. Для изменения поведения смотреть `Json2Xml --help`.

## Ссылки
* RapidJSON        [https://github.com/miloyip/rapidjson](https://github.com/miloyip/rapidjson)
* SimpleJsonReader [https://github.com/popovb/SimpleJsonReader](https://github.com/popovb/SimpleJsonReader)

## Лицензия
Mozilla Public License Version 2.0
