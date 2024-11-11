import re

bw,cl='#Black&White','#Color'

def sclr(v):
	for x in v:
		if re.match(r'[CMY]',x):
			return 1
	return 0

n,m=[int(x) for x in input().split()]

v=[]
for x in range(n):
	v.append(input())

print(cl if sclr(v) else bw)