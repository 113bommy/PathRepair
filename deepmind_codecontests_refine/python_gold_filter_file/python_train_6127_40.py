N, M = map(int, input().split())
numSccPair = N + (M - 2 * N) // 4 if M >= 2 * N else M // 2
print(numSccPair)