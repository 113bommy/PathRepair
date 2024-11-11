def myc(a,b,c,d,e,f):
    return str(iph[a][b]+iph[c][d]+iph[e][f])
iph=[]
for i in range(4):
    iph.append(str(input()))
ipv=[]
b=0
for i in range(4):
    ipv.append(str(iph[0][i]+iph[1][i]+iph[2][i]+iph[3][i]))
for i in iph:
    if 'x.x' in i or 'xx.' in i or '.xx' in i:
        b=1
    if 'ooo' in i:
        b=2
        break
if b!=2:
    for i in ipv:
        if 'x.x' in i or 'xx.' in i or '.xx' in i:
            b=1
        if 'ooo' in i:
            b=2
            break
if b!=2:
    ipd=[myc(0,0,1,1,2,2),myc(1,1,2,2,3,3),myc(1,0,2,1,3,2),myc(0,1,1,2,2,3),
         myc(0,2,1,1,2,0),myc(0,3,1,2,2,1),myc(1,2,2,1,3,0),myc(1,3,2,2,3,1)]
    for i in ipv:
        if 'x.x' in i or 'xx.' in i or '.xx' in i and b==0:
            b=1
        if 'ooo' in i:
            b=2
            break
if b==0 or b==2:
    print('NO')
else:
    print('YES')
