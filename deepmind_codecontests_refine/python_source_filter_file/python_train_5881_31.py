

noOfWheels = int(input())


count = 0
initial = int(input())
final = int(input())

currvalue = 0

for i in range(noOfWheels):

	diff = initial%10 - final%10
	if diff<0:
		diff = (-1)*diff
	
	if diff>5:
		diff = 10 - diff
	

	initial = initial/10
	final = final/10

	count += diff


print(count)