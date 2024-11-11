N = int(input())
P = [int(input()) for i in range(N)]
Q = [0]*N
for i in range(N):
    Q[P[i]-1] = i

cur = 1; ans = 0
for i in range(N-1):
    if Q[i] < Q[i+1]:
        cur += 1
    else:
        cur = 1
    ans = max(cur, ans)
print(N - ans)
