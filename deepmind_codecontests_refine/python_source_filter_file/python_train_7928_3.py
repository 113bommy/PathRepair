N = int(input())
S = input()

X = [[-1] for _ in range(26)]
for i in range(N):
    X[ord(S[i])-97].append(i)
print(X)

M = int(input())
for _ in range(M):
    T = input()
    Y = [0] * 26
    for t in T:
        Y[ord(t)-97] += 1
    ma = -1
    for i in range(26):
        ma = max(ma, X[i][Y[i]])
    print(ma + 1)