n = int(input())
if n == 1:
    print(-1)
else:
    print(' '.join(str(i) for i in range(n, 0, -1)))
