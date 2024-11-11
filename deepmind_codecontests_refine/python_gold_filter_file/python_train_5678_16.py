zero = int(input())
five=0
while zero>0:
	five+=5
	rem = five
	count=0
	while rem%5==0:
		count+=1	
		rem/=5
		
	zero-=count
if zero<0:	
	print(0)
else:
	print(5)
	print(five,five+1,five+2,five+3,five+4)