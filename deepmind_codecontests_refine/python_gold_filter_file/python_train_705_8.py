f=lambda:[*map(int,input().split())]
n,m=f()
S=[f()[1:] for _ in [0]*m]
p=f()
print(sum(all(sum(i>>~-k for k in S[j])%2==p[j] for j in range(m)) for i in range(2**n)))