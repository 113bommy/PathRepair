n,m=map(int,input().split())

for i in range(1,n):
    if i%2==1:
        for j in range(0,m):
            print("#",end='')
    else:
        if i%4==0:
            print("#",end='')
            for j in range(1,m):
                print(".",end='')
        else:
            for j in range(1,m):
                print(".",end='')
            print("#",end='')
    print()