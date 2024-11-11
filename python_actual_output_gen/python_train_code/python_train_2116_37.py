N, M = map(int, input().split())
numSccPair = N + (M - 2 * N) // 4 if M >= 4 else M // 2
print(numSccPair)