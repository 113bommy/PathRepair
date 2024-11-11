#http://codeforces.com/problemset/problem/870/C
#solved

n = int(input())
todo = [int(input()) for _ in range(n)]
wrong = [1, 2, 3, 5, 7, 11]

for i in todo:
    if i in wrong:
        print(-1)
        continue

    modulo = i % 4

    if modulo == 0 or modulo == 2:
        print(i // 4)
        continue

    elif modulo == 1:
        print((i - 1) // 4 - 1)
        continue

    elif modulo == 3:
        print((i - 3) // 4 - 2)
        continue