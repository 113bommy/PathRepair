n, l, a = map(int, input().split())
if n == 0:
    print(l // a)
    exit()
ar = []
for i in range(n):
    ar.append(list(map(int, input().split())))
ar = sorted(ar, key = lambda x: x[0])
cur = 0
ans = 0
for i in range(n):
    ans += (ar[i][0] - cur)//a
    cur = ar[i][0] + ar[i][1]
ans += (l - cur)//a
print(ans)