# your code goes here
from collections import *

t = int(input())

for i in range(t):
	n, k = map(int, input().split())
	L = list(map(int, input().split()))
	L.sort()
	print(sum(L[-1-k:-1]) + L[-1])