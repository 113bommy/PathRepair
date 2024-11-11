N,Q = map(int,input().split())
S = '_'+input()+'_'
td = [input().split() for _ in range(Q)]
R = N+1
L = 0
for i in range(Q-1,-1,-1):
    t,d = td[i]
    if t == S[R-1] and d == 'R':
        R -= 1
    elif t == S[R] and d == 'L':
        R += 1
    elif t == S[L+1] and d == 'L':
        L += 1
    elif t == S[L] and d == 'R':
        L -= 1
print(max(0,R-L-1))