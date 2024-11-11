m, n, x, y = map(int, input().split())
a, b = list(map(int, input().split())), list(map(int, input().split()))
a = [[a[i], i + 1] for i in range(m)]
b = [[b[j], j + 1] for j in range(n)]
a.sort()
b.sort()
ans, j = [], 0
for a0, a1 in a:
    while j < n and b[j][0] + y < a0: j += 1
    if j == n: break
    if b[j][0] - x > a0: continue
    ans.append([a1, b[j][1]])
    j += 1
print(len(ans))
for i in ans:
    print(i[0], i[1])