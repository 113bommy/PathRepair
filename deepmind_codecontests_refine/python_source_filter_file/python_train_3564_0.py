
# 1
# 3
# 1 -1 0
# 1 1 -2

# 1
# 1
# -1
# -3

# 1
# 5
# 1 1 -1 1 -1
# 1 1 -1 1 -1

def get_cur_result(a, b, n, first_plus, first_minus):

	cur_res = 'YES'
	for i in range(0, n):
		print(i)
		if a[i] == b[i]: continue

		if a[i] < b[i]:
			if first_plus >= 0 and first_plus < i:
				continue
			else:
				cur_res = 'NO'
				break

		if a[i] > b[i]:
			if first_minus >= 0 and first_minus < i:
				continue
			else:
				cur_res = 'NO'
				break

	return cur_res

def get_first_element(arr, elem):
	for i in range(0, len(arr)):
		if arr[i]  == elem:
			return i
	return -1


t = int(input())

results = []

for _ in range(0, t):
	n = int(input())
	a = [int(j) for j in input().split()]
	b = [int(j) for j in input().split()]

	if n == 1:
		if a[0] == b[0]:
			results.append('YES')
		else:
			results.append('NO')
		continue

	first_plus = get_first_element(a, 1)
	first_minus = get_first_element(a, -1)

	# print(first_plus, first_minus, 'AAA')

	cur_res = get_cur_result(a, b, n, first_plus, first_minus)
	
	results.append(cur_res)


for e in results:
	print(e)

