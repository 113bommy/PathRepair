N,M=map(int,input().split())
X=sorted(list(map(int,input().split())))
Y=[]
for i in range(M-1):
    y=X[i+1]-X[i]
    Y.append(y)
y=sorted(Y)[::-1]
print(sum(y[N-1:]))