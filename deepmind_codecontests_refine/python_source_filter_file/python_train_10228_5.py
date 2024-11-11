for u in range(int(input())):
    x,y=map(int,input().split())
    if((x%2==0 and y%2==1) or (x%2==0 and y%2==1)):
        print("NO")
    elif(x<y*y):
        print('NO')
    else:
        print("YES")
