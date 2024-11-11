n, k = map(int ,input().split())
win = [[False]*(n+1) for _ in range(n+1)]
count = 0

if ((n * (n - 1)) >> 1) < (n * k):
    print(-1)
else:
    for i in range(1, n+1):

        current = k

        for j in range(1, n+1):
            if i != j and not win[j][i]:
                win[i][j] = True
                current -= 1
                count += 1
            if current == 0:
                break

    print(count)
    for i in range(1, n+1):
        for j in range(1, n+1):
            if win[i][j]:
                print(i, j)
