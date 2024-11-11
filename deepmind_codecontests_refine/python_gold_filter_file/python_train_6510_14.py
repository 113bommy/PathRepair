# from debug import debug
import sys

n = int(input())
s = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))
c = list(map(int, input().split()))

vp = [0]*m
p = [0]*m

d = dict()
for i in s:
	if i in d:
		d[i] += 1
	else:
		d[i] = 1

for i in range(m):
	if b[i] in d:
		vp[i] += d[b[i]]
	if c[i] in d:
		p[i] += d[c[i]]

m1 = 0
m2 = 0
ind = 0
for i in range(m):
	if vp[i] > m1:
		m1 = vp[i]
		m2 = p[i]
		ind = i

	elif vp[i] == m1 and p[i] > m2:
		m1 = vp[i]
		m2 = p[i]
		ind = i
print(ind+1)


