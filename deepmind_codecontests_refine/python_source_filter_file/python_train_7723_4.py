k = int(input())
for x in range(k):
 
	n = int(input())
	ls = list(map(int, input().split()))
	output = 0
	if n == sum(ls) // n:
		print(n)
		continue
 
	for a in range(1000,2,-1):
		count = 0
		for number in ls:
			if number >= a:
				count+=1
		if count >= a:
			output = a
			break
	print(output)
 
 