n = int(input())
a = []
for i in range((n*(n-1))//2-1):
    c,d = map(int , input().split())
    a.append([c, d])
d = {}
for i in a:
    if i[0] in d:
        d[i[0]]+=1
    else:
        d[i[0]]=1
    if i[1] in d:
        d[i[1]]+=1
    else:
        d[i[1]] = 1
c = []
for i in d:
    if d[i]!=n-1:
        c.append(i)
win = []
loss = []
win1 = []
loss1 = []
for i in a:
    if i[0] == c[0]:
        win.append(i[1])
    elif i[1] == c[0]:
        loss.append(i[0])
    if i[0] == c[1]:
        win1.append(i[1])
    elif i[1] == c[1]:
        loss1.append(i[0])
flag = 0
for i in win:
    for j in loss1:
        if i == j:
            flag = 1
            print(c[0], c[1])
            break
    if flag:
       break
if not flag:
    for i in loss1:
        for j in win1:
            if i == j:
                print(c[1], c[0])
                flag = 1
                break
        if flag:
            break
if not flag:
    print(c[0],c[1])
