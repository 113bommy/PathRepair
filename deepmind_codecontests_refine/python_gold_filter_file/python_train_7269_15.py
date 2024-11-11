N,Y = map(int,input().split())
x,y,z=-1,-1,-1
for i in range(N+1):
    for j in range(i+1):
        if 10000 * (N-i) + 5000 * j + 1000 * (i-j) == Y:
            x,y,z=N-i,j,i-j
print(x,y,z)
