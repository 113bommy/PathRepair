from math import *
import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

n = mint()
s = list(minp())
#a = [[0]*256 for i in range(3)]
a = [0]*256
i = 0
l = len(s)
while i < l:
	j = i + 1
	while j < l and s[j] == s[i]:
		j += 1
	#a[(i==0)+(j==l)][ord(s[i])] = max(a[(i==0)+(j==l)][ord(s[i])], j-i)
	a[ord(s[i])] = max(a[ord(s[i])], j-i)
	i = j
#b = [[0]*256 for i in range(3)]
b = [0]*256
for k in range(1,n):
	#print(a[ord('a'):ord('z')+1])
	for i in range(ord('a'),ord('z')+1):
		b[i] = min(a[i],1)
	i = 0
	s = minp()
	l = len(s)
	q = 0
	while i < l:
		j = i + 1
		while j < l and s[j] == s[i]:
			j += 1
		z = ord(s[i])
		w = j-i
		if i == 0:
			q = w
			if j == l:
				w += (w+1)*a[z]
			elif a[z] != 0:
				w += 1
		elif j == l:
			w += 1
			if s[i] == s[-1]:
				w += q
		b[z] = max(b[z], w)
		i = j
	a,b = b,a
print(max(a))
