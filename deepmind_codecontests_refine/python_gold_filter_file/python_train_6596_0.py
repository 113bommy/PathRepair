import sys 
import math
#4
#1 3 2 0
m,k = [int(i) for i in sys.stdin.readline().split()]
d = [int(i) for i in sys.stdin.readline().split()]
s = [int(i) for i in sys.stdin.readline().split()]
 
### 0 closed closed 1 gym 2 contest 3 both
 
time = 0
oil = 0
max_val = 0
for i,val in enumerate(d):
    oil += s[i]
    if s[i] > max_val:
        max_val = s[i]
    if val <=  oil: ## you can move
        time += val
        oil -= val
    else:
        left = val - oil  ## the required gas
        ## if the required gas is less than
        times = math.ceil(left/max_val) ## time 
        oil += times * max_val
        time += val + times * k
        oil -= val
print(time)