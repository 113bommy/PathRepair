# cook your dish here
t=int(input())
for i in range(t):
    d=int(input())
    if d==0:
        a=0
        b=0
        print('Y', end=' ')
        print("{r:10.9f},{p:10.9f}".format(r=a,p=b))
    elif 0<d<4:
        print('N')
    else:
        a=(d+(d*d-4*d)**0.5)/2
        b=(d-(d*d-4*d)**0.5)/2
        print('Y', end=' ')
        print("{r:10.9f},{p:10.9f}".format(r=a,p=b))
        
        
        
    