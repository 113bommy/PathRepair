a,b,c = [int(i) for i in input().split()]
if  ((b-c+a) >= 0) and ((b-c+a) % 2): 
    if ((b-c+a)/2 == (b-c+a)//2):
        y = (b-c+a) // 2
    x = b - y
    z = c - x 
    if (x > -1) and (y > -1) and (z > -1):
        print(y,x,z)
    else:
        print("Impossible")
else:
    print("Impossible")