### run program in new name namespaces  
```shell
unshare --user --pid --map-root-user --mount-proc --fork bash
```  
### show uid, gid, groups ...
```shell
id
```
### show list of namespaces
```shell
lsns --output-all
```