a = int(input())
for i in range(a):
	b, c, d = [int(i) for i in input().split()]
	if(b==1):
		print(c)
	elif(c*2<=d):
		print(b*c)
	else:
		if(b%2==0):
			print(b*d/2)
		else:
			print((b-1)*d/2+c)