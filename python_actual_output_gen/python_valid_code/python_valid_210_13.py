n, cur = int(input()), 1
for i in range(1, n):
    cur = (cur + i) % n
    print(cur, end=' ')
