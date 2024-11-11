import math
def getint():
    return [int(i) for i in input().split()]
def getstr():
    return [str(i) for i in input().split()]
#--------------------------------------------------------------------------
def solve():
    n,u,v=getint()
    a=getint()
    flag=1
    ans=0
    for i in range(n-1):
        if abs(a[i+1]-a[i])>=2:
            flag=0
            break
        if a[i+1]-a[i]==0:
            ans+=1
    if flag==0:
        print(0)
    else:
        if ans==n-1:
            print(min(u+v,u*v))
        else:
            print(min(u,v))
                
                
#--------------------------------------------------------------------------
for _ in range(int(input())):
    solve()
