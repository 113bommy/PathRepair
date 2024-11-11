N, L = map(int, input().split())
S = [input() for i in range(L)]
print(*(sorted(S)), sep='')
