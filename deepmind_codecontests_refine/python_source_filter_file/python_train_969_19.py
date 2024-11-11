n = int(input())
m = list(map(int, input().split()))

cnt = -2
min_val = 10000
max_val = -1

for v in m:
    if v < min_val:
        cnt += 1
        min_val = v
    if v > max_val:
        cnt += 1
        max_val = v

print(cnt)