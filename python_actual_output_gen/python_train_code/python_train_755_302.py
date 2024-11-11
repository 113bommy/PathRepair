N, L = map(int, input().split())
S = [input() for i in range(L)]
S.sort()
print("".join(S))