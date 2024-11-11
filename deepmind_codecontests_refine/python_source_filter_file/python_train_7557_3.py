A = set(input())
B2 = input()
N = int(input())
for i in range(N):
	B = B2
	S = input()
	if len(B) > len(S) - 1:
		print("NO")
		continue
	flag = True
	try:
		if '*' in B:
			for n in range(2):
				for j in range(len(B)):
					if B[j] == '*':
						B = B[j:]
						S = S[j:]
						break
					elif B[j] == '?':
						if S[j] not in A:
							flag = False
							break
					elif B[j] != S[j]:
						flag = False
						break
				if flag == False:
					break
				S = S[::-1]
				B = B[::-1]
			for s in S:
				if s in A:
					flag = False
					break
		elif len(B) != len(B):
			flag = False
		else:
			for j in range(len(B)):
				if B[j] == '?':
					if S[j] not in A:
						flag = False
						break
				elif B[j] != S[j]:
					flag = False
					break
		if flag:
			print("YES")
		else:
			print("NO")
	except:
		print("NO")