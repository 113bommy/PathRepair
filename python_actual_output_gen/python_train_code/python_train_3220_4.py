N,K=[int(i) for i in input().split()]
X=[int(i) for i in input().split()]
m=10**5
for i in range(n-k+1):
    m=min(m,x[k-1+i]-x[i]+min(abs(x[k-1+i]),abs(x[i])))

print(m)