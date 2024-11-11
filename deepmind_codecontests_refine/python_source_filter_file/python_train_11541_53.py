from fractions import gcd

A, B, C = map(int, input().split())

print('YES' if gcd(A, B) % C == 0 else 'NO')