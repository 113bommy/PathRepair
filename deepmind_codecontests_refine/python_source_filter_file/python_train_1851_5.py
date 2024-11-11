j=0
N,D=map(int,input().split())
for i in range(N):
    X,Y=map(int,input().split())
    if (X**2+Y**2)**0.5<=D:
        j=j+1
print(i)