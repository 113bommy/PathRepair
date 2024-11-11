import fractions as fr
A,B=map(int,input().split())
print(A*B//fr.gcd(A,B))