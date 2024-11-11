n, k = input().split()
n, k = int(n), int(k)

arr = input().split()
arr = [int(a) for a in arr]

su = {1}

for i in range(1, 40):
    if k**i < 10**10:
        su.add(k**i)
        continue
    break

#print(su)
d = {0:1}
ans = 0
cumulative_sum = 0
for x in arr:
    cumulative_sum += x
    for s in su:
        if cumulative_sum - s in d:
            ans += d[cumulative_sum-s]
    d[cumulative_sum] = d.get(cumulative_sum, 0) + 1

print(ans)