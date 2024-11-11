x,y=map(int,input().split())
if y>=2*x and y<=4*x and y%6==0:
    print("YES")
else:
    print('NO')