n,k = [int(x) for x in input().split()]
count=0
limit = 1000001
prime = [1]*limit
prime[0:2] = [0,0]
for i in range(2,limit):
    if (prime[i]==1):
        for j in range(i*i,limit,i):
            prime[j] = 0
_prime = [int(i)*prime[i] for i in range(1,n+1)]
_prime = list(filter(lambda x: x!=0, _prime))
for i in range(0, len(_prime)-1):
    x = _prime[i]+_prime[i+1]+1
    if x<=n and prime[x]==1:
        count+=1
rs = "YES" if count>=k else "NO"
print(rs)