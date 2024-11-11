n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))

cnt = dict()
sum = dict()

res = n

for x in a:
    y = x
    cur = 0
    while True:
        if y == 0:
            break
        if y not in cnt:
            cnt[y] = 0
            sum[y] = 0
        if cnt[y] < k:
            cnt[y] += 1
            sum[y] += cur
            if cnt[y] == k:
                res = min(res, sum[y])
        y >>= 1
        cur += 1
print(res)