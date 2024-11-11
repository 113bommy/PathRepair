n, m = map(int, input().split())

maximum = 10 ** 5 + 1
prime = [True] * (maximum + 1)
prime[0], prime[1] = False, False
for i in range(2, maximum + 1):
    if (prime[i]):
        for j in range(i + i, maximum + 1, i):
            prime[j] = False

matrix = []
sums = [[0] * n, [0] * m]
ans = 1e9 + 7
for i in range(n):
    row = [int(i) for i in input().split()]
    new_row = []
    for j in range(m):
        num = row[j]
        add = 0
        while ((num <= 10 ** 5) and (not prime[num])):
            add += 1
            num += 1
        new_row.append(add)
        sums[0][i] += add
        sums[1][j] += add
    matrix.append(new_row)
    ans = min(ans, sums[0][i])


for i in range(m):
    ans = min(ans, sums[1][i])


print (ans)
        