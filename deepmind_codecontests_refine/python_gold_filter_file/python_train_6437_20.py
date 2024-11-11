S = input()
T = len(S)
for i in range(len(S)-1):
    if S[i] != S[i+1]:
        K = max(i+1, len(S)-i-1)
        T = min(T, K)

print(T)