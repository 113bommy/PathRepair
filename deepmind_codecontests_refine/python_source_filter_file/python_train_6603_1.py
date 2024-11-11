n = int(input())
data = [list(input()) for _ in range(n)]

mid = n//2
if data[mid][mid]!=data[1][0]:
    print('NO')
    exit(0)
for i in range(n):
    for j in range(n):
        if abs(i-mid)==abs(j-mid):
            if data[i][j]!=data[mid][mid]:
                print('NO')
                exit(0)
        elif data[i][j]!=data[1][0]:
            print('NO')
            exit(0)
print('YES')