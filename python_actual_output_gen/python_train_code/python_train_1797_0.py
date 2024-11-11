N,D=map(int,input().split())
X=[list(map(int,input().split())) for i in range(N)]
c=0
for i in range(N-1):
    for j in range(i+1,N):
        c += (sum((a-b)**2) for a,b in zip(X[i],X[j]))**0.5.is_integer()
print(c)