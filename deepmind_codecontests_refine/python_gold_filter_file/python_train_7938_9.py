a,b,c,d = map(int,input().split())
for i in range(d,0,-1):
    print(c,i)
for i in range(d+1,b+1):
    print(c,i)
flag=1
for j in range(b,0,-1):
    if flag==1:
        for i in range(c-1,0,-1):
            print(i,j)
        flag*=-1
    else:
        for i in range(1,c):
            print(i,j)
        flag*=-1
flag=1
for i in range(1,b+1):
    if flag==1:
        for j in range(c+1,a+1):
            print(j,i)
        flag*=-1
    else:
        for j in range(a,c,-1):
            print(j,i)
        flag*=-1
