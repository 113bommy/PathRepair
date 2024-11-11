K = int(input())
S = input()
if len(str(S)) < K:
    print(S)
else:
    print(S[:K]+'...')