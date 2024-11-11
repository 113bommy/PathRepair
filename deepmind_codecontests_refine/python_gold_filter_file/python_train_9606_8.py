import math

t=int(input())

for i in range(t):
    n=int(input())
    
    a=[int(x) for x in input().split()]
    l={}
    c=0
    for x in a:
        y=int(math.log2(x))
        if y in l:
            l[y]+=1
        else:
            l[y]=1
    k=0
    for x in l:
        a=l[x]
        k+=int(a*(a-1)/2)
    print(k)
        
        
        
