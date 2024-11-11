n,k = tuple(map(int,input().split())) 
N = list(map(int,input().split()))
s = sum(N[0:k])
m = sum(N[0:k])

for i in range(0,n-k):
    s = s-N[i]+N[i+k]
    m = max(m,s)   
print((s+k)/2)
