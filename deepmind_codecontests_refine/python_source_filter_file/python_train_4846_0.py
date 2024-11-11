
import sys
input=sys.stdin.readline
import math
n, k = map(int, input().split())
a = 1;
ar = list(map(int, input().split()))
for c in ar:
    a *=  math.gcd(k,c)//math.gcd(a,c) 
    print(a,c)
if a==k:
	print("Yes")
else:
	print("No")
