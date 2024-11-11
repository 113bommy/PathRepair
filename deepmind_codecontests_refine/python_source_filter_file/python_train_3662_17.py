import sys
input = sys.stdin.readline

n,I = map(int,input().split())
A = list(map(int,input().split()))

import math


# I = 1 6*log_2_K <= 8 K = 2
# I = 2 6*log_2_K <= 16 K = 2

K = int(2**(I*8/n))

from collections import Counter
C = Counter(A)

KEY = sorted(C.keys())
LIST = []

for k in KEY:
    LIST.append(C[k])

S=[0]
for l in LIST:
    S.append(l+S[-1])

if K>=len(KEY):
    print(0)
    sys.exit()

ANS=S[-1]
SUM=S[-1]

for i in range(K,len(S)):
    ANS=min(ANS,SUM-(S[i]-S[i-K]))
    #print(ANS)

print(ANS)

