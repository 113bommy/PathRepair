n,m=map(int,input().split())

def can(x):
    global n
    if x*(x+1)//2>=n: # / -> // XD
        return True
    return False

if m>=n:
    print(n)
else:
    n=n-m
    st=1
    en=n+5
    mid=0
    ans=0
    while en-st>1:
        mid=(st+en)//2
        if can(mid):
            en=mid
            ans=mid
        else:
            st=mid
    print(m+ans)
