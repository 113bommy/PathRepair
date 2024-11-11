import math
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    ans=n
    if(k>=n):
        print(1)
    else:
        for j in range(1,int(math.sqrt(n)+1)):
            if(n%j==0):
                if(j<=k):
                    ans=min(ans,n//j)
                if(n//j<=k):
                    ans=min(j,ans)
        print(ans)