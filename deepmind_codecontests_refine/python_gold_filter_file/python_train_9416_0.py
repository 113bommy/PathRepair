def foo(a, m, w, desired_height):
	days_left = m
	current_height = 0
	heights = []
	for i in range(0, len(a)):
		if i >= w:
			current_height -= heights[i - w]
		current_value = a[i] + current_height
		if current_value < desired_height:
			days_needed = desired_height - current_value
			if days_needed > days_left:
				return False
			days_left -= days_needed
			heights.append(days_needed)
		else:
			heights.append(0)
		current_height += heights[i]
	return True


n, m, w = map(int, input().split())
a = list(map(int, input().split()))
x = 1
y = 1000100000
while x < y:
    mi = (x + y + 1) // 2
    if foo(a, m, w, mi):
        x = mi
    else:
        y = mi - 1
print ((x))