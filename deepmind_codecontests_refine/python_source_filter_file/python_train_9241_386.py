K = int(input())
S = input()

if len(S) <= K:
    print(K)
else:
    print(S[0:K]+'...')
