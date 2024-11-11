N,K=[int(i) for i in input().split()]
X=[int(i) for i in input().split()]
m=10**5
for i in range(N-K+1):
    m=min(m,x[K-1+i]-x[i]+min(abs(x[K-1+i]),abs(x[i])))

print(m)