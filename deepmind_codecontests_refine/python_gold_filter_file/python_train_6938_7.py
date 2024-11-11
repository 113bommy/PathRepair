import math

def nextsquare(x):
	y = int(math.sqrt(x))
	return ((y+1)*(y+1))



a = input()
for i in range(int(a)):
	k = int(input())
	j = nextsquare(k)
	answer1 = -1
	answer2 = 0
	while (j <= (4 * k / 3) + 1):
		l = j - k
		if not (l == 0):

			if (int(math.sqrt(l)) * int(math.sqrt(l)) == l):
				n = int(math.sqrt(j))
				m = int(math.sqrt(l))
				r = n % m
				m1 = (n - r)/m
				if r < m1:
					answer1 = n
					answer2 = int(m1)
		j =nextsquare(j)
	if answer1 == -1 :
		print(answer1)
	else:
		print(answer1,answer2)
