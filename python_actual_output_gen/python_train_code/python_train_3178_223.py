S = int(input())
K = input()

if len(S) < K:
    print(S)
else:
    print(S[:K]+'...')