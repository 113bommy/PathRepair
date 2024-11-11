import math
n = int(input())
a = int(input())
b = int(input())
c = int(input())
if a < (b - c) or b > n:
    print(math.floor(n / a))
else:
    if n - math.floor((n - b) // (b - c)) * (b - c) >= b:
        count = (math.floor((n - b) // (b - c)) + 1)
        r = n - count * (b - c)
        count += math.floor(r // a)
        print(count) if count > 0 else print(math.floor(n / a))
    else:
        print(math.floor((n - b) // (b - c)))
