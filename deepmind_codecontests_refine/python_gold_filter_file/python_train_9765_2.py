from collections import Counter

N = int(input())
S = ["".join(sorted(input())) for _ in range(N)]
c = Counter(S)
print(sum([k*(k-1)//2 for k in c.values()]))