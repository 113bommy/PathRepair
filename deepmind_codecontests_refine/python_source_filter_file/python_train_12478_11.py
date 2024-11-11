N = int(input())
S = input()
T = input()

p = 2*N
for i in range(N):
    if S[i:] == T[:N-i] and i < p:
        p = i + N

print(p)
