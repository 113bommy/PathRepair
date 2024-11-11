n,k = map(int,input().split())
a = [i for i in range(1,n+1)]
ans = []
l = 0
r = n-1
while l<r:
    ans.append(a[l])
    ans.append(a[r])
    l+=1
    r-=1
if l<=r: 
    ans.append(a[l])
ans = ans[:k]
if k%2==1: 
    ans += a[k//2+1:k//2+1 + n-k]
else: 
    ans += a[k//2:k//2 + n-k][::-1]
print(*ans)