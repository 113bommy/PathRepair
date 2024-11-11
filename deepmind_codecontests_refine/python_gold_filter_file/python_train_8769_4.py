#: Author - Soumya Saurav

from collections import defaultdict
from collections import OrderedDict
from collections import deque
from itertools import combinations
from itertools import permutations
from itertools import accumulate
import bisect
import math
import heapq
import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n , x = map(int , input().split())
arr = list(map(int , input().split()))
arr = arr+arr
#print(arr)
def summa(n):
	return (n+1)*n//2

ptr1 = 0
ptr2 = -1
days = 0
hugs = 0
ans = 0
while ptr2 < 2*n-1:
	ptr2+=1
	#print(ptr2)
	days += arr[ptr2]
	hugs += summa(arr[ptr2])
	while(days > x):
		if days - arr[ptr1] < x:
			break
		days -= arr[ptr1]
		hugs -= summa(arr[ptr1])
		ptr1+=1
	diff = max(days - x, 0)
	ans = max(ans, hugs - summa(diff))
print(ans)
		


