import math as m
A, B, H, M = list(map(int, input().split()))
print(m.sqrt(A**2+B**2-2*A*B*m.cos(3.1415926/180*(30*H-11*M/2))))
