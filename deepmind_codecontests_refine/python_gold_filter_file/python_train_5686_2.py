
n=int(input())
l=[]
for i in range(n):
	x,y=map(int,input().split())
	l.append((x,y))
l.sort()
tv1=[-1]
tv2=[-1]
f=0
for i in range(n):
	if tv1[-1]<l[i][0]:
		tv1.append(l[i][1])
	elif tv2[-1]<l[i][0]:
		tv2.append(l[i][1])
	else:
		f=1
		break
if f:
	print("NO")
else:
	print("YES")
