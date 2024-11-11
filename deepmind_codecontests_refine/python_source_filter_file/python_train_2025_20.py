from sys import stdin
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as df

n=it()
l=mp()

i=0
while i<n-1:
	if l[i]<=l[i+1]:
		i+=1
	else:
		break

a = l[i+1:]+l[:i+1]
l.sort()
print(a)
if l == a:
	print(n-i-1)
else:
	print(-1)
