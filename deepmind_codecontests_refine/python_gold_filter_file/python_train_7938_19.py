#Codeforces1395B
z = input().split()
n = int(z[1])
m = int(z[0])
x = int(z[2])
y = int(z[3])
print(x, y)
for i in range(m):
    if i + 1 != x:
        print(i + 1, y)
x = m - 1
for i in range(n):
    if i + 1 != y:
        print(x + 1, i + 1)
        for j in range(m):
            if j != x:
                print(j + 1, i + 1)
        if x != m - 1:
            x = m - 1
        else:
            x = m - 2
