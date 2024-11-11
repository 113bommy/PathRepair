n = int(input())
x = int(input())
 
a = [0]*3
a[x] = 1
 
n = n%6
 
if n==0:
    print(a.index(1))
elif n==1:
    a[0], a[1] = a[1], a[0]
    print(a.index(1))
elif n==2:
    a[0], a[1] = a[1], a[0]
    a[2], a[1] = a[1], a[2]
    print(a.index(1))
elif n==3:
    a[0], a[2] = a[2], a[0]
    print(a.index(1))
elif n==4:
    a[0], a[1] = a[1], a[0]
    a[0], a[2] = a[2], a[0]
    print(a.index(1))
elif n==5:
    a[2], a[1] = a[1], a[2]
    print(a.index(1))