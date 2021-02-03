module.exports = function () {
    
    //  To check inbuilt programs are installed or not

    // Include shelljs to run shell commands in node
    const sh = require('shelljs')

    // Include electron-store to store the information in default path :
    // C:\Users\[USER_NAME]\AppData\Roaming\[APP_NAME]
    const Store = require('electron-store');

    const store = new Store();

    // Checking for the Operating System
    if(process.platform == 'darwin'){
        store.set('platform.Mac',true)
        store.set('platform.Windows',false)
        store.set('platform.Linux',false)
    }else if(process.platform == 'linux' ){
        store.set('platform.Windows',false)
        store.set('platform.Mac',false)
        store.set('platform.Linux',true)
    }else{
        store.set('platform.Linux',false)
        store.set('platform.Mac',false)
        store.set('platform.Windows',true)
    }

    sh.exec('java  -version', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.java',false)
        }
        else if(code === 0 ) {
            store.set('languages.java',true)
        }
    })
    
    sh.exec('node -v', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.node',false)
        }
        else if(code === 0 ) {
            store.set('languages.node',true)
        }
    })

    sh.exec('py --version', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.python',false)
        }
        else if(code === 0 ) {
            store.set('languages.python',true)
        }
    })

    sh.exec('conda -V', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.conda',false)
        }
        else if(code === 0 ) {
            store.set('languages.conda',true)
        }
    })

    sh.exec('gcc --version', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.c',false)
        }
        else if(code === 0 ) {
            store.set('languages.c',true)
        }
    })

    sh.exec('php -v', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.php',false)
        }
        else if(code === 0 ) {
            store.set('languages.php',true)
        }
    })

    sh.exec('npm -v', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.npm',false)
        }
        else if(code === 0 ) {
            store.set('languages.npm',true)
        }
    })

    sh.exec('jupyter-notebook --version', {silent : true } , (code, output,error) => {

        if(code !== 0) 
        {
            store.set('languages.jupyter-notebook',false)
        }
        else if(code === 0 ) {
            store.set('languages.jupyter-notebook',true)
        }
    })
}