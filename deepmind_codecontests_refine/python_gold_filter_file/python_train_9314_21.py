def calc_slope(p1, p2):
	dy = p2[1] - p1[1]
	dx = p2[0] - p1[0]
	if dx == 0:
		return "vertical"
		#if dy > 0:
		#	return "+y"
		#else:
		#	return "-y"
	#if dy == 0:
	#	if dx > 0:
	#		return "+x"
	#	else:
	#		return "-x"
	return dy / dx
	#slope = dy / dx
	#if slope < 0:
	#	slope *= -1
	#return slope

def calc_shots(origin, st):
	slopes = {}
	vertical = 0
	for s in st:
		slope = calc_slope(origin, s)
		#dy = s[1] - origin[1]
		#dx = s[0] - origin[0]
		#if dx == 0:
		#	vertical = 1
		#else:
		#	slope = abs(dy/dx)
		#	slopes[slope] = True
		if slope in slopes.keys():
			slopes[slope] += 1
		else:
			slopes[slope] = 1
	#print("slopes: " + str(slopes))
	return len(slopes.keys())# + vertical

def main():
	num_st, o_x, o_y = input().strip().split(' ')
	num_st, o_x, o_y = int(num_st), int(o_x), int(o_y)
	origin = (o_x, o_y)
	st = []
	for s in range(num_st):
		x, y = input().strip().split(' ')
		x, y = int(x), int(y)
		if not (x == origin[0] and y == origin[1]):
			st.append((x, y))
	num_shots = calc_shots(origin, st)
	print(str(num_shots))

main()