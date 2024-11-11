#!/usr/bin/python
import math 
N = int(input())
l = [-1 for x in range(0,100000+4)]
st = input().split()
ans = 2
ind = -1
for i in range(N):
	a = int(st[i])
	if(l[a-2] != -1 or l[a+2] != -1):
		if(l[a-2] !=-1 and l[a+2] ==-1 ):
			if(-ind + i > ans):
				ans = i - ind -1
			ind = l[a-2]
			l[a-2] = -1
 
		elif(l[a+2] != -1 and l[a-2] == -1):
			if(-ind + i >ans):
				ans = i - ind -1
			ind = l[a+2] 
			l[a+2] = -1
		else:
			if(i - ind > ans) :
				ans = i - ind -1
			l[a-2] = -1
			l[a+2] = -1
			ind = max(l[a-2],l[a+2])
	#print(ind,ans)
	l[a] = i
if(N-1-ind > ans):
	ans = N-1-ind
print(ans)

