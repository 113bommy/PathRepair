    
import math
for _ in range(1):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    for i in range(k):
        cnt=0
        a,b,c=map(int,input().split())
        for j in range(a-1,b):
            if l[j]<l[c-1]:
                cnt+=1
        if cnt+a==c:
            print("YES")
        else:
            print("NO")
        
    