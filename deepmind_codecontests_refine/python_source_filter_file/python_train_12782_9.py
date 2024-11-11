import collections
N = int(input())
A = list(map(int,input().split()))
CA = collections.Counter(A)
S = 0
for i in CA.values():
    S += i*(i-1)//2
for x in A:
    print(S - count[x] + 1)