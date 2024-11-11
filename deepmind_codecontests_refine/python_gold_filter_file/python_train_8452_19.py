t = int(input())
for i in range(t):
	students, swaps, a, b = map(int, input().split())
	if b > a:
		a, b = b, a
	
	if a + swaps >= students:
		maxa = students
	else:
		maxa = a + swaps

	swaps -= maxa - a

	if b - swaps <= 1:
		minb = 1
	else:
		minb = b - swaps
	print(abs(maxa - minb))