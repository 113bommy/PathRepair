def solve(n, m, a):
    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                if i == 0 or j == 0 or  i == n-1 or i == m-1:
                    return 2
    else:
        return 4

n, m = map(int, input().split())
a = []
for i in range(n):
    b = list(map(int, input().split()))
    a.append(b)
print(solve(n, m, a))
