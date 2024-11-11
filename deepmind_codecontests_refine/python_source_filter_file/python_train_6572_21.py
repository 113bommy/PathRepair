n = int(input())
inlist = []
for i in range(n):
    inlist.append(list(input()))
count = 0
if n >= 3:
    for i in range(1, n - 1):
        for j in range(1, n - 1):
            if inlist[i][j] == 'x' and inlist[i - 1][j - 1] == 'x' and inlist[i - 1][j + 1] == 'x' and inlist[i + 1][j - 1] == 'x' and inlist[i + 1][j + 1] == 'x':
                count += 1
else:
    count = 0
print(count)