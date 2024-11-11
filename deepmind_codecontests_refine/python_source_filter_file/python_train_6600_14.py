from fractions import Fraction
a, b, c, d = map(int, input().split())
h = (a * d)/c
v = (b * c) / d
# print(h, v)
if v > a:
    v = 0
if h > b:
    h = 0
if h != 0:
    ans = str(Fraction((b - h)/b).limit_denominator())
else:
    ans = str(Fraction((a - v) / a).limit_denominator())
if ans == 0:
    print('0/1')
else:
    print(ans)
# a c ad/c
# b d  bc/d
