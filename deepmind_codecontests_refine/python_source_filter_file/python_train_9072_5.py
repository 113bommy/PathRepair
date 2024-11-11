n = int(input()) #https://codeforces.com/problemset/problem/1173/B
import math

m=math.ceil((n+1)/2)
print(m)
for i in range(n):
    if i<m:
        print(1,i+1)
    elif i>=m:
        print(i-m+1,m)