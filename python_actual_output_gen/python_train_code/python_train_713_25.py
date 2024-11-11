n, m, k = [*map(int, input().split())]
if k < n:
    print(k + 1, 1)
    quit()
k -= n
m -= 1
row = n - k // m
if row % 2 == 1:
    col = m + 1 - k % m
else:
    col = k % m + 1
print(row, col)