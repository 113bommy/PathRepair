i=0
N,D=map(int,input().split())
for i in range(N):
    X,Y=map(int,input().split())
    if (X**2+Y**2)**0.5<=D:
        i=i+1
print(i)