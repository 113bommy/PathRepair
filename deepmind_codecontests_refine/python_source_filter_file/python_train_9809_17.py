import sys
from collections import Counter

# inf = open('input.txt', 'r')
# reader = (line.rstrip() for line in inf)
reader = (line.rstrip() for line in sys.stdin)
input = reader.__next__

def countPrefix(s, x):
    if x < 0:
        s = s.replace('0', '#').replace('1', '0').replace('#', '1')
        x = -x
    
    bal = 0
    ctr = Counter()
    maxBal = minBal = 0
    for c in s:
        if c == '0':
            bal += 1
        else:
            bal -= 1
        ctr[bal] += 1
        maxBal = max(maxBal, bal)
        minBal = min(minBal, bal)
        
#     print(s, bal)
#     print(x, maxBal)
    if bal == 0:
        if x <= maxBal:
            return -1
        else:
            return 0
    elif bal < 0:
        ans = 0
        if maxBal >= x:
            k = 0
            while maxBal + k * bal >= x:
                ans += ctr[x + k * bal]
                k += 1
    else:
        if maxBal >= x:
            k = 0
        else:
            k = (x - maxBal) // bal
        ans = 0
        while minBal + k * bal <= x:
            ans += ctr[x - k * bal]
            k += 1
    
    if x == 0:
        ans += 1
    return ans

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    s = input()
    print(countPrefix(s, x))

# inf.close()
