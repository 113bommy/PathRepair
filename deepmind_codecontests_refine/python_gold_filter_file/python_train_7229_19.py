a,b=map(int,input().split())
i=0
while(a>0 and b>0):
	i+=1
	a,b=a-1,b-1
if(i%2==0):
	print("Malvika")
else:
    print("Akshat")	