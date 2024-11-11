def read(t=int):
    return list(map(t,input().strip().split(' ')))
n = read()[0]
a = read()
from collections import defaultdict
d=defaultdict(int)
last = [4,4,8,15,16,23,42]
for i in a:
    index = last.index(i)-1
    if i == 4:
        d[i]+=1
    else:
        d[i]=min(d[i]+1,d[last[index]])
remove= n-min(d.values())*6
print(d)
if remove<0:
    remove = n
print(remove)
