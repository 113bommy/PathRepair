S = list(input())
N = len(S)
S2 = S[:(N-1)//2+2]
if S == S[::-1] and S2 == S2[::-1]:
    print('Yes')
else:
    print('No')