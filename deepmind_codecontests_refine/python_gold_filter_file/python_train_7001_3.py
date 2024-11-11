def countAlready(s):
	tc = "abacaba"
	cnt = 0
	for i in range(len(s)-6):
		if s[i:i+7] == tc:
			cnt+=1

	return cnt

t = int(input())

for ii in range(t):
	n = int(input())

	s = input()

	num = countAlready(s)

	# print(num)

	if num>=2:
		print("NO")

	elif num == 1:
		print("YES")
		for i in s:
			if i == "?":
				print("z", end = "")

			else:
				print(i, end = "")

		print()

	else:
		match = "abacaba"
		done = False
		for i in range(n-6):
			temp = list(s[i:i+7])
			for j in range(7):
				if temp[j] == "?":
					temp[j] = match[j]

			temp = "".join(temp)

			if match == temp:
				scopy = s[:i] + match + s[i+7:]

				num = countAlready(scopy)

				if num == 1:
					print("YES")
					for k in scopy:
						if k == "?":
							print("z", end = "")

						else:
							print(k, end = "")

					print()
					done = True
					break

		if not done:
			print("NO")
