from math import factorial as f
n = int(input())
# print((f(n)/ (f( max( n//2, 1))* f(max(n//2, 1)))))
print(int((f(n)/ (f( max( n//2, 1))* f(max(n//2, 1))))*  f(max(n// 2-1, 1)) * f(max(n// 2-1, 1)) *(1/2)))