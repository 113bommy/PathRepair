import fractions
A,B = list(map(int,input().split()))
print(A*B//fractions.gcd(A,B))