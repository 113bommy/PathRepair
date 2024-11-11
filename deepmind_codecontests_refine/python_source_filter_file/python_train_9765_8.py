import collections
N = int(input())
s = ["".join(sorted(input())) for _ in range(N)]
print(A)
B = collections.Counter(s)
print(sum(i*(i-1)//2 for i in B.values()))