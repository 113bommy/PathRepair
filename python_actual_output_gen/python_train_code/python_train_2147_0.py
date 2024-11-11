N,M = map(int,input().split())
AB = sorted([list(map(int,input().split())) for i in range(N)])
res = 0
for a,b in range(N):
    M -= b
    res += a*b
    if M < 0:
        res += a*M
        break
print(res)