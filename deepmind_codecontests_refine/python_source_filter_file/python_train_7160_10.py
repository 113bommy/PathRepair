S = input()
N = len(S)
if S == S[::-1] and S[0:(N-3)//2] == S[0:(N-3)//2:-1]:
    print ('Yes')
else:
    print ('No')