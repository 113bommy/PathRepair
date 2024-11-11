def ans(a):
	if a == 0:
		return 2
	if a == 1:
		return 6
	if a == 2:
		return 2
	if a == 3:
		return 3
	if a==4:
		return 3
	if a == 5:
		return 4
	if a== 6:
		return 2
	if a== 7:
		return 5
	if a == 8:
		return 1
	if a==9:
		return 2
n = list(map(int,input()))
print(ans(n[0])*ans(n[1]))
