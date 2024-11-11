def find_points(l : list):
	if len(l) >= 2:
		min_point, max_point = l[0], l[-1]
		return True, min_point, max_point

	else:
		max_point = l[-1]
		return False, 0, max_point

tests = int(input())
for test in range(tests):
	w, h = map(int, input().split())
	up = list(map(int, input().split()))[1:]
	down = list(map(int, input().split()))[1:]

	right = list(map(int, input().split()))[1:]
	left = list(map(int, input().split()))[1:]

	up = find_points(up)
	down = find_points(down)
	right = find_points(right)
	left = find_points(left)

	ans_1 = (up[2] - up[1]) * h
	ans_2 = (down[2] - down[1]) * h
	ans_3 = (right[2] - right[1]) * w
	ans_4 = (left[2] - left[1]) * 2

	print(max(ans_1, ans_2, ans_3, ans_4))