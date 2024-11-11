n = int(input())
mp = {}
for i in range(n):
    x, y, z = map(str, input().split())
    x = x.lower()
    z = z.lower()
    mp[x] = z
ans = 1

for i in mp:
    x = i
    c = 1
    while mp.get(x):
        c = c + 1
        x = mp[x]
    ans = max(ans, c)

print(ans)