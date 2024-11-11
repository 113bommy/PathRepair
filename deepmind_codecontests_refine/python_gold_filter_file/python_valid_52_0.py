
t=int(input())
from functools import reduce

def sp():
    n=int(input())
    l=[]
    l=list(map(int,input().split()))
    n=max(l)
    l.remove(n)
    k=sum(l)/len(l)
    
    y=n+k
    print(y) 
for i in range(t):
    sp()






