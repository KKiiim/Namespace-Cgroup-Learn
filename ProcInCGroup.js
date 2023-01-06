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

ThroughDirectory("/sys/fs/cgroup");

let pids = []

for(let index in Files){
    let file = Files[index];
    if(file.includes("cgroup.procs")){
        var lines = require('fs').readFileSync(file, 'utf-8').split('\n').filter(Boolean);
        for(let y in lines){
            let pid = parseInt(lines[y]);
            pids.push(pid);
        }
    }
}

console.log(JSON.stringify(pids));
console.log(pids.length);