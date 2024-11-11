d=list(map(int,input().split()))
d=[0]+d
#def f(a):
#    if (a[1]==a[2]==a[3]==a[4])&(a[5]==a[6]==a[7]==a[8])&(a[9]==a[10]==a[11]==a[12])&(a[13]==a[14]==a[15]==a[16])&(a[17]==a[18]==a[19]==a[20])&(a[21]==a[22]==a[23]==a[24]):
#        return True
#    return False
def ff(g):
    if g[1]==g[2]==g[3]==g[0]:
        return True
    return False
def df(g):
    #a[0],a[1],a[2],a[3]=a[1],a[3],a[0],a[2]
    return [g[1],g[3],g[0],g[2]]
if (ff(d[13:17]))&(ff(d[17:21])): #1
    a=d[:]
    #if (a[5]==a[7])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])
    b=True
    for i in range(1,25,4):
        if a[i]!=a[i+2]:
            b=False
    for i in range(2,25,4):
        if a[i]!=a[i+2]:
            b=False
    if b==False:
        print('NO')
    else:
        if ((a[1]==a[6])&(a[5]==a[10])&(a[9]==a[21])&(a[2]==a[22]))|((a[5]==a[2])&(a[9]==a[6])&(a[24]==a[12])&(a[21]==a[1])):
            print('YES')
        else:
            print('NO')
elif (ff(d[1:5]))&(ff(d[9:13])): #2
    a=d[:]
    a[1:5],a[13:17],a[9:13],a[17:21]=df(a[17:21]),df(a[1:5]),df(a[13:17]),df(a[9:13])
    a[5:9]=df(a[5:9])
    a[21:25]=df(df(df(a[21:25])))
    #if (a[5]==a[7])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])
    b=True
    for i in range(1,25,4):
        if a[i]!=a[i+2]:
            b=False
    for i in range(2,25,4):
        if a[i]!=a[i+2]:
            b=False
    if b==False:
        print('NO')
    else:
        if ((a[1]==a[6])&(a[5]==a[10])&(a[9]==a[21])&(a[2]==a[22]))|((a[5]==a[2])&(a[9]==a[6])&(a[24]==a[12])&(a[21]==a[1])):
            print('YES')
        else:
            print('NO')
elif (ff(d[5:9]))&(ff(d[21:25])): #3
    a=d[:]
    a[1:5],a[9:13]=df(df(df(a[1:5]))),df(a[9:13])
    a[13:17],a[5:9],a[17:21],a[21:25]=a[5:9],a[17:21],a[21:25],a[13:17]
    #a[1:5],a[13:17],a[9:13],a[17:21]=df(a[17:21]),df(a[1:5]),df(a[13:17]),df(a[9:13])
    #a[5:9]=df(a[5:9])
    a[21:25]=df(df(df(a[21:25])))
    #if (a[5]==a[7])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])&(a[]==a[])
    b=True
    for i in range(1,25,4):
        if a[i]!=a[i+2]:
            b=False
    for i in range(2,25,4):
        if a[i]!=a[i+2]:
            b=False
    if b==False:
        print('NO')
    else:
        if ((a[1]==a[6])&(a[5]==a[10])&(a[9]==a[21])&(a[2]==a[22]))|((a[5]==a[2])&(a[9]==a[6])&(a[24]==a[12])&(a[21]==a[1])):
            print('YES')
        else:
            print('NO')
else:
    print('NO')
