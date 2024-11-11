import math

A,B=map(int,input().split())

n=int(A*B/math.gcd(A,B))

print(n)
