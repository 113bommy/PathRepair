from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf
import math
def sp(): return map(int, input().split())
def fun(x):
    return sum(int(i) for i in str(x))
# t=int(input())
t=1
for _ in range(t):
    n=int(input())
    l=list(sp())
    s=sum(l)
    k=l[0]
    dup=[]
    for i in range(n):
        dup.append(l[i])
    # print(*dup)
    l=l[1:]
    l.sort(reverse=False)
    if(k>s//2):print(1);print(1)
    else:
        i=0;
        ans=[];ans.append(k);
        while(k<=s//2 and i<n-1):
            if(ans[0]>=2*l[i]):
                k+=l[i]
                ans.append(l[i])
                # print(k,s)
                i+=1;
            else:
                print(0);exit(0);
        print(i+1)
        # print(*ans)
        for x in range(i+1):  
            for j in range(n):
                if(dup[j]==ans[x]):
                    print(j+1, end=" ")
                    dup[j]=-1
                    break;