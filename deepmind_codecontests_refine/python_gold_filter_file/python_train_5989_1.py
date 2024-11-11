n = int(input())
a = []
res = 0
for i in range(n):
    a += [input()]
for i in range(n):
    x = 0
    y = 0
    for j in range(n):
        if a[i][j] == 'C':
            x += 1
        if a[j][i] == 'C':
            y += 1
    res += x * (x-1) // 2 + y * (y-1) // 2
print(res)
            
