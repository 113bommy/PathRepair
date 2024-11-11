n = int(input())
if n == 1 or n == 2:
    print(-1)
else:
    arr = [x for x in range(2, n)]
    arr.append(1)
    print(*arr)