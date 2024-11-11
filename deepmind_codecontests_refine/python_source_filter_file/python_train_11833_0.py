N = int(input())
map1 = []
map2 = []
for _ in range(N):
    map1 += [input()]

for _ in range(N):
    map2 += [input()]

equal1 = True
equal2 = True
equal3 = True
equal4 = True
equal5 = True
equal6 = True
equal7 = True
equal8 = True

for i in range(N):
    for j in range(N):
        if map1[i][j] != map2[i][j]:
            equal1 = False
        if map1[i][j] != map2[j][N - i - 1]:
            equal2 = False
        if map1[i][j] != map2[N - i - 1][N - j - 1]:
            equal3 = False
        if map1[i][j] != map2[N - j - 1][N - i - 1]:
            equal4 = False
        if map1[i][j] != map2[i][N - j - 1]:
            equal5 = False
        if map1[i][j] != map2[N - i - 1][j]:
            equal6 = False
        if map1[i][j] != map2[N - j - 1][i]:
            equal6 = False
        if map1[i][j] != map2[j][i]:
            equal6 = False
            
if equal1 or equal2 or equal3 or equal4 or equal5 or equal6 or equal7 or equal8:
    print('yes')
else:
    print('no')

