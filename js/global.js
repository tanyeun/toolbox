console.log("Hello World");

// console object belongs to the global object
global.console.log("Hello World");

// Every NodeJS file created is it's own module
var hello="Hello NodeJS";
console.log(global.hello);  // undef
console.log(hello);         // variables are visible in the file/module scope

// simple string operation
var nodejs=hello.slice(6);
console.log("Foo bar: ", nodejs);

// global references
console.log(__filename);
console.log(__dirname);

// require default libs
var path = require("path");
// get the filename directly from base
console.log("file: ", path.basename(__filename));
