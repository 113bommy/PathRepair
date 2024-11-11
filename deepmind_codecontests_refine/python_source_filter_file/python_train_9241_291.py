K = int(input())
S = input()

print(S[:len(S)-K]+'...' if len(S)>int(K) else S)