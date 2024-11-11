N = int(input())
from collections import Counter
Sc = Counter([input() for _ in range(N)])
max_count = max(Sc.values())
ans = sorted([k for k, v in Sc.items() if v == max_count])
print(*ans, sep="\n")