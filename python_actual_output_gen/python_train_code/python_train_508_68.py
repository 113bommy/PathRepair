N, X = map(int, input().split())
L = [int(x) for x in range(N)]
print(N + ((X - sum(L))) // min(L))