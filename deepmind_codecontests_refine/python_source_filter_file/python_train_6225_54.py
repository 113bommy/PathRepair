import math as mt 
A,B=map(int,input().split())
print(int(A*B/mt.gcd(A,B)))