import sys

n=int(input())
l=[]
for x in range(n):
	l.append(str(input()))
	if x>0:
		if not(l[x-1][-1] == l[x][0]) or (l[:x] in l):
			print("No")
			sys.exit()
print("Yes")
