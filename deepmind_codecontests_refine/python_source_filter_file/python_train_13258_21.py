
s,n=map(int,input().split())
l=[]
for i in range(n):
	x,y=map(int,input().split())
	l.append((x,y))
l.sort()
de=0
for i in range(n):
	if l[i][0]<s:
		s=s+l[i][1]
	else:
		de+=1
		break
if de==0:
	print("Yes")
else:
	print("No")
