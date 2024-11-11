from math import fabs as abs
a = int(input())
b = list(map(int,input().split()))
for i in range(a): b[i]=abs(b[i])
print(int(sum(b)))