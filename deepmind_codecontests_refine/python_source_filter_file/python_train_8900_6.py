import math,sys
from sys import stdin, stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def case():
    n=I()
    a=li()
    b=a.copy()
    b.sort()
    d=defaultdict(int)
    print(*b)
    j=0
    ans=0
    for i in range(n):
        if(a[i]==b[j]):
            d[b[j]]+=1
            while(j<n and b[j] in d):
                d[b[j]]-=1
                if(d[b[j]]==0):
                    del(d[b[j]])
                j+=1
                if(j==i+1):
                    ans+=1
                    break
                #print(i,j)
        else:
            d[a[i]]+=1
        #print(d)
    print(ans)



for _ in range(1):
    case()