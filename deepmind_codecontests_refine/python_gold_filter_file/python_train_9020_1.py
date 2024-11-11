def reconst(pos):
    if pos == 0:
        return
    reconst(prev[pos-1])
    print(pos, end = ' ')

n = int(input())
v = [int(x) for x in input().split()]
dp = {}
res = []
sol = 0

for val in v:
    if val-1 in dp:
        dp[val] = dp[val-1] + 1
    else:
        dp[val] = 1
    if sol < dp[val]:
        sol = dp[val]
        lst = val

for i in range(n-1, -1, -1):
    if v[i] == lst:
        res.append(i)
        lst -= 1
res.reverse()
print(sol)
for i in res:
    print(i+1, end = ' ')

