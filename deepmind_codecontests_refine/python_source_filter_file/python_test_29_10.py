import math
t=int(input())
while(t>0):
    t-=1
    n=int(input())
    l=list(map(int,input().split()))
    #a,b,c=map(int,input().split())
    zero=l.count(0)
    one=l.count(1)
    print(zero*one)
