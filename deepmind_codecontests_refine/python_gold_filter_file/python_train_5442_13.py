t = int(input())
for _ in range(t):
	n = int(input())
	digit = input()
	raze = list()
	breach = list()
	if n==1:
		if int(digit)%2==0:
			print(2)
		else:
			print(1)
		continue
	
	for i in range(n):
		if (i+1)%2==0:
			breach.append(int(digit[i]))
		else:
			raze.append(int(digit[i]))
	evenCount = 0
	oddCount = 0
	for i in raze:
		if i%2==1:
			oddCount+=1
	for i in breach:
		if i%2==0:
			evenCount+=1
	if n%2==1:
		if oddCount>0:
			print(1)
		else:
			print(2)

	else:
		if evenCount>0:
			print(2)
		else:
			print(1)