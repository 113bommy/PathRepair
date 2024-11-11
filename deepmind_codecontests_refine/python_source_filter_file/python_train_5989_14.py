n = int(input())
a = list()
for i in range(n):
    a.append(input())
mx = 0
for i in range(n):
    count = 0
    for j in range(n):
        if(a[i][j] == "C"):
            count += 1
    mx += count * (count - 1) / 2
for i in range(n):
    count = 0
    for j in range(n):
        if(a[j][i] == "C"):
            count += 1
    mx += count * (count - 1) / 2
print(mx)
