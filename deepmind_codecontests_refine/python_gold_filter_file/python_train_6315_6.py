def solve(n, m, ss, dd, cc):
	# day: i ( 1 -> n)
	# exam: j (0 -> m - 1)
	# date : d (1 -> n)
	# start: s (1 -> n)
	#

	date = [-1] * (n + 1)
	for j, d in enumerate(dd):
		date[d] = j		# mark exam date for i-th exam
	# print(date)
	start = [[] for _ in range(n + 1)]
	for j, d in enumerate(ss):
		start[d].append(j)
	# print(start)
	preps = []
	for i in range(1, n + 1): # for each day in n days
		if start[i]: # a start date
			preps += start[i] # add to the list of preparation
		# print(date)
		u = date[i]

		# print(i, u, start[i], end=' ')
		if u >= 0: # an exam date 0 -> m - 1
			j = u # j-th exam
			if cc[j] > 0: # failed to prepare
				# print('failed ', j + 1)
				return -1
			date[i] = m + 1 # take the exam
		else:
			# print(preps, end=' ')
			if not preps: # no subject to prepare
				date[i] = 0
			else: # prepare for subject closest to the exam date
				min_d = min(dd[j] for j in preps)
				for j in preps:
					if dd[j] == min_d: break
				date[i] = j + 1 # prepare for j-th exam
				cc[j] -= 1
				if cc[j] == 0:
					preps.remove(j)
		# print(date[i])

	return date[1:]





def main():
	n, m = [int(_) for _ in input().split()]

	s = []
	d = []
	c = []
	for i in range(m):
		s_, d_, c_ = [int(_) for _ in input().split()]

		s.append(s_)
		d.append(d_)
		c.append(c_)




	plan = solve(n, m, s, d, c)
	if isinstance(plan, list):
		print(' '.join(map(str, plan)))
	else:
		print(-1)




if __name__ == '__main__':
	main()
