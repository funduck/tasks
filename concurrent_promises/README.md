# Concurrent Promises (JavaScript)
## Задача
В файле `main.js` смоделирован следующий процесс:  
`syncWork` - какие-то синхронные действия при обработке задачи  
`asyncWork` - какие-то асинхронные  
`[1,2,3,4,5]` - набор задач  
Вызов обработки задач происходит синхронно сразу для всех задач  
Цель - задачи должны обработаться последовательно

Нужно написать модуль `solution.js`, такой чтобы проходил тест
```
node main.js solution
passed!
```

## Тест
Для примера, есть некорректное решение задачи  
`node main.js incorrect` должен выдать примерно такое  
```
AssertionError [ERR_ASSERTION]: [ '<head>1</head>',
  '<head>2</head>',
  '<head>3</head>',
  '<head>4</head>',
  '<head>5</head>',
  '<body>1</body>',
  '<body deepStrictEqual [ '<head>1</head>',
  '<body>1</body>',
  '<head>2</head>',
  '<body>2</body>',
  '<head>3</head>',
  '<body>3</body>',
  '<head
    at Promise.all.then (/home/oomilekh/dev/tasks/concurrent_promises/main.js:30:12)
    at <anonymous>
```

