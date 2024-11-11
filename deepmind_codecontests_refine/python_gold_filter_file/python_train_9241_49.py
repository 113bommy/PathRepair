K = int(input())
S = input()
print(S if len(S) <= K else S[0:K:1] + '...')