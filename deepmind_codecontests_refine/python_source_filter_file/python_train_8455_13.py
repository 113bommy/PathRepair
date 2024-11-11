R = lambda:map(int,input().split())
 
from collections import defaultdict
t = int(input())
 
 
def solve(a):
    d = defaultdict(int)
    d[a[0]] += 1
    m = 0
    current = 0
    for i in range(1, len(a)):
        if a[i] != a[i-1]:
            d[a[i]] += 1
            current = 0
        else: 
            current+= 1
            m = max(m, current)
    if max(d.values())>1 or m>2: return "YES"
    return "NO"
 
for _ in range(t):
    n = int(input())
    a = list(R())
    print(solve(a))
        