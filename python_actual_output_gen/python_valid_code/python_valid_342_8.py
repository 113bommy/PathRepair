n,c,k = list(map(int,input().split()))

t = []
for i in range(n):
    t.append(int(input()))
t.sort()
a = t[0]
b = 1
ans = 1
for i in range(1,n):
    if t[i]-a <= k and b < c:
        b += 1
    else:
        ans += 1
        a = t[i]
        b = 0
print(ans)