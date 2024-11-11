def euclid(data):
    a=data[0]
    for b in data[1:]:
        if(b<a):
            a,b=b,a
        while(1):
            r=b%a
            if(r==0):
                break
            else:
                b=a
                a=r
    return a



la,ra,ta=map(int,input().split())
lb,rb,tb=map(int,input().split())

if(la < lb):
    la,lb=lb,la
    ra,rb=rb,ra
    ta,tb=tb,ta

gcd=euclid([ta,tb])
tmp=(la-lb) - gcd*((la - lb)//gcd)

print( max( [0, min([ra-la+tmp,rb-lb]) -tmp +1 , min([ra-la,rb-lb + gcd-tmp]) -(gcd - tmp) +1]))
