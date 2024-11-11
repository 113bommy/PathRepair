from fractions import gcd
def func(n):
    return n - (n//C + n//D - n//(C*D//gcd(C, D)))
A, B, C, D = map(int, input().split())
print(func(B) - func(A-1))