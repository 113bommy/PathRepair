from collections import Counter
n = int(input())
S = [str(sorted(input())) for _ in range(N)]

print(sum(map(lambda x: x * (x - 1) // 2, Counter(S).values())))