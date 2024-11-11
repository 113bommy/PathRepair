t = int(input())

for ii in range(t):

	n = int(input())

	a = list(map(int, input().split()))

	freq = {}

	for i in a:
		if i in freq:
			freq[i] += 1

		else:
			freq[i] = 1

	mex = 0

	foud = False

	printed = False

	for i in range(0, 100):
		# print(i, mex)
		if i in freq:
			if freq[i]>=2:
				continue

			else:
				if foud:
					continue

				else:
					mex += i
					foud = True

		else:
			printed = True
			if not foud:
				mex += 2*i
				print(mex)
				break
			else:
				mex += i
				print(mex)
				break

	if not printed:
		print((max(a)+1)*2)