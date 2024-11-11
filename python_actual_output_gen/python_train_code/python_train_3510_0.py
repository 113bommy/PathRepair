n, k = map(int, input().split())
nums = list(map(int, input().split()))
counts = [{} for _ in range(11)]
for n in nums:
    a = n
    for i in range(10):
        r = a % k
        try:
            counts[i][r] += 1
        except KeyError:
            counts[i][r] = 1
        a *= 10
res = 0
for i in nums:
    wo = str(i)
    le = len(wo)
    mimo = (k-(i % k)) % k
    if mimo in counts[le]:
        res += counts[le][mimo]
        if int(wo+wo) % k == 0:
            res -= 1
print(res)
