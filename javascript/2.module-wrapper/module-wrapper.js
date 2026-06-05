function moduleWrapper(exports, require, module, __filename, __dirname) {

    console.log("node module wrapper demo");

    console.log("__filename", __filename);

    console.log("__dirname", __dirname);
    
    console.log("exports", exports);
    
    console.log("require", require);
    
    console.log("module", module);
}

// function call
moduleWrapper();
