N, L = map(int, input().split())
P = [input() for i in range(L)]
P.sort()
print("".join(P))