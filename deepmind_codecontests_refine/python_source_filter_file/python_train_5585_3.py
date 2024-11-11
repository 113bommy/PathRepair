n, u = list(map(int, input().split()))
e = list(map(int, input().split()))
max_eff = -1
j = 0
for i in range(n):
    while j < n and e[j] <= e[i] + u:
        j += 1
    if i + 2 <= j:
        max_eff = max(max_eff, (e[j - 1] - e[i + 1]) / (e[j - 1] - e[i]))
print(max_eff)