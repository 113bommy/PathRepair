n = int(input())
s = list(input() for i in range(n))

import collections
A = collections.Counter(S)
 
B = max(A.values())
C = [i for i in A if A[i] == B]
C = sorted(C)
 
for i in C:
    print(i)