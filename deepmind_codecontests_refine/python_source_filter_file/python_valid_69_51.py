from math import *
from sys import *
power=[]
val=1
for i in range(40):
    power.append(str(val))
    val*=2
for _ in range(int(stdin.readline())):
    n=int(stdin.readline())
    y=str(n)
    ans=maxsize
    for hello in range(40):
        x=power[hello]
        cnt=0
        start=0
        for i in range(len(x)):
            s=x[i]
            pos=-1
            for j in range(start,len(y)):
                if s==y[j]:
                    pos=j
                    break
            if pos==-1:
                break
            start=pos+1
            cnt+=1
        val=len(y)-cnt+(len(x)-cnt)
        ans=min(ans,val)
    print(ans)