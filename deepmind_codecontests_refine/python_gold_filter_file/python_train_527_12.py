n , k = map(int,input().split())
dicts = {chr(i+96):i for i in range(1,27)}
S = sorted(list(dicts[i] for i in input()))
ans = 0
ansC = k
prev = -2
flag= 0
for i in range(n):
    if S[i] > prev + 1 and k > 0:
        ans += S[i]
        prev = S[i]
        k -= 1
        flag += 1
if flag == ansC:
    print(ans)
else:
    print(-1)
    