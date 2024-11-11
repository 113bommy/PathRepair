import fractions
a,b,c,d = map(int,input().split())
def ans(b):
    return b-b//c - b//d + (b//(c*d//fractions.gcd(c,d)))
print(ans(b)-ans(a))