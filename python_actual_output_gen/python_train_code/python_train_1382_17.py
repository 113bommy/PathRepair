a,b = map(int,input().split())

minutes=0
cha=True
chb=False

stop=False

while not stop:
    if a==0 or b==0:
        stop=True
        break
    if a==1 and b==1:
        stop=True
        break
    if a<2 and b>1:
        cha=True
        
        chb=not cha
        
    if b<2 and a>1:
        chb=True
        
        cha= not chb
        
    if cha:
        a+=1
        b-=2
    else:
        a-=2
        b+=1
    if not stop:
        minutes+=1


print( str(minutes))

    