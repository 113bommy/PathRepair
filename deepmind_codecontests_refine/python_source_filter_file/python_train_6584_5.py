t=int(input())
import math
for i in range(t):
#map(int,input().strip().split())
    n,k=map(int,input().strip().split())
    if n>=k:
        q=[]
        for i in range(1,int(math.sqrt(n)+1)):
            if n%i==0:
                q.append(i)
                q.append(n//i)
        f=[]
        for i in range(len(q)):
            if q[i]<=k:
                f.append(q[i])
        print(n//max(f))
        
    if n<k:
        print(n)
