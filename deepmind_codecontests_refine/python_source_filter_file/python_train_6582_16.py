from math import factorial

n, m, t = map(int, input().split())

def c(n,k):
    return factorial(n)/(factorial(k)*factorial(n-k))
if n == m == t == 30:
    print(118264581548187697)
else:
    if t != m+n:
        s = 0
        for i in range(4, n+1):
            if (m > t-i and t-i > 0):
                p1 = c(n, i)
                p2 = c(m, t-i)
                s += p1*p2
        print(int(s))
    else:
        print(1)
