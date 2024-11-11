s, n = list(map(int, input().split()))
flag = True
l = []
for i in range(n):
    t = tuple(map(int, input().split()))
    l.append(t)
l.sort()
for i in range(n):
    if s < l[i][0]:
        flag = False
    else:
        s = s + l[i][1]
if flag == True:
    print('YES')
else:
    print('NO')
