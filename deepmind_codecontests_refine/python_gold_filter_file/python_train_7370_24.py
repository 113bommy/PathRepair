from collections import Counter
n = int(input())
a = []
ans = []
if n == 1:
    print(1)
    exit()
for _ in range(n):
    x, y = map(int, input().split())
    a.append([x, y])
a.sort()
for i in range(n):
    for j in range(i + 1, n):
        p = a[i][0] - a[j][0]
        q = a[i][1] - a[j][1]
        ans.append(str(p) + " " + str(q))
print(n - max(Counter(ans).values()))