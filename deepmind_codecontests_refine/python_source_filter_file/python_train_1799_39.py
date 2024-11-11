import math
t=int(input())
for q in range(0,t):
    n=int(input())
    curr=1
    i=2
    sum=0
    ans=0
    while sum<n:
        cal=((curr)*(curr+1))//2
        if (sum+cal)<=n:
            sum+=curr
            curr+=i
            i=i*2
            ans+=1
        else:
            break
    print(ans)