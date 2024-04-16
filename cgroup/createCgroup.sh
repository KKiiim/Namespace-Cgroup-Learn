cd /sys/fs/cgroup
sudo mkdir mygrp18702
sudo sh -c "echo $$ > /sys/fs/cgroup/mygrp18702/cgroup.procs"
cat /proc/$$/cgroup
sudo cat mygrp18702/pids.current
sudo sh -c "echo 5 > mygrp18702/pids.max" # max allowed pids in cgroup
sudo sh -c "echo '+cpu' > mygrp18702/cgroup.subtree_control" # add cpu to enabled controller
sudo sh -c "echo '5000 10000' > mygrp18702/cpu.max" # set max cpu 5000/10000