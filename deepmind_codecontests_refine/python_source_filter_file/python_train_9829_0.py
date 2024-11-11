n, m = map(int, input().split())
t = []
min = 10 ** 9
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(m):
        if a[j] == 1:
            if i == 0 or i == n - 1 and j == 0 or j == m - 1:
                if 2 < min:
                    min = 2
            else:
                if 4 < min:
                    min = 4
print(min)
