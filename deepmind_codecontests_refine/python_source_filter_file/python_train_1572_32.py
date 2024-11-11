n=int(input())
a=list(map(int, input().split()))
a.sort()
minn=10000000000000
for i in range(n):
    minn=min(minn, a[i+n-1]-a[i])
if n==1:
    print(0)
else:
    print(min(((a[n-1]-a[0])*(minn)),(a[n-1]-a[0])*(a[2*n-1]-a[n])))