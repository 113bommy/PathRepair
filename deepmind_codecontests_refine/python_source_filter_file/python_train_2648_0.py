def check(a1,b1,a2,b2):
	if b1 > a2 and a1 > b2:
		return True
	return False
def solve(x):
	if (check(x[0][0],x[1][1],x[2][0],x[3][1]) and check(x[0][0],x[1][1],x[3][0],x[2][1])) or \
	   (check(x[1][0],x[0][1],x[2][0],x[3][1]) and check(x[1][0],x[0][1],x[3][0],x[2][1])):
		return 1
	if (check(x[2][0],x[3][1],x[0][0],x[1][1]) or check(x[2][0],x[3][1],x[0][0],x[1][1])) and \
	   (check(x[3][0],x[2][1],x[1][0],x[0][1]) or check(x[3][0],x[2][1],x[1][0],x[0][1])):
		return 2
	return 0
def main():
	x = []
	for i in range(4):
		tmp = list(map(int,input().split()))
		x.append(tmp)
	w = solve(x)
	if w == 0:
		print('Draw')
	else:
		print('Team {}'.format(w))
main()