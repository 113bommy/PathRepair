n = int(input())
pole = [['*' for x in range(n)] for y in range(n)]

sred = n//2
for i in range(n):
    if i<=sred:
        for j in range(sred-i, sred+1+i):
            pole[i][j] = 'D'
    else:
        for j in range(i-sred, n-(i-sred)):
            pole[i][j] = 'D'
    # pole[i][sred] = 'D'
    # pole[i][i] = 'D'
    # pole[i][n] = 'D'


for elem in pole:
    print(*elem)
