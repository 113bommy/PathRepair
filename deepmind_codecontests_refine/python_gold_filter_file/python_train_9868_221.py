N, R = map(int, input().split())
print(R if N > 9 else R + 100*(10 - N))
