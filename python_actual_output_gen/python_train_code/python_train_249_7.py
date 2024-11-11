n, d = map(int, input().split())
c = d
x = list(map(int, input().split()))
x.sort()
cur_cnt, max_cnt = 1, 0
for i in range(n - 1):
    cur_cnt = 1
    for j in range(i + 1, n):
        if x[j] - x[i] <= d:
            cur_cnt += 1
        else:
            if cur_cnt > max_cnt:
                max_cnt = cur_cnt
            cur_cnt = 1
    max_cnt = max(cur_cnt, max_cnt)
print(n - max_cnt)
