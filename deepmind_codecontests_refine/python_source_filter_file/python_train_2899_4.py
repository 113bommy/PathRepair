# _*_ coding:utf-8 _*_

import sys

input = sys.stdin.readline().replace('\n','')
ans  = 1000

for c in input:
	s = input.split(f'{c}')
	ma = 0
	for i in range(len(s)):
		if ma < len(s[i]):
			ma = len(s[i])
	
	if ans > ma:
		ans = ma
		
print(ans,end='') 