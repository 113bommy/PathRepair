from collections import defaultdict as dd,deque as dq
from math import factorial
p = int(input())
a1,*a = list(map(int,input().split()))
b1,*b = list(map(int,input().split()))
t = factorial(11)
m = dq(a)
n = dq(b)
d ={}
fights =0
while m and n:
	if fights >t:
		fights=-1
		break
	k = m.popleft()
	l = n.popleft()
	if k>l:
		m.append(l)
		m.append(k)
	else:
		n.append(k)
		n.append(l)
	fights+=1
if fights ==-1:
	print(fights)
else:
	if m==[]:
		print(fights,2)
	else:
		print(fights,1)