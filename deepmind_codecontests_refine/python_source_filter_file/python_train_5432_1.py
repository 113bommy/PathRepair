from sys import stdout

def full(k, get, mass):
	global l
	# print(f"k = {k}")
	if k%2 == 1:
		k = k
	else:
		k = k-1

	if k-4 >= 0:
		for i in range(l)[k-4::-2]:
			answer = ask(get(i), get(i+2))
			if answer:
				mass[i] = mass[i+2]
			else:
				mass[i] = ~mass[i+2]
	# print((k+2))
	# print(2*n-1)			
	if (k+2) < (2*n-1):
		# print("pass here")
		for i in range(l)[k+2::2]:
			# print(f"l = {l}, i = {i}")
			answer = ask(get(i-2), get(i))
			if answer:
				mass[i] = mass[i-2]
			else:
				mass[i] = ~mass[i-2]


def ask(x, y):
	x = [x[1], x[0]]
	y = [y[1], y[0]]
	q = f"? {x[0]+1} {x[1]+1} {y[0]+1} {y[1]+1}"
	print(q)
	stdout.flush()
	answer = bool(int(input()))
	return answer

def get_top(idx):
	if idx>=n:
		i = n-1
		j = idx%n+1
	else:
		i = idx%n
		j = 0
	return i,j

def get_bot(idx):
	if idx>=n:
		j = n-1
		i = idx%n+1
	else:
		j = idx%n
		i = 0
	return i,j

def fun( mass, f):
	l = len(mass)
	get = f
	for i in range(l)[2:l-1:2]:
		answer = ask(get(i-2), get(i))
		# print(f"answer = {answer}")
		if answer:
			mass[i] = mass[i-2]
		else:
			mass[i] = not mass[i-2]
		# print(mass)

	for i in range(l)[4::2]:
		if (mass[i-4] == mass[i-2]) and (mass[i-2] != mass[i]):
			answer = ask(get(i-3), get(i-1))
			if answer:
				answer = ask(get(i-4), get(i-1))
				if answer:
					mass[i-3] = mass[i-4]
					mass[i-1] = mass[i-4]
				else:
					mass[i-3] = not mass[i-4]
					mass[i-1] = not mass[i-4]
				full(i-1, get, mass)
			else:
				answer = ask(get(i-3), get(i))
				if answer:
					mass[i-3] = mass[i]
					mass[i-1] = mass[i-2]
				else:
					mass[i-3] = not mass[i]
					mass[i-1] = not mass[i-2]
				full(i, get, mass)
			break
		elif (mass[i-4] != mass[i-2]) and (mass[i-2] == mass[i]):
			answer = ask(get(i-3), get(i-1))
			if answer:
				answer = ask(get(i-3), get(i))
				if answer:
					mass[i-3] = mass[i]
					mass[i-1] = mass[i]
				else:
					mass[i-3] = not mass[i]
					mass[i-1] = not mass[i]
				full(i, get, mass)
			else:
				answer = ask(get(i-4), get(i-1))
				if answer:
					mass[i-3] = mass[i-2]
					mass[i-1] = mass[i-4]
				else:
					mass[i-3] = not mass[i-2]
					mass[i-1] = not mass[i-4]
				full(i-1, get, mass)
			break

if __name__ == "__main__":
	n = int(input())

	a_top = [None]*(2*n-1)
	a_top[0] = True
	a_top[len(a_top)-1] = False 
	a_bot = a_top.copy()
	
	l = len(a_bot)

	fun(a_top, get_top)
	# print(a_top)
	fun(a_bot, get_bot)
	# print(a_bot)
	
	matrix = []
	for i in range(n):
		matrix.append([None]*n)
	for i in range(len(a_top)):
		idx = get_top(i)[::-1]
		# print("idx_top", idx)
		matrix[idx[0]][idx[1]] = a_top[i]
		idx = get_bot(i)[::-1]
		# print("idx_bot", idx)
		matrix[idx[0]][idx[1]] = a_bot[i]

	for i in range(n)[1:n-1:1]:
		for j in range(n)[1:n-1:1]:
			answer = ask([j-1,i-1], [j,i])
			if answer:
				matrix[i][j] = matrix[i-1][j-1]
			else:
				matrix[i][j] = not matrix[i-1][j-1]
	print("!")
	for i in matrix:
		for j in i:
			print(int(j), end = "")
		print()
	stdout.flush()
