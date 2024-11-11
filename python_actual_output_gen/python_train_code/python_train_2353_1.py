import sys
input = sys.stdin.readline
n,p=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
mn=0
mx=200000000
for i in range(n):
    d=a[i]-i
    mn=max(d,mn)
    if i>=p-1:
        d2=a[i]-i+p-1
        mx=min(mx,d2)
print(max(mx-mn,0))
for i in range(mn,mx):
    print(i,end=" ")