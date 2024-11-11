n, k = map(int, input().split())
aa = list(map(int, input().split()))

inf = 10 ** 9 * 15
ans = inf
for bits in range(2 ** n):
    selected = set()
    for shift in range(n):
        if bits & (1 << shift) > 0:
            selected.add(shift)

    if len(selected) < k:
        continue
    highest = aa[0]
    cost = 0

    for i in range(1, n):
        if highest < aa[i]:
            highest = aa[i]
        else:
            if i in selected:
                highest += 1
                cost += highest - aa[i]
    ans = min(ans, cost)
print(ans)
