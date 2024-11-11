t=int(input())
for i in range(t):
    n=int(input())
    grid=[]
    for j in range(n):
        grid.append(input())
    s1=grid[0][1]
    s2=grid[1][0]
    s3=grid[-2][-1]
    s4=grid[-1][-2]
    if s1==s2==s3==s4:
        print(2)
        print(1,2)
        print(2,1)
    elif s1==s2==s3:
        print(1)
        print(n-1,n)
    elif s1==s2==s4:
        print(1)
        print(n,n-1)
    elif s1==s4==s3:
        print(1)
        print(1,2)
    elif s4==s2==s3:
        print(1)
        print(2,1)
    elif s1==s3:
        print(2)
        print(1,2)
        print(n-1,n)
    elif s1==s4:
        print(2)
        print(1,2)
        print(n,n-1)
    else:
        print(0)