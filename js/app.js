
// process object also is available globally
console.log(process.argv);

function grab(flag){
  var index = process.argv.indexOf(flag);
  // if flag not found, then index will be -1
  return (index == -1) ? null : process.argv[index+1]; 
}

var greeting = grab('--greeting');
var user = grab('--user');

if( !user || !greeting ){
    console.log("You brew it");
}else{
    console.log("Welcome ", user, " ", greeting);
}
