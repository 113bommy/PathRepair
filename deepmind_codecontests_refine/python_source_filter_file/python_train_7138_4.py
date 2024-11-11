  
def get_m(i):
    lis = i.split(' ')
    return int(lis[0])

n = int(input())
chk = 0
chk2 = 1
sam=0
direc=[]
for i in range(n):
    direc.append(input())
if 'South' in direc[0]:
    chk=1

for i in direc:
    c=0
    d=0
    if 'South' in i:
        c = get_m(i)
    elif 'North' in i:
        d = get_m(i)
    sam =(sam-d+c)    
    if d>20000 or c>20000 or 20000<sam<0:
        chk2=0
    elif sam==0 and direc[direc.index(i)]!=direc[-1]:
        if 'South' in direc[(direc.index(i))+1]:
            chk2*= 1
        else:
            chk2*=0
    elif sam==20000 and direc[direc.index(i)]!=direc[-1]:    
        if 'North' in direc[(direc.index(i))+1]:
            chk2*= 1
        else:
            chk2*=0
            
if chk==1 and chk2==1 and sam==0:
    print('YES')
else:
    print('NO')