n = int(input())
if n == 1 or n== 2:
	print (1)
	print (1)
elif n == 3:
	print (2)
	print (1,3)
elif n == 4:
	print (3)
	print (1,4,2)
else:
	print (n)
	odd = [i+1 for i in range(n) if (i+1)%2 == 1]
	even = [i+1 for i in range(n) if (i+1)%2 == 0]
	odd.extend(even)
	print (*odd)