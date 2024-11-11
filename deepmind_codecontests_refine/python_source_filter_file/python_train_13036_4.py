# import sys
# sys.stdin=open("input.in","r")
for i in range(int(input())):
	a,b,c=sorted(map(int,input().split()))
	if c==0:
		print(0)
	if a==0:
		print(min(b+1,3))
	elif a==1:
		print(min(b+2,4))
	elif a==2:
		if c==2:
			print(4)
		else:
			print(5)
	elif a==3:
		print(6) 
	else:
		print(7)
