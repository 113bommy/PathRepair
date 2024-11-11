N = int(input())
Xmi, Xma, Ymi, Yma, DYmi, DYma, UYmi, UYma, RXmi, RXma, LXmi, LXma = [(10**10), -(10**10)] * 6
for _ in range(N):
    x, y, d = input().split()
    x, y = int(x), int(y)
    
    if d == "R":
        RXmi = min(RXmi, x)
        RXma = max(RXma, x)
    elif d == "L":
        LXmi = min(LXmi, x)
        LXma = max(LXma, x)
    else:
        Xmi = min(Xmi, x)
        Xma = max(Xma, x)
        
    if d == "U":
        UYmi = min(UYmi, y)
        UYma = max(UYma, y)
    elif d == "D":
        DYmi = min(DYmi, y)
        DYma = max(DYma, y)
    else:
        Ymi = min(Ymi, y)
        Yma = max(Yma, y)

def calc(t):
    xmi = min(RXmi+t, LXmi-t, Xmi)
    xma = max(RXma+t, LXma-t, Xma)
    ymi = min(UYmi+t, DYmi-t, Ymi)
    yma = max(UYma+t, DYma-t, Yma)
    return max(yma-ymi, 0)*max(xma-xmi, 0)
    
def di(t):
    a = 1
    return calc(t+a) - calc(t-a)
def dii(t):
    a = 0.00000009
    return calc(t+a) - calc(t-a)

l = 0
r = 2*10**9
for _ in range(100):
    m = (l+r)//2
    if di(m) > 0:
        r = m
    else:
        l = m
for _ in range(100):
    m = (l+r)/2
    if dii(m) > 0:
        r = m
    else:
        l = m
print(calc(m))
