L, N = map(int, input().split())
S = [input() for _ in range(N)]
S.sort()
print("".join(S))
