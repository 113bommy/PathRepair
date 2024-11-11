n =int(input())
k=2
x = list(map(int, input().split()))
l = 0
r = 0
ans = 0
d= {}
s=set()
while l <= r < n:
    if len(s) <= k:
        s.add(x[r])
        if x[r] in d:
            d[x[r]] += 1
        else:
            d[x[r]]=1
        if len(s) <= k:
            ans = max(ans, r - l + 1)
        r += 1
    else:
        d[x[l]] -= 1
        if d[x[l]] == 0:
            s.remove(x[l])
        l += 1
print(ans)