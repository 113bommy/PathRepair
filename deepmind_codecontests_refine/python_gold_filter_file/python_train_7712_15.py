n = int(input())
a = [int(x) for x in input().split()]

low = 0 
high = len(a)-1
curr_max = 0 
lsum, rsum = a[low], a[high]
if lsum == rsum:
	curr_max = lsum
while high - low > 1:
	if lsum < rsum:
		low += 1
		lsum += a[low]
	else:
		high -= 1
		rsum += a[high]
	if lsum == rsum:
		curr_max = lsum
if len(a) <= 1:
	print(0)
else:
	print(curr_max)