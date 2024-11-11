def max2(x,y):
    return x if x > y else y

N, K = map(int, input().split())
P = list(map(int, input().split()))
C = list(map(int, input().split()))

off = max(C)
m2 = off
for i in range(N):
    tmp = 0
    m1 = off
    l = i
    S = 0
    k = 0
    for j in range(N):
        S += C[l]
        l = P[l] - 1
        if l==i:
            k = j+1
            break
    cnt = K // k - (K % k == 0)
    cnt = max2(0, cnt -2)
    a = K-cnt*k
    l = i
    for j in range(a):
        tmp += C[l]
        m1 = max2(m1, tmp)
        l = P[l] - 1
    if S > 0:
        m1 += cnt*S
    m2 = max2(m1, m2)

print(m2)
"""
2 4
2 1
10 -7
"""
