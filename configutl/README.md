# ConfigUtl
Утилита для работы с семейством конфигов, зависящих от окружения: хост, юзер, профиль  

## Примерный --help 
```
Usage: configutl [--file FILENAME] [--host HOSTNAME] [--user USERNAME] [--profile PROFILE] [--getjson|--getstd]
Example: configutl --user sergey --profile test_env --getstd "db.host db.port"
```

## Устройство конфигов
Формат файла - JSON, структура такая:
* корневые ключи имеют вид **<hostname_mask>.<user_mask>.<profile_mask>**
* **default**  исключительный корневой ключ - он задает базовый конфиг
* Маска может содержать `*` - обозначает любой символ в количестве больше 0, а `.` - разделитель между масками

## Сборка конфига
Определяются `hostname, user, profile` из среды и переданных в **configutl** параметров (**hostname** - полное имя хоста, **user** - логин пользователя, **profile** - переменная среды `TEST_CONFIG_PROFILE`)  
Проверяются все корневые ключи, если ключ подходит, то конфиги накладываются в означенном порядке:
1. `default`
2. `hostname.*.*`
3. `*.user.*`
4. `*.*.profile`

config.json - пример конфига, на котором работает тест
test.sh - тестовый bash скрипт, если твой бинарник `your_bin`, то запускать тест так: sh test.sh `your_bin`

## Как должно всё сработать
```
$ sh test.sh sh mock.sh
Part 1: no TEST_CONFIG_PROFILE
 case 0
 case 1
 case 2
Part 2: with TEST_CONFIG_PROFILE
 case 0
 case 1
 case 2
All passed
```