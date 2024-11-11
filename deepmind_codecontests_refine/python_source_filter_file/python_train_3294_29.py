import math
for _ in range(int(input())):
    n,m=map(int,input().split())
    k=[int(i) for i in input().split()]
    start=k[0]
    maxcount=0
    for x in k[1:]:
        maxcount=max(math.ceil((x-start)/2)+1,maxcount)
        start=x
    
    maxcount=max(k[0],maxcount)
    maxcount=max(n-k[-1]+1,maxcount)
    
    print(maxcount)