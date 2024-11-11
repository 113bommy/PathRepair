from collections import Counter as C
N = int(input())
A = C([min(int(a)//400, 8) for a in input().split()])

a = sum([A[i]>0 for i in range(8)])
print(a, a+A[8])