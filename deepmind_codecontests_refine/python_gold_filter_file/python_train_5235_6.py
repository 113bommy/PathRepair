import sys 
lines = sys.stdin.readlines()

#choose largest barrel, to pour into second largest barrel first, and then second largest to largest

def barrels(barr, c):
	count = 0
	diffVal = 0
	barr = sorted(barr)
	while (count < c):
		if count == 0: # put largest value into second largest value
			diffVal = barr[-(count+1)] + barr[-(count+2)] #find next largest and add
		else:
			diffVal += barr[-(count+2)]
		count += 1
	print(diffVal)

count = 0
c= 0
for line in lines[1:]:
	if count % 2 == 0:
		c = line.split()
		c= int(c[1])
	else:
		barrel = line.split()
		barrel = list(map(int, barrel))
		barrels(barrel, c)
	count += 1