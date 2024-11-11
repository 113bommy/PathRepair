N = int(input())
S = input()
S1 = S[:N]
S2 = S[N::][::-1]
H = dict()
for i in range(2**N):
    t1 = ''.join([s for j, s in enumerate(S2) if 2**j & i])
    t2 = ''.join([s for j, s in enumerate(S2) if not 2**j & i])
    k = H.get((t1, t2), 0)
    H[(t1, t2)] = k+1
ans = 0
for i in range(2**N):
    t1 = ''.join([s for j, s in enumerate(S1) if 2**j & i])
    t2 = ''.join([s for j, s in enumerate(S1) if not 2**j & i])
    ans += H.get((t1, t2), 0)
print(ans)