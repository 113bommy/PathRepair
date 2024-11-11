num = [int(x) for x in input().split(' ')]
n, m = num[0], num[1]
table1 = list()
table2 = list()
for i in range(n):
    num = [int(x) for x in input().split(' ')]
    table1.append(num)
test = table1
max_col = len(test)
max_row = len(test[0])
cols = [[] for i in range(max_col)]
rows = [[] for i in range(max_row)]
fdiag = [[] for i in range(max_col + max_row - 1)]
for y in range(max_col):
    for x in range(max_row):
        cols[y].append(test[y][x])
        rows[x].append(test[y][x])
        fdiag[x+y].append(test[y][x])
dig1 = fdiag
for i in range(n):
    num = [int(x) for x in input().split(' ')]
    table2.append(num)
test = table2
max_col = len(test)
max_row = len(test[0])
cols = [[] for i in range(max_col)]
rows = [[] for i in range(max_row)]
fdiag = [[] for i in range(max_col + max_row - 1)]
for y in range(max_col):
    for x in range(max_row):
        cols[y].append(test[y][x])
        rows[x].append(test[y][x])
        fdiag[x+y].append(test[y][x])
dig2 = fdiag
f = 0
for i in range(m + n - 1):
    if set(dig1[i]) != set(dig2[i]):
        f = 1
        break
if f == 1:
    print('NO')
else:
    print('YES')
