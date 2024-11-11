t=int(input())
import math
for i in range(t):
    n=int(input())
    a,b,c=list(map(int,input().split()))
    g=input()
    r=g.count('R')
    p=g.count('P')
    s=g.count('S')
    x=min(a,s)+min(p,c)+min(r,b)
    #print(x)
    if x>=math.ceil(n/2):
        print("YES")
        ans=[];j=0
        while j<n:
            if g[j]=='R' and b>0:
                ans+='P'
                b-=1
            elif g[j]=='P' and c>0:
                ans+='S'
                c-=1
            elif g[j]=='S' and a>0:
                ans+='R'
                a-=1
            else:
                ans+='X'
            j+=1
        j=0
        while a!=0:
            if ans[j]=='X':
                ans[j]='R'
                a-=1
            j+=1
        while b!=0:
            if ans[j]=='X':
                ans[j]='P'
                b-=1
            j+=1
        while c!=0:
            if ans[j]=='X':
                ans[j]='S'
                c-=1
            j+=1
        print(''.join(ans))
    else:
        print("NO")
        
