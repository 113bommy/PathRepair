import math,sys
from collections import Counter, defaultdict, deque
from sys import stdin, stdout
input = stdin.readline
li = lambda:list(map(int,input().split()))

def factors(g):
    fact=[]
    for i in range(1,int(math.sqrt(g))+1):
        if(g%i==0):
            if(i*i==g):
                fact.append(i)
            else:
                fact.append(i)
                fact.append(g//i)
    fact.sort(reverse=True)
   # print(*fact)
    return(fact)

def case():
    a,b=li()
    g=math.gcd(a,b)
   # print(g)
    fact=factors(g)
    q=int(input())
    for i in range(q):
        l,r=li()
        flag=0
        for j in range(len(fact)):
            if(fact[j]<=r and fact[j]>=l):
                print(fact[j])
                flag=1
                break
        if(not flag):
            print(-1)


for _ in range(1):
    case()