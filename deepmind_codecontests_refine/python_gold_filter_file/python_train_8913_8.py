n=int(input())
l=list(map(int,input().split()))
t=l.count(2)
o=l.count(1)
count=0
if t==0:
	print(o//3)
elif o==0:
	print(0)
else:
	if t>=o:
		print(o)
	else:
		count+=t
		count+=(o-t)//3
		print(count)
