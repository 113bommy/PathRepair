i = 0
q = int(input())
 
for i in range (0,q):
    x, y, z = input().split()
    x = int(x)
    y = int(y)
    z = int(z)
    a = (x+y+z)//2
    print(a)