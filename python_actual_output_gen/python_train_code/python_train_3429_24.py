# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
t,s,x=map(int,input().split())
if x==t:
	print("YES")
else:
	x-=t
	if x>s:
		if x%s==0 or (x-1)%s==0:
			print("YES")
		else:
			print("NO")
	else:
		print("NO")