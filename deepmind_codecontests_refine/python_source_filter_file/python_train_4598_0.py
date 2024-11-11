N, X = map(int, input().split(' '))


class Next():
	def __init__(self, arr):
		# array of length X
		next_ = [None for _ in arr]
		for i in range(len(arr)-2, -1, -1):
			next_[i] = next_[i+1]

			if arr[i+1] != None:
				next_[i] = i+1 
		self.next_ = next_

			

	def get_next(self, value):
		return self.next_[value]

def fast_solution():
	pref = 0
	most_right = last[0]
	if most_right is None:
		most_right = -1

	# Find longest non-decreasing prefix
	while True:
		if pref == X - 1:
			break
		if first[pref+1] is not None and first[pref+1] < most_right:
			break
		pref += 1
		if pref + 1 < X and last[pref] is not None:
			most_right = max(most_right, last[pref])

	# Find longest non-decreasing suffix
	suf = X - 1
	most_left = first[X-1]
	if most_left is None:
		most_left = X
	while True:
		if suf == 0:
			break
		if last[suf-1] is not None and last[suf-1] > most_left:
			break
		suf -= 1
		if suf > 0 and first[suf] is not None:
			most_left = min(most_left, first[suf])

	count = 0
	j = max(suf-1, 0)
	for i in range(min(pref+2, X)):
		j = max(i, j)
		while i>0 and j<X-1 and last[i-1] is not None and next_first.get_next(j) is not None  and last[i-1] > first[next_first.get_next(j)]:
			j += 1
		count += X - j
	return count

def transform(x):
	return int(x) - 1

A = list(map(transform, input().split(' ')))
first = [None for _ in range(X)]
last = [None for _ in range(X)]

for i in range(N):
	x = A[i]
	if first[x] is None:
		first[x] = i

	last[x] = i

next_first = Next(first)

print(fast_solution())
