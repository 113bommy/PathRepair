K = str(input)
S = input()
if len(S)<=K:
    print(S)
else:
    print(S[:K]+'...')