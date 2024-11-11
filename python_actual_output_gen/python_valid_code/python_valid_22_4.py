
if __name__ == '__main__':

	n = int(input())
	arr = list(map(int,input().rstrip().split()))
	c = 0
	bi = 0
	b = 0
	for i in range(n):
		val = arr[i]
		if i % 3 == 0:
			c = c + val
		elif (i+1) % 3 == 1:
			b = b + val
		else:
			bi = bi + val
	ans = ''
	if c > bi and c > b:
		ans = 'chest'
	if bi > c and bi > b:
		ans = 'biceps'
	if b > bi and b > c:
		ans = 'back'
	print(ans)