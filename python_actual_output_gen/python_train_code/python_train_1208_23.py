n, m = [int(i) for i in input().split()]
a = []
b = []
s = ''
for i in range(n):
    name, ip = [j for j in input().split()]
    a.append((name, ip))

for i in range(m):
    command, ip = [j for j in input().split()]
    b.append((command, ip[0:-1]))

for i in range(n):
    for j in range(m):
        if a[i][1] == b[j][1]:
            print(b[j][0], b[j][1] + ';', '#' + a[i][0])
