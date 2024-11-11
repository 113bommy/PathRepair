import math
t=int(input())
for i in range(t):
    cnt=0
    l=input().split(' ')
    s=int(l[0])
    intel=int(l[1])
    exp=int(l[2])
    dif=s+exp-intel
    if exp==0 and dif>0:
        print(1)
    else:
        print(min(max(math.floor((dif+1)/2),0),exp))
