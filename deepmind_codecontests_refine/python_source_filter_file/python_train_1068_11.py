import math
t=int(input())
for w in range(t):
    n,k=(int(i) for i in input().split())
    l=[int(i) for i in input().split()]
    s=set(l)
    s1=set()
    if(len(s)==k):
        print(1)
    elif(k==1):
        print(-1)
    elif(k<=len(s)//2):
        print(math.ceil(len(s)-(2*k-1)/(k-1))+2)
    else:
        print(2)