n = int(input())
print((n + 2) // 2)

row = col = 1
di, dj = 0, 1
for k in range(n):
    print(row, col, sep=" ")
    row += di
    col += dj
    di, dj = dj, di
