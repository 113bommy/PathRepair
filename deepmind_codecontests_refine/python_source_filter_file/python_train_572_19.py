import fractions
a, b, c = [int(x) for x in input().split()]

def solve(a, b, c):
    if c % fractions.gcd(a, b) != 0: return False
    if c > a*b: return True
    for i in range(b):
        for j in range(a):
            if a*i + b*j == c:
                return True
    return False

print('Yes' if solve(a,b,c) else 'No')
