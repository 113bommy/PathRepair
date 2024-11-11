N,Y = map(int,input().split())
x,y,z=-1,-1,-1
for i in range(N):
    for j in range(i):
        if 10000 * (N-i) + 5000 * j + 1000 * (i-j) == Y:
            x,y,z=N-i,j,i-j
print(x,y,z)