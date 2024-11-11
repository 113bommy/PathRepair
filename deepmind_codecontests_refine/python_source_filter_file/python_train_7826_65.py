import math
def ii(): return int(input())
def fi(): return float(input())
def si(): return input()
def mi(): return map(int,input().split())
def msi(): return input().split()
def li(): return list(mi())
def isplli(n):
    for i in range(2,(n**(1//2)+1)):
        if(n%i==0):
            return 0
    return 1

t=ii()
while(t):
    f=0
    t-=1
    n,m=mi() 
    p=n-m
    #print(p)
    c=0
    for i in range(p,-1,-1):
        if(isplli(i)):
            if(p%i==0):
                #print(i)
                print("YES")
                f=1
                break
    if(f==0):
        print("NO")
