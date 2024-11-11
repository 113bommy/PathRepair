from math import *

n = int(input())
a = list(map(int,input().split()))
summa = sum(a)
print(max(max(a),((2*summa)+n-1)//n))