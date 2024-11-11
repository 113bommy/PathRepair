

#start the code from here

t=int(input())
for i in range(t):
	r=int(input())
	if r==3:
		print(7)
		continue
	if r%2==1:
		print(7,end="")
		er="1"
		we=''
		for i in range((r//2)-1):
			we+=er
		print(we)
	else:
		er='1'

		we=''
		for i in range(r//2):
			we+=er
		print(we)