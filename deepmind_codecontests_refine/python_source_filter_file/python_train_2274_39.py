from fractions import gcd
from functools import reduce
N,K,*A=map(int,open(0).read().split())
print("IM"*(((K-A[0])%reduce(gcd,A)>0)&((min(A)>K)|(K>max(A))))+"POSSIBLE")