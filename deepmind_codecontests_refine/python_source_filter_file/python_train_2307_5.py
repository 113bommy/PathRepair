n = int(input())
a = list(map(int, input().split()))
for i in range(n):
    a[i] = abs(a[i])
a.sort()
l = 0
r = n - 1
ans = 0
while l < n:
    while r<n and 2*a[l]>=a[r]:
        r+=1
    ans+=(r-l-1)
    l+=1
print(ans)
