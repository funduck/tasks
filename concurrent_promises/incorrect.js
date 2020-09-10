module.exports = async function work(syncWork, asyncWork, x) {
    syncWork(x)
    await asyncWork(x)
}  

