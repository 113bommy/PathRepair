def getXorSuffix(i, n, xor):
    res = 0 if (n//(i+1)) % 2 == 0 else xor[i]
    return res^xor[n%(i+1)]

n = int(input())
p = [int(x) for x in input().split()]

xor = [0 for i in range(n+1)]
for i in range(1, n+1):
    xor[i] = i^xor[i-1]

ans = 0
for i in range(len(p)):
    ans ^= p[i]^getXorSuffix(i,n,xor)
print(ans)