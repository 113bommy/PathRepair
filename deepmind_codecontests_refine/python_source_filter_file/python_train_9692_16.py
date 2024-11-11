a = list(input().split(' '))
n , m = int(a[0]), int(a[1])
a = []
for _ in range(n):
    a.append(list(input()))
x = 0
x_begin, y_begin = -1, -1
for i in range(n):
    res = 0
    for j in range(n):
        if a[i][j] == 'B':
            if y_begin == -1:
                y_begin = j
            res += 1
    if x == 0:
        x = max(x, res)
for j in range(m):
    for i in range(n):
        if a[i][j] == 'B':
            if x_begin == -1:
                x_begin = i
print(x_begin + x//2 + 1, y_begin + x//2 + 1)
        
