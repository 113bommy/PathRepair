# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")

l=list(map(int,input().split()))
n=l[0]
m=l[1]
count=0
for i in range(n):
	if(i%2==0):
		for j in range(m-1):
			print("#",end=" ")
		print("#")	
	else:
		count+=1
		if(count%2!=0):
			for k in range(m-1):
				print(".",end=" ")
			print("#")
		else:
			print("#",end=" ")
			for p in range(m-2):
				print(".",end=" ")
			print(".")




				

