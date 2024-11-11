from sys import stdin
for _ in range(int(stdin.readline())):
    n,m = map(int, stdin.readline().split())
    maps = []
    ans = 0
    totals = [0] * (n + m - 1)
    ones = [0] * (n + m - 1)
    zeros = [0] * (n + m - 1)
    for i in range(n):
        array = list(map(int, stdin.readline().split()))
        for j in range(m):
            totals[i + j] += 1
            if array[j] == 1:
                ones[i + j] += 1
            else:
                zeros[i + j] += 1
    for i in range((n + m - 2) // 2):
        ans += min(ones[i] + ones[n + m - 2 - i], zeros[i] + zeros[n + m - 2 - i])
    print(ans)