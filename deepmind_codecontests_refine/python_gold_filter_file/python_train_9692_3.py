n, m = map(int, input().split())
matr = []
ma = []

for i in range(n): matr.append(input())

for i in range(n):
    for j in range(m):
        if matr[i][j] == 'B':
            ma.append([i, j])

maxi, maxj, mini, minj = -1, -1, 116, 116
if len(ma) == 1:
    print(ma[0][0] + 1, ma[0][1] + 1)
    exit()
for i in range(len(ma)):
    maxi = max(maxi, ma[i][0])
    mini = min(mini, ma[i][0])
    maxj = max(maxj, ma[i][1])
    minj = min(minj, ma[i][1])

print((maxi + mini) // 2 + 1, (minj + maxj) // 2 + 1)

            
