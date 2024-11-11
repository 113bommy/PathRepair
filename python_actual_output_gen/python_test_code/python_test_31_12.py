# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")

m,d=map(int,input().split())
if(m==2):
	if(d==1):
		print(5)
	else:
		print(6)
else:
	l=[1,3,5,7,8,10,12]	
	s=[2,4,6,9,11]

	if(m in l):
		if(d==6 or d==7):
			print(6)
		else:
			print(5)

	else:
		if(d==7):
			print(6)
		else:
			print(5)						