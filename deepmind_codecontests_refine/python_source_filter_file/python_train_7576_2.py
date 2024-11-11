import fractions

N = int(input())
A = list(map(int, input().split()))

a = A[0]
for i in range(1, N):
    g = a * A[i] // fractions.gcd(a, A[i])
    a = g
    
b = 0
for i in range(N):
    b = b + g // A[i]

c = b % (1000000007)
print(c)