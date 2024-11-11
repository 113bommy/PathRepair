def score(a,b):
	#inner, outer
	if a == 1:
		if b == 2:
			return 3
		else:
			return 4
	elif a == 2:
		if b == 1:
			return 3
		else:
			return "infinite"
	else:
		if b == 1:
			return 4
		else:
			return "infinite"

def result(s):
	if type(s) == int:
		print("Finite")
		print(s)

	else:
		print("Infinite")

	quit()

n = int(input())

figures = list(map(int, input().split()))

sc = 0

if len(figures) == 2:
	result(score(figures[0], figures[1]))

for i in range (len(figures[:-1])):
	k = score(figures[i+1], figures[i])
	#print(figures[i+1], figures[i])
	#print(k)

	if k == "infinite":
		result(k)

	else:
		sc+=k

for h in range(len(figures[:-2])):
	if figures[h] == 3 and figures[h+1] == 1 and figures[h+2] == 2:
		sc-=1

	if figures[h] == 2 and figures[h+1] == 1 and figures[h+2] == 2:
		sc-=2
result(sc)

