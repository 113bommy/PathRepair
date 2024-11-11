# Name : Sachdev Hitesh
# College : GLSICA

t,s,x=map(int,input().split());n=t+s+1
a=((x-t)%s);b=1
if x-n>0:
	b=((x-n)%(s))
if x==t:
	print("YES")
elif x>t:
	if a==0 or b==0:
		print("YES")
	else:
		print("NO")
else:
	print("NO")