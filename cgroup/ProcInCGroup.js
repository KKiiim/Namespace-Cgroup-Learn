const Path = require("path");
const FS   = require("fs");
let Files  = [];

function ThroughDirectory(Directory) {
    FS.readdirSync(Directory).forEach(File => {
        const Absolute = Path.join(Directory, File);
        if (FS.statSync(Absolute).isDirectory()) return ThroughDirectory(Absolute);
        else return Files.push(Absolute);
    });
}

// ThroughDirectory("/sys/fs/cgroup");
ThroughDirectory("/sys/fs/cgroup/mygrp18702");

let pids = []

for(let index in Files){
    let file = Files[index];
    if(file.includes("cgroup.procs")){
        /**
         * the .filter(Boolean) part ensures that the resulting array lines contains only non-empty lines from the file.
         * pass Boolean as the callback function to .filter(), .filter() will call Boolean on each element of the array.
         * like a type converter
         * 
         * let array = [0, 1, "", "text", undefined, "another text", false, true];
         * let truthyArray = array.filter(Boolean);
         * console.log(truthyArray); // Output: [1, "text", "another text", true]
         */
        var lines = FS.readFileSync(file, 'utf-8').split('\n').filter(Boolean);
        for(let y in lines){
            let pid = parseInt(lines[y]);
            pids.push(pid);
        }
    }
}

console.log(JSON.stringify(pids));
console.log(pids.length);