N,M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

PA = [0, A[0]]
for i in A[1:]:
    PA += [PA[-1] + i]
print(PA)
from bisect import *
for i in B:
    ind = bisect_left(PA, i)
    print(str(ind) + ' ' + str(i - PA[ind - 1]))
    