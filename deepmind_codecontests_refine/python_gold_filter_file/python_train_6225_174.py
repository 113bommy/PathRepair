A, B = map(int, input().split())
import fractions

print(int(A*B/fractions.gcd(A,B)))
