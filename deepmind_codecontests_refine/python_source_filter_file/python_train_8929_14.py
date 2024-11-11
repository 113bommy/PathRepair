import collections
N = int(input())
S = [input() for _ in range(N)]
count = collections.Counter(S)
maxV = max(count.values())
c = [k for k, v in count.items() if v == maxV]
print('\n'.join(c))