N,K=[int(i) for i in input().split()]
X=[int(i) for i in input().split()]
m=10**9
for i in range(N-K+1):
    m=min(m,X[K-1+i]-X[i]+min(abs(X[K-1+i]),abs(X[i])))

print(m)