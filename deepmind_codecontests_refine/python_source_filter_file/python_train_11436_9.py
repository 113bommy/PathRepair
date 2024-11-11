from itertools import accumulate
N = int(input())
S = input()
SS = [1 if S[i]=='(' else -1 for i in range(N)]
SSS = list(accumulate(SS))
m = max(0,-min(SSS))
M = max(SSS)
print('('*m+S+')'*(M+m))
