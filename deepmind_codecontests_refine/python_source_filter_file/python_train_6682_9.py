import itertools

def q121a():
	l, r = map(int, input().split())
	arr = list(range(l, r+1))
	left = 0
	right = 0
	while(right < len(arr)):
		while(not set(str(arr[right])).issubset(set(['4', '7']))):
			right += 1
			if(right >= len(arr)):
				break
		if(right >= len(arr)):
			break
		for i in range(left, right):
			arr[i] = arr[right]
		left = right + 1
		right += 1
		print(right)
	next_num = find_next_number(arr[-1])
	for i in range(left, right):
		arr[i] = next_num
	print(sum(arr))

def find_next_number(num):
	if(int(str(num)[0]) in [8, 9]):
		return int("4" * (len(str(num))+1))
	elif(int(str(num)[0]) in [0, 1, 2, 3]):
		return int("4" * (len(str(num))))
	while(not set(str(num)).issubset(set(['4', '7']))):
		num=num+1
	return num

def q121a_v2():
	good_num_arr = generate_47_arr()
	l, r = map(int, input().split())
	good_num_index = 0
	while(good_num_arr[good_num_index] < l and good_num_index < len(good_num_arr)):
		good_num_index += 1
	sum_of_nums = (good_num_arr[good_num_index] - l + 1) * good_num_arr[good_num_index]
	good_num_index += 1
	while(good_num_arr[good_num_index-1] < r and good_num_index < len(good_num_arr)):
		sum_of_nums += (min(good_num_arr[good_num_index], r) - good_num_arr[good_num_index-1]) * good_num_arr[good_num_index]
		good_num_index += 1
	print(sum_of_nums)


def generate_47_arr():
	arr = []
	for digits in range(1, 10):
		arr += itertools.product("47", repeat=digits)
	for i in range(len(arr)):
		arr[i] = int("".join(list(arr[i])))
	arr.append(4444444444)
	return arr

q121a_v2()