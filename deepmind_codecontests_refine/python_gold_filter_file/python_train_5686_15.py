n = int(input())
pr = []
flag = True
for i in range(n):
    pr.append(tuple(map(int,input().split())))
pr.sort()
tel1, tel2 = -1, -1
flag = True
for i in range(n):
    if tel1 < pr[i][0]:
        tel1 = pr[i][1]
    elif tel2 < pr[i][0]:
        tel2 = pr[i][1]
    else:
        flag = False
        break
if flag:
    print("YES")
else:
    print("NO")