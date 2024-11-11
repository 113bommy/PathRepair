S = input()
N = len(S)
K = (N-3)//2
if S == S[::-1] and S[0:K] == S[0:K:-1]:
    print ('Yes')
else:
    print ('No')