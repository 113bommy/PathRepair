n = int(input())
if n % 2 == 1:
    print(-1, end=' ')
else:
    for i in range(1, n + 1, -1):
        print(i, end=' ')