from random import randint
import sys

n, k = [int(w) for w in input().split()]

def there(l, r):
    print(l, r)
    sys.stdout.flush()
    a = input()
    if a == "Bad":
        sys.exit(0)
    else:
        return a == "Yes"

l, r = 1, n

while True:
    if r - l < 57:
        x = randint(l, r)
        if there(x, x):
            sys.exit(0)
    else:
        m = (l+r)//2
        if there(l, m):
            r = m
        else:
            l = m + 1
    l = max(l - k, 1)
    r = min(r + k, n)
