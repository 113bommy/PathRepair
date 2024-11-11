from bisect import bisect_left
N = int(input())
A = list(map(int, input().split()))
S1 = [A[0]]*N
S2 = [A[-1]]*N
for i in range(1, N):
    S1[i] = S1[i-1]+A[i]
    S2[i] = S2[i-1]+A[N-i-1]
ans = S1[-1]
for i in range(1, N-2):
    s1 = S1[i]
    b = bisect_left(S1, s1/2)
    if abs(S1[b]-s1/2)>abs(s1/2-S1[b-1]):
        b-=1
    P, Q = S1[b], s1-S1[b]
    s2 = S2[N-i-2]
    c = bisect_left(S2, s2/2)
    if abs(S2[c]-s2/2)>abs(s2/2-S2[c-1]):
        c-=1
    R, S = S2[c], s2-S2[c]
    res = max(P, Q, R, S)-min(P, Q, R, S)
    ans = min(ans, res)
print(ans)