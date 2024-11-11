a,b,c=input().split(' ')
a=int(a)
b=int(b)
c=int(c)
if c==0:
    if a==b :
        print('YES')
    else :
        print('NO')
else :
    if (b-a)%c ==0 and (b-a)//c > 0 :
        print('YES')
    else :
        print('NO')