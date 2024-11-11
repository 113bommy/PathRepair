t=int(input())
for i in range(t):
    x1,y1,z1=map(int,input().split())
    x2,y2,z2=map(int,input().split())
    if y2>=z1:
        if x1>=z2:
            print(2*z1)
        else:
            print(2*z1-2*(z2-x1))
    else:
        if x1+(z1-y2)>=z2:
            print(2*y1)
        else:
            print(2*y1-2*(z2-(z1-y2)-x1))