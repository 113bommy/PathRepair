n = int(input())

a = [list(map(int, input().split())) for _ in range(n)]

s1 = sum(a[i][i] for i in range(n))

s2 = sum(a[i][n - 1 - i] for i in range(n))

s3 = sum(a[i][n // 2] for i in range(n))

s4 = sum(a[n // 2][i] for i in range(n))

print(s1 + s2 + s3 + s4 - 3 * a[n //2][n // 2])
