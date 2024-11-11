


for tt in range(int(input())):
	x = int(input())
	n = 0
	powTwo  = 2
	while x>0:
		sqs = powTwo * (powTwo-1) //2
		x -= sqs
		powTwo *= 2
		if x > 0:
			n+=1

	# print(">>>>>>>>>>>>>>>>>", end="")		
	print(n)

