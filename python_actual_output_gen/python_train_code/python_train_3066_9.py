n = int(input())
cur = 2
for i in range(1, n + 1):
    new = i * (i + 1) ** 2
    cnt = (new - cur) // i
    cur = i * (i + 1)
    print(cnt)
