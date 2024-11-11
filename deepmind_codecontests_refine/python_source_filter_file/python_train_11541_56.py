import fractions

A,B,C = map(int, input().split())

ret = C % fractions.gcd(A,B) == 0
print('Yes' if ret else 'No')