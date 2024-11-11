import math
import sys
input=sys.stdin.readline
k=math.log(10**11,2)
for _ in range(int(input())):
    n=int(input())
    mins=[]
    for i in range(int(k),-1,-1):
        a=str(2**i)
        idx=0
        res=0
        for x in str(n):
            if x==a[idx]:
                idx+=1
                res+=1
            if idx==len(a):
                break
        mins.append(len(str(n))-res+len(a)-idx)
    mins.append(len(str(n))+1)
    print(min(mins))