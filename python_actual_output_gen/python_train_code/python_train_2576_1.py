def findpoweroftwo(n):
    for i in range(1,51):
        if 2**i==n:
            return i
        
n,k=map(int,input().split())
if k%2==1:
    exit(print(-1))
for i in range(n-1,0,-1):
    if k&(k-1)==0:
        exit(print(findpoweroftwo(k) + 1))
    k=abs(2**i-k)    
    
        