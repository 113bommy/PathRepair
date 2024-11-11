def greater(nowcandy, x):
	vas = int(0)
	pet = int(0)
	while nowcandy > 0:
		if nowcandy > x:
			nowcandy = nowcandy - x
			vas = vas + x
		else:
			vas = vas + nowcandy
			nowcandy = 0
		pet = pet + int(nowcandy / 10)
		nowcandy = nowcandy - int(nowcandy/10)
	if vas >= pet:
		return True
	else:
		return False

candies = int(input())

lo = int(1)
hi = int(candies)

while lo < hi:
	mid = int((lo + hi) // 2)
	if greater(candies, mid):
		hi = mid
	else:
		lo = mid + 1
print(lo)