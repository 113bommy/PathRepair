N = int(input())
prime = [0]*(N+1)
ans = 1
for i in range(2,N+1):
    d = 1
    while i > 1:
        d+=1
        while i % d == 0:
            i = i//d
            prime[d]+= 1
for j in range(N+1):
    ans = ans *(prime[j]+1)%(10**9+7)
print(ans)