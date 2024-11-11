def check(x,n,m,k):
    a = 0
    if(k-1>x-1):
        a += x*(x-1)//2+k-x
    else:
        a += (2*x-k)*(k-1)//2
    b = 0
    if(n-k>x-1):
        b += x*(x-1)//2 + n-k-x+1
    else:
        b += (2*x-n+k-1)*(n-k)//2
    if(a+b+x<=m):
        return True
    return False

n,m,k = map(int,input().split())
l = 1;h=m
ans = 0
while(l<h):
    mid = (l+h+1)//2
    if(check(mid,n,m,k)):
        l = mid
        ans = mid
    else:
        h = mid-1
print(ans)