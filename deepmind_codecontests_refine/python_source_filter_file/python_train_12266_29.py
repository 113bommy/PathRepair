import fractions

N, X = map(int, input.split())
x = list(map(int,input.split()))
D = abs(x[0]-X)
for i in x:
    D = fractions.gcd(D,abs(i-X))
print(D)