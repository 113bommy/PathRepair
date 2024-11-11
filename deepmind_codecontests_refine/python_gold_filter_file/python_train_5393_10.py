A,B,C,D = map(int, input().split())
from fractions import gcd

cd = C*D//gcd(D,C)
f = lambda x: B//x - ((A-1)//x)
print(B - A + 1 - (f(C) + f(D) - f(cd)))