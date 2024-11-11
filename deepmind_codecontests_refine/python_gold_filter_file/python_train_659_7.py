y,k,n=[int(i) for i in input().split()]
z=y
y=k-(y%k)
if y+z>n:
    print(-1)
else:
    while (z+y)%k==0 and y+z<=n:
        print(y,end=' ')
        y+=k
        
