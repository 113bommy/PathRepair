n = int(input())
p = [int(input()) for _ in range(n - 1)]
c = [[] for _ in range(n)]
l = [0 for _ in range(n)]
for i in range(n - 1):
    c[p[i] - 1].append(i + 1)
for i in range(n - 1):
    for u in c[i]:
        if len(c[u]) == 0:
            l[i] += 1
if any(map(lambda i: 1 < len(c[i]) and l[i] < 3, range(n - 1))):
    ans = "No"
else:
    ans = "Yes"
print(ans)
