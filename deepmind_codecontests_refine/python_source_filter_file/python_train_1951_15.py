yoar=list(map(int,input().split()))
x=yoar[0]
y=yoar[1]
if x==y:
	print("=")
elif x==1 :
	print("<")
elif y==1:
	print(">")
elif x==2 and y!=1:
	if (y>=5):
		print("<")
	elif y==4:
		print("=")
	else:
		print(">")	
			
elif y==2 and x!=1:
	if (x>=5):
		print(">")		
	elif x==4:
		print("=")	
	else:
		print("<")	
else:
	if (x<y):
		print(">")	
	else:
		print("<")	