import sys
import math
from collections import defaultdict
import bisect
def alele(): return list(map(int, sys.stdin.readline().strip().split()))
def ilele(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()
def list2d(a, b, c): return [[c] * b for i in range(a)]
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
def Yes(): print('Yes')
def No(): print('No')
def YES(): print('YES')
def NO(): print('NO')
INF = 10 ** 18
MOD = 1000000000 + 7

def primeFactors(n): 
	A =set()
	while n % 2 == 0: 
		A.add(2) 
		n = n // 2
	for i in range(3,int(math.sqrt(n))+1,2): 
		while n % i== 0: 
			A.add(i) 
			n = n // i 
	if n > 2: 
		A.add(n) 
	return list(A)	
Z = []
for i in range(int(input())):
    a,b = ilele()
    Z.append((a,b))
for i in range(len(Z)):
    a,b = Z[i]
    if i == 0:
        B = list(set(primeFactors(a) + primeFactors(b)))
        #print(B)
    else:
        C = []
        for j in B:
            if a%j == 0 or b%j == 0:
                C.append(j)
        B = C.copy()
    #print(B)
    if len(B) == 0:
        break
if len(B) != 0:
    print(B[0])
else:
    print(-1)
