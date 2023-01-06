cd /sys/fs/cgroup
sudo mkdir mygrp
echo $$ > mygrp/cgroup.procs
cat /proc/$$/cgroup
cat mygrp/pids.current
echo 5 > mygrp/pids.max # max allowed pids in cgroup
echo $$ > /sys/fs/cgroup/cgroup.procs # move to root cgroup
echo "+cpu" > mygrp/cgroup.subtree_control #add cpu to enabled controller
echo "5000 10000" > mygrp/cpu.max #set max cpu 5000/10000