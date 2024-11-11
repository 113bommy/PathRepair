m, d = map(int, input().split())

cnt = 0
for i in range(d):
    do = i % 10
    dt = i // 10
    if do <= 1 or dt <= 1:
        continue
    if do*dt <= m:
        cnt += 1

print(cnt)
