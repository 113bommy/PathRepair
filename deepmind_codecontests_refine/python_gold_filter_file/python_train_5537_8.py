a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
n = int(input())
max_ = 0
min_ = 0
if k1 <= k2:
    if n <= a1 * k1:
        max_ = n // k1
    else:
        max_ += a1
        if n - a1 * k1 <= a2 * k2:
            max_ += (n - a1 * k1) // k2
        else:
            max_ += a2
else:
    if n <= a2 * k2:
        max_ = n // k2
    else:
        max_ += a2
        if n - a2 * k2 <= a1 * k1:
            max_ += (n - a2 * k2) // k1
        else:
            max_ += a1
if a1 * (k1 - 1) + a2 * (k2 - 1) < n:
    min_ = n - (a1 * (k1 - 1) + a2 * (k2 - 1))
print(min_, max_)