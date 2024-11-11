n,k = map(int, input().split())
a = []
for _ in range(n):
    a.append(list(map(int, input().split())))
a.sort(key=lambda x: (-x[0],x[1]))
ans = 1
k-=1
l=k-1
r=k+1
while l>=0 and a[l]==a[k]:
        ans+=1
        l-=1
while r<n and a[r]==a[k]:
        ans+=1
        r+=1
print(ans)

     