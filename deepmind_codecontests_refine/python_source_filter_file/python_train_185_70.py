import math
from sys import stdin
N,P=[int(x) for x in stdin.readline().rstrip().split()]
for i in reversed(range(int(math.pow(P,(1/N)))+1)):
    tmp=math.pow(i,N)
    if P==1:
        ans=1
        break
    if N==1:
        ans=P
        break
    if P%tmp==0:
        ans=i
        break
print(ans)