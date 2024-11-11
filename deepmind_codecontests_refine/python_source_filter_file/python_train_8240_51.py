n=int(input())
for i in range(0,n):
    x,y,z=[int(i) for i  in input().split()]
    if (x+y+z)%2==0:
        print((x+y+z)/2)
    else:
        print((x+y+z)//2)
