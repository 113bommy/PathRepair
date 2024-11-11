n = int(input())
starting = 1
ending = n * n
for _ in range(n):
    print(*[starting + i if i < n // 2 else ending + i - n + 1for i in range(n)])
    starting += n // 2
    ending -= n // 2
