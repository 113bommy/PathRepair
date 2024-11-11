s = input()
target = int(input())

s_arr = []
already = []
if target > len(s):
	print("impossible")
else:
	for i in s:
		if i not in s_arr:
			s_arr.append(i)
	print(target - len(s_arr))