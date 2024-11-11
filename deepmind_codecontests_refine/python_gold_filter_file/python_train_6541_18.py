N, C = map(int, input().split())
cusum = [[0 for j in range(10**5+1)] for i in range(C+1)]
for i in range(N):
    s, t, c = map(int, input().split())
    cusum[c][s] += 1
    cusum[c][t] += -1
ans = 0
s = 0
for j in range(10**5+1):
    cp = 0
    cm = 0
    for i in range(C+1):
        if cusum[i][j] == 1:
            cp += 1
        elif cusum[i][j] == -1:
            cm += 1
    s += cp
    ans = max(s, ans)
    s -= cm

print(ans)
