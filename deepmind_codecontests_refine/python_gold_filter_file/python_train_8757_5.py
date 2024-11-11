# import math
# import sys
n = int(input().strip())
a = [int(x) for x in input().strip().split(" ")]
mod = 998244353
d = {}
# c = {}
f = [0]*(n+2)
t = [1]*n
t[0]=0
for i in range(n):
	if a[i] in d:
		f[d[a[i]][-1]+1]+=1
		f[i+1]-=1
		d[a[i]].append(i)
	else:
		d[a[i]]=[i]
s=0
for i in range(n):
	s+=f[i]
	if s>0:
		t[i]=0
print(pow(2,sum(t),mod))