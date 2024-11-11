from collections import Counter
N = int(input())
c = Counter(''.join(sorted(input())) for _ in range(N))
sum_ = lambda n: int(n*(n-1)/2)
print(sum(map(sum_,c.values())))