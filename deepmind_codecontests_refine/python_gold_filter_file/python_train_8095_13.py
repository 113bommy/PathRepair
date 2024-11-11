N = int(input())
z = []
zz = []
for _ in range(N):
    x, y = map(int, input().split())
    zz.append(x-y)
    z.append(x+y)
z.sort()
zz.sort()
ans = z[-1]-z[0]
ans = max(ans, zz[-1]-zz[0])

print(ans)