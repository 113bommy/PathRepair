from collections import Counter
N = int(input())
V = list(map(int, input().split()))
a1, a2, *_ = Counter(V[0::2]).most_common() + [(0, 0)]
b1, b2, *_ = Counter(V[1::2]).most_common() + [(0, 0)]
print(N - max(a1[1] + b2[1], a2[1] + b1[1]) if a1[0] == b1[0] else N - a1[1] + b1[1])
