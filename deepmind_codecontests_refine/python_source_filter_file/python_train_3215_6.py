import copy
try:
	while True:
		A = [[]]
		L = input()
		i = 0
		flag = 0
		for a in L:
			if a != "+" and a != "=":
				A[i].append(a)
			else:
				i = i + 1
				A.append([])
		for a in A:
			if "X" in a and len(a) == 1:
				flag = 1
		for i in range(10):
			B = copy.deepcopy(A)
			for Bi,b in enumerate(B):
				for bi,k in enumerate(b):
					if k == "X":
						B[Bi][bi] = str(i)
				B[Bi] = int("".join(B[Bi]))
			if B[0] + B[1] == B[2]:
				if i == 0 and flag == 1:
					print("NA")
					flag = 2
				else:
					print(i)
					flag = 2
		if flag == 1 or flag == 0:
			print("NA")
except EOFError:
	pass