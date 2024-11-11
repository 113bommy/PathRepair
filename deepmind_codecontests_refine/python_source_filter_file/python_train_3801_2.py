n = int(input())
ans = []
for i in range(1, 1442250 + 10):
    t = i * (i + 1) // 2
    j, mod = divmod(n + (i - 1) * t // 3, t)
    if i >= j:
        break
    if mod == 0:
        ans.append((i, j))
        if i != j: ans.append((j, i))
ans.sort()
print(len(ans))
for x, y in ans:
    print(x, y)
