from collections import *
d, c =defaultdict(int), []
n=int(input())
sum=0
for i in input().split():
    i=int(i)
    sum=sum+i
    d[sum]+=1
    c.append(sum)
d[sum]-=1
p=0
for i in c[-1:1:-1]:
    if(i/2)*3==sum and i%2==0:
        d[i]-=1
        p=p+d[i/2]
    else:
        d[i]-=1
print(p)