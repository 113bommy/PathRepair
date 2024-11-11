n = int(input())

a = []

for i in range(n):
    a.append(list(input()))

def check_range(i, j):
    if j - 1 >= 0 and j + 1 < n and i + 2 < n:
        if a[i+1][j-1] == '#' and a[i+1][j+1] == '#' and a[i+1][j] == '#' and a[i+2][j] == '#':
            return False
        return True
    else:
        return False

res = True

for i in range(n):
    for j in range(n):
        if a[i][j] == '#':
            if check_range(i, j):
                a[i][j] = 'X'
                a[i+1][j-1] = 'X'
                a[i+1][j] = 'X'
                a[i+1][j+1] = 'X'
                a[i+2][j] = 'X'
            else:
                res = False
                break

if res:
    print("YES")
else:
    print("NO")

