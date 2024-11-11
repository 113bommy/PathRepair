n,m=map(int,input().split())
D=[1] * (n + 1)
for _ in range(m):
    D[int(input())] = 0
for i in range(n+1):
    if i > 1:
        D[i] = (D[i-1] + D[i-2]) % 1000000007 * D[i]
print(D[i])
