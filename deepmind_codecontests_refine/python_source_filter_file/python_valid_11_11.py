import sys
input=sys.stdin.readline
from collections import Counter as cc
I = lambda : list(map(int,input().split()))

def ans(arr):
	arr.sort(reverse=True, key = lambda x:[x[0] > x[1], x[0],-x[1]])
	x,y = arr[0]
	if x <= y:
		an = 0
		x = y = 0
	else:
		an = 1
	for i in range(1,len(arr)):
		p,q = arr[i]
		if x+p > y+q:
			an+=1
			x+=p
			y+=q
	return an

t,=I()
for _ in range(t):
	n, = I()
	a=[]
	b=[]
	c=[]
	d=[]
	e=[]
	for i in range(n):
		x = input().strip()
		temp = [0]*5
		le = len(x)
		for j in x:
			temp[ord(j) - 97]+=1
		a.append([temp[0],le - temp[0]])
		b.append([temp[1],le - temp[1]])
		c.append([temp[2],le - temp[2]])
		d.append([temp[3],le - temp[3]])
		e.append([temp[4],le - temp[4]])

	print(max(map(ans,[a,b,c,d,e])))