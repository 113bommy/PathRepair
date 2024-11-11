t=int(input())
for i in range(0,t,1):
    x,y=map(int,input().split())
    if (x==1 and y!=1) or (x==3 and y>4) or (x==2 and y>3):
        print('NO')
    else:print('YES')
