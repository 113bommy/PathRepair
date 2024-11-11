y = int(input())
for w in range(y + 1 , 10000):
	for x in str(y + 1):
		if str(y + 1).count(x) > 1:
			y = y + 1
		else:
			year = y + 1
print(year)