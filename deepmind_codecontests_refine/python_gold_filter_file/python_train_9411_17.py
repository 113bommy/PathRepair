a,b,c = map(int, input().split())
if (a+b+c)%2 ==0:
    x = (a+b-c)//2 
    z = (a-b+c)//2
    y = (-a+b+c)//2
    if all(i>=0 for i in [x,y,z]):
        print(x, y, z)
    else:
        print('Impossible')
else:
    print('Impossible')