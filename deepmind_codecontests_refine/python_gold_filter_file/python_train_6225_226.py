from fractions import gcd
A,B=map(int,input().split())
x=(A*B)//(gcd(A,B))

print(x)
