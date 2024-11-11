from collections import Counter

s = Counter(input())
if (s['N'] > 0) == (s['S'] > 0) and (s["W"] > 0) == (s['E'] > 0):
    print("Yes")
else:
    print("No")
