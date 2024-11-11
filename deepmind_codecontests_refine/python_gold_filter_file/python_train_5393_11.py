A, B, C, D = map(int,input().split())
import fractions
lcm = C*D//fractions.gcd(C,D)
print((B-B//C-B//D+ B//lcm)-((A-1) - (A-1)//C - (A-1)//D + (A-1)//lcm))