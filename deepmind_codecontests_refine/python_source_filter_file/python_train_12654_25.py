n = int(input())
if n==1:
    x = input()
    print(1)
    exit()
row = set()
a = []
for _ in range(n):
    a.append(list(map(int,input().split())))

for i in range(n):
    if 0 not in a[i]:
        total = sum(a[i])
    else:
        ind = a[i].index(0)
        x = i
        y = ind
        val = sum(a[i])

a[x][y] = (total - val)
if a[x][y] == 0:
    print(-1)
    exit()

for i in range(n):
    row.add(sum(a[i]))
if len(row)!= 1:
    print(-1)
    exit()

diag1 = [ a[i][i] for i in range(n) ]
diag2 = [ row[-i-1] for i,row in enumerate(a)]
d1 = sum(diag1)
d2 = sum(diag2)

if d1 == d2 == total:
    pass
else:
    print(-1)
    exit()

columns = [sum(row[i] for row in a) for i in range(len(a[0]))]
if len(set(columns))!=1:
    print(-1)
    exit()


print(a[x][y])
