import collections

N, K = map(int, input().split())
R, S, P = map(int, input().split())
T = list(input())

for i in range(N-K):
    if T[i] == T[i+K]:
        T[i+K] = "a"

c = colelctions.Counter(T)

print(c["r"]*P + c["s"]*R + c["p"]*S)