import sys
from collections import Counter
Q = int(input())
def check(a, b):
    a = a[::-1]
    b = b[::-1]
    for i in b[::-1]:
        if a and i == a[-1]:
            a.pop()
    if a:
        return False
    else:
        return True
for _ in range(Q):
    s = [ord(s) for s in sys.stdin.readline().strip()]
    t = [ord(s) for s in sys.stdin.readline().strip()]
    p = [ord(s) for s in sys.stdin.readline().strip()]
    if not check(s, t):
        sys.stdout.write('NO\n')
    else:
        Cs = Counter(s)
        Ct = Counter(t)
        Cp = Counter(p)
        if all(Ct[k] - Cs[k] <= Cp[k] for k in Ct.keys()):
            sys.stdout.write('YES\n')
        else:
            sys.stdout.write('NO\n')