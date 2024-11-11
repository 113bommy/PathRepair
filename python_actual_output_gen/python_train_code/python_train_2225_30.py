S = input()
N = len(S)
ans = 10 ** 6
for k in range(N - 1):
    if S[k] != S[k + 1]:
        ans = min(ans, max(k + 1, N - k - 1))
        
if ans != 0:
    print(ans)
else:
    print(N)