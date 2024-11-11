a=int(input())
b=int(input())
from math import *
if a>ceil(log(b,2)):
	print(b)
else:
	print(b%2**a)
