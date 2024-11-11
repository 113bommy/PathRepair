
n=int(input())

x,y=1,1
z=-1

for i in range(0,n+1):
    if y>n:
        print(i-1)
        break

    z=x+y
    x=y
    y=z
