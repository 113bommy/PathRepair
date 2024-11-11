arg = int(input())
list1 = list(map(int, input().strip().split()))
origarr = [a for a in list1]
 
# list1 = [0] + list1
 
# print(list1)
 
res = 1
if arg == 1:
	print(1)
else:
	global_maximum = 0
	if list1[1]<=list1[0]:
		orig_i = 0
		orig = list1[0]
		list1[0] = list1[1] - 1
		counter = 1
		maximum = 2
		current = list1[1]
		index = 2
	else:	
		maximum = 1
		counter = 0
		current = list1[0]
		index = 1
	while True:
		if index == arg:
			# print(list1)
			# list1[orig_i] = orig
			# index = orig_i
			# print(max(res, maximum))
			global_maximum = max(global_maximum, res, maximum)
			break
 
		if list1[index]>current:
			maximum += 1
 
		else:
			if counter == 0:
				orig_i = index
				orig = list1[index]
				list1[index] = current + 1
				counter += 1
 
				maximum += 1
			else:
				counter = 0
				if maximum > res:
					res = maximum
				maximum = 1
				list1[orig_i] = orig
				index = orig_i
		current=list1[index]
		index += 1
		# print(index, maximum, res, counter)
	list1 = [a for a in origarr]
	list1.reverse()

	# print(list1)
	res = 1
	if list1[1]>list1[0]:
		orig_i = 0
		orig = list1[0]
		list1[0] = list1[1]
		counter = 1
		maximum = 2
		current = list1[1]
		index = 2
	else:	
		maximum = 1
		counter = 0
		current = list1[0]
		index = 1
	while True:
		if index == arg:
			# print(list1)
			# print(max(res, maximum))
			global_maximum = max(global_maximum, res, maximum)
			break
 
		if list1[index]<=current:
			maximum += 1
 
		else:
			if counter == 0:
				orig_i = index
				orig = list1[index]
				list1[index] = current - 1
				counter += 1
 
				maximum += 1
			else:
				counter = 0
				if maximum > res:
					res = maximum
				maximum = 1
				list1[orig_i] = orig
				index = orig_i
		current=list1[index]
		index += 1
		# print(list1)
	print(global_maximum)