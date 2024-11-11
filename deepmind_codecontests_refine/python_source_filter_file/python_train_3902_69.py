m,n = map(int, input().split())
a = [['#'] * n for i in range(m)]
for i in range(1,m,4):
    for j in range(n-1):
        a[i][j] = '.'
for i in range(3,m,4):
    for j in range(1,n):
        a[i][j] = '.'


for i in range(len(a)):
    print(*a[i])