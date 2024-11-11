n = (input())

decimal = int(n,2)
count = 0
for i in range(32):
	if(decimal > pow(4,i)):
		count += 1
print(count)