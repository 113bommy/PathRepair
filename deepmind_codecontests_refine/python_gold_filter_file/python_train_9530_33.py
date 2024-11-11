n = int(input())
a = []
flag = False
for _ in range(n):
    s = [str(s) for s in input().split()]
    s[1] = int(s[1])
    s[2] = int(s[2])
    a.append(s)

for i in range(n):
    if a[i][1] >= 2400 and a[i][2] - a[i][1] >= 1:
        flag = True
        break
print('YES') if flag == True else print('NO')
