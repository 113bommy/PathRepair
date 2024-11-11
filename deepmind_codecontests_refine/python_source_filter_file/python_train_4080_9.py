n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
vals = [[] for i in range(200 * 1000 + 11)]
for i in a:
    cur = 0
    x = i
    while x > 0:
        vals[i].append(cur)
        cur += 1
        x //= 2
answer = 1000000000
for i in range(200 * 1000 + 11):
    vals[i].sort()
    if len(vals[i]) < k:
        continue
    answer = min(answer, sum(vals[i][:k]))
print(answer)
