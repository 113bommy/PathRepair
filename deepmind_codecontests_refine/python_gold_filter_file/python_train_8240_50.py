r = 0
i = int(input())
for r in range (0,i):
    x, y, z = input().split()
    x = int(x)
    y = int(y)
    z = int(z)
    a = (x+y+z)//2
    print(a)