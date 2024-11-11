N = int(input())
C = [int(input()) for _ in range(N)]

MOD = 10 ** 9 + 7
recent = [-1 for _ in range(max(C))]
hist = []

ans = 1
for i in range(N):
    c = C[i] - 1
    if recent[c] >= 0 and recent[c] != i-1:
        ans = (ans + hist[recent[c]]) % MOD
    recent[c] = i
    hist.append(ans)
    
print(ans)