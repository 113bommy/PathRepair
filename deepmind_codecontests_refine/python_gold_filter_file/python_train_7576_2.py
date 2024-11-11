import fractions

N = int(input())
A = list(map(int, input().split()))

a = 1
for i in range(N):
    g = a * A[i] // fractions.gcd(a, A[i])
    a = g
    
b = 0
for i in range(N):
    b = b + g // A[i]

c = b % (1000000007)
print(c)