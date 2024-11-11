import math

for t in range(int(input())):
    m,d,w = map(int, input().split())
    diffw = w // math.gcd(d-1, w)
    totp = min(m, d)
    print(totp // diffw * diffw *(totp // diffw - 1)//2 + (totp % diffw)*(totp // diffw))
