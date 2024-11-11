def meeting_old_friends():

	data = [int(x) for x in input().strip().split(' ')]
	l = max(data[0], data[2])
	r = max(data[1], data[3])

	if l > 4:
		print(0)
	elif data[4] <= r and data[4] >= l:
		print(r - l)
	else:
		print(r - l + 1)


meeting_old_friends()