import sys
input=sys.stdin.readline
n,k=map(int,input().split())
a=list(map(int,input().split()))

for i in range(50):
    ans=[0]*(n)
    for j in range(n):
        l=max(0,j-a[j])
        r=j+1+a[j]
        ans[l]+=1
        if r<n:
            ans[r]-=1
    for z in range(n-1):
        ans[z+1]+=ans[z]
    a=ans
print(" ".join(list(map(str,ans))))