n,k = map(int,input().split())
if(k%2):
    x = k//2
else:
    x = k//2-1

if(x>=n):
    print(0)
else:
    z = k-x
    ans = n-z+1
    print(min(x,ans))