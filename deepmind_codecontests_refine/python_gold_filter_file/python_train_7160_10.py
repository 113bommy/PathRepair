S = input()
N = len(S)
if S == S[::-1] and S[:(N-1)//2] == S[:(N-1)//2][::-1]:
    print('Yes')
else:
    print('No')