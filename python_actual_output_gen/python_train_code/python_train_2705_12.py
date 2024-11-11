n = int(input())
xlt = []
for i in range(n):
    xi,li = map(int,input().split())
    xlt.append((xi+li,xi-li))
xlt.sort()
ans = 0
x = -float("INF")
for i in range(n):
    if x <= xlt[i][1]:
        ans += 1
        x = xlt[0][0]
print(ans)