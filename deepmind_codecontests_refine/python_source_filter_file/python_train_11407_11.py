a, b = map(int, input().split())
s = list(map(int, input().split()))
from collections import Counter
s = Counter(s)
res = 0
for i in s:
    x = b^i
    if x == x^i: res += s.get(x)*(s.get(x)+1)
    else: res += s.get(x, 0)*s.get(i)
print(res//2)
    