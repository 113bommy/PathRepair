import sys
input = lambda: sys.stdin.readline().rstrip()
D = {"AB": 2, "AC": 1, "BC": 0}
N, a, b, c = map(int, input().split())
X = [a, b, c]
S = [D[input()] for _ in range(N)]
ANS = []
if max(X) == 0:
    print("No")
    exit()

if sum(X) == 1:
    t = 0 if a else 1 if b else 2
    for s in S:
        if X[s]:
            print("No")
            exit()
        t ^= s ^ 3
        ANS.append(t)
        X[s-1] ^= 1
        X[s-2] ^= 1
    print("Yes")
    print("\n".join([chr(t+65) for t in ANS]))
    exit()

s = S[0]
if X[s-1] + X[s-2] == 0:
    print("No")
    exit()

for i, s in enumerate(S):
    if X[s-1] > X[s-2]:
        ANS.append((s-2) % 3)
        X[s-1] -= 1
        X[s-2] += 1
    elif X[s-1] < X[s-2]:
        ANS.append((s-1) % 3)
        X[s-1] += 1
        X[s-2] -= 1
    elif i == N - 1 or S[i+1] == (s-1) % 3:
        ANS.append((s-2) % 3)
        X[s-1] -= 1
        X[s-2] += 1
    else:
        ANS.append((s-1) % 3)
        X[s-1] += 1
        X[s-2] -= 1

print("Yes")
print("\n".join([chr(t+65) for t in ANS]))