import sys
import math
from math import *
from collections import Counter,defaultdict


  
def main():
	n  = int(input())
	s = input()
	ans = []
	i = 0
	while(i<n):
		cnt = 0
		while(i<n):
			if s[i] == 'R':
				break
			cnt += 1
			i += 1
		if cnt != 0:
			ans.append(cnt)
		cnt = 0
		while(i<n):
			if s[i] == 'L':
				break
			cnt += 1
			i +=1
		if cnt != 0:
			ans.append(cnt)
	if s[0] == s[-1] and len(ans)>1:
		ans[0] += ans[-1]
		ans.pop()
	elif len(ans) == 1:
		ans[0] += 2
	val = 0
	for i in ans:
		if i>=3:
			val += i//3
	print(val)

for i in range(int(input())):
	main()
