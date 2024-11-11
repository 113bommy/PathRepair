n, k = list(map(int, input().split()))
a = sorted(enumerate(list(map(int, input().split()))), key=lambda x: x[1])
res = []
cur = 0
for idx, val in a:
    if cur + val < k:
        cur += val
        res.append(idx + 1)
    else:
        break
print(len(res))
print(*res)

