n=int(input())
r=[int(input()) for i in range(n)]
maxv=r[1]-r[0]
minv=r[0]
for i in range(1,n-1):
    maxv=max(maxv,r[i]-minv)
    minv=min(minv,r[i])
print(maxv)
