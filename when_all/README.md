# When all - Задача на оптимизацию обработки запросов
Модуль `main.js` эмулирует задачу выполнения набора запросов и обработку разными модулями, сначала `mock_request_processor`, затем переданным в командной строке  
Например успешный запуск корректного решения задачи
```
$ node main.js correct_request_processor.js
mockRequestProcessor took 2729 msec
requestProcessor took 2087 msec
```
Или запуск без агрументов - только `mock_request_processor`
$ node main.js
mockRequestProcessor took 2748 msec
to check your request processor run: node main.js <filename>
```
Ради шутки, можно сравнить `mock_request_processor` с самим собой
```
$ node main.js mock_request_processor.js
mockRequestProcessor took 2741 msec
requestProcessor took 2753 msec
{ AssertionError: implemented processor should be more than 10% faster than mock processor
    ... }
```
