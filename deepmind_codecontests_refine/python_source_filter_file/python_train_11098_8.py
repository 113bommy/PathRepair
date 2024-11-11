a,b=input().split()
n=int(input())
l=['v','<','^','>']
i=l.index(a)
j=l.index(b) 
if (j-i+4)%4==0 or (j-i+4)%4==2:
    print('udefined')
elif (j-i+4)%4==n%4:
    print('cw')
else:
    print('ccw')      