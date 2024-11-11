# import sys
# sys.stdin=open("input.in","r")
# sys.stdout=open("output.out","w")

t,s,x=map(int,input().split())
if(x==t):
	print("YES")
elif(x<t):
	print("NO")	
elif(x<t+s):
	print("NO")	
else:
	x-=t
	if(x%s==0 or (x-1)%s==0):
		print("YES")
	else:
		print("NO")				
		
			

