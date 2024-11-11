from collections import Counter

n = int(input())
a = [input() for x in range(n)]
b = Counter(a)
c = max(b.values())
s = [s for s, g in b.items() if g == c]
s.sort()
print('\n'.join(s))