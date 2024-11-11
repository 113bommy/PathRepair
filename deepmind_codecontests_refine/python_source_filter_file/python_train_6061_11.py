query=int(input())

for _ in range(query):
	n=int(input())
	#Because all numbers can be divided into 2s and 3s except 1, 3 lights make highest of '7' and 2 lights make '1'. If 6 lights on, rather than having '9', we can print'77'
	if n%2==0:
		#For n==6,'111'>'77'
		print((n//2)*'1')
	else:
		#For n==9, '7111111'>'777'
		#Segment is decreased by 2 for each '1'
		print('7'+((n//2)-3)*'1')