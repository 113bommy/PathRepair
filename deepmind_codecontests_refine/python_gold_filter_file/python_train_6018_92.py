X = input()
MOD = 10**9 + 7
M = 13
S = [0]*M
S[0] = 1
T = [0]*M

def calc(S, T, x):
    for i in range(M):
        T[(i*10 + x) % M] += S[i]
    for i in range(M):
        T[i] %= MOD

zeros = [0]*M
for c in X:
    T[:] = zeros
    if c == "?":
        for x in range(10):
            calc(S, T, x)
    else:
        x = int(c)
        calc(S, T, x)
    S, T = T, S
print(S[5])