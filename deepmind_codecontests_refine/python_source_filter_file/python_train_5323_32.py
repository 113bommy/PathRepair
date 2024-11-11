int_inp   = lambda: int(input()) #integer input
strng     = lambda: input().strip() #string input
strl      = lambda: list(input().strip())#list of strings as input
mul       = lambda: map(int,input().split())#multiple integers as inpnut
mulf      = lambda: map(float,input().split())#multiple floats as ipnut
seq       = lambda: list(map(int,input().split()))#list of integers
import math
from collections import Counter,defaultdict

k = int_inp()
p = math.ceil(k/4)
if k//4 < 2*((4*p)-k):
	print(-1)
else:
	seven =(4*p-k)
	p=p-2*seven
	if p>=7:
		seven = seven + (p//7)*4
		p=p-(p//7)*7
	print(('4'*p)+'7'*seven)
