t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    sum = []
    if k == 1:
        print(1)
    elif n == 1:
        print(2)
    elif k == 2:
        print(n + 1)
    else:
        for i in range(k):
            tmp = [0]*(n+1)
            sum.append(tmp)
        for i in range(n + 1):
            sum[0][i] = 1

        for i in range(1, k):
            for j in range(n + 1):
                if j == 0:
                    sum[i][j] = 1

                else:
                    sum[i][j] = (sum[i][j - 1] + sum[i - 1][n - j]) % (10**9+7)
        print(sum[-1][-1])