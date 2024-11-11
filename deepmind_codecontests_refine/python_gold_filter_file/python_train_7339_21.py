l=[]
c=[[],[],[],[],[],[],[],[],[],[]]
for i in range(8):
    l.append(input())
for i in range(8):
    for j in range (8):
        c[i].append(l[j][i])
sw=[]
sb=[]
for i in range (8):
    apw=8
    apb=8
    down=0
    up=0
    for j in range (8):
        if c[i][j]=='W'and apw==8 and down==0:
            apw=j
            down=1
        if c[i][j]=='B'and down==0:
            down=1
        if c[i][7-j]=='B'and apb==8 and up==0:
            apb=j
            up=1
        if c[i][7-j]=='W'and up==0:
            up=1
    sw.append(apw)
    sb.append(apb)
mw=min(sw)
mb=min(sb)
if mb<mw:
    print('B')
else :
    print('A')
