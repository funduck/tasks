'use strict';

const assert = require('assert')

let file = []

function syncWork(x) {
    file.push(`<head>${x}</head>`)
}
async function asyncWork(x) {                
    return new Promise((res) => { 
        setTimeout(() => {
            file.push(`<body>${x}</body>`)
            res()                     
        }, 1)
    })                                
}

const work = require('./' + process.argv[2])

Promise.all(
    [1,2,3,4,5].map(
        (x) => {
            return work(syncWork, asyncWork, x)
        }
    )
)
.then(() => {
    //console.log(JSON.stringify(file, null, '  '))
    assert.deepStrictEqual(file, [
        "<head>1</head>",
        "<body>1</body>",
        "<head>2</head>",
        "<body>2</body>",
        "<head>3</head>",
        "<body>3</body>",
        "<head>4</head>",
        "<body>4</body>",
        "<head>5</head>",
        "<body>5</body>"
    ])
    console.log('passed!')
})
.catch((e) => {
    console.error(e.stack)
})
