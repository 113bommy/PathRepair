def win(a,b,c,d):
    if a>c and b>d:  return 1
    return 0
a={}
b={}
for i in range(2):           
    a[i*2],b[i*2]=map(int,input('').split())
    a[1+i*2],b[1+i*2]=map(int,input('').split())
    h=b[i*2]
    b[i*2]=b[1+i*2]
    b[1+i*2]=h
if (win(a[0],b[0],a[2],b[2])*win(a[0],b[0],a[3],b[3])==1) or (win(a[1],b[1],a[2],b[2])*win(a[1],b[1],a[3],b[3])==1):
    print ('Team 1')
    exit()
if (win(a[2],b[2],a[0],b[0])*win(a[2],b[2],a[1],b[1])==1) or (win(a[3],b[3],a[0],b[0])*win(a[3],b[3],a[1],b[1])==1) or (win(a[2],b[2],a[0],b[0])*win(a[3],b[3],a[1],b[1])==1) or (win(a[2],b[2],a[1],b[1])*win(a[3],b[3],a[0],b[0])==1):
    print ('Team 2')
    exit()
print('Draw')


