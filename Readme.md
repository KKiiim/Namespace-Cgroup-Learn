### cgroup and namespace commands refer:  
https://www.nginx.com/blog/what-are-namespaces-cgroups-how-do-they-work/  

# Preliminary conclusion
By 
```shell
echo '5000 10000' > mygrp18702/cpu.max
```
the cgroup mygrp18702 is limited to using half the cpu time.  
This only affects the cpu's time-slice allocation, and does not affect the progress of the actual user or system mode.
