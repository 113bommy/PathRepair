K = int(input())
S = input()
if K > len(S):
    print(S)
else:
    print(S[0:K] + '...')