S = input()
K = float('inf')
for i in range(1, len(S)):
    if S[i-1] != S[i]:
        K = min(K, max(i, len(S)-i))

print(K)
