from collections import Counter
 
N = int(input())
S = [input() for x in range(N)]
E = Counter(S)
c = max(E.values())
s = [s for s, g in b.items() if g == c]
s.sort()
print('\n'.join(s))