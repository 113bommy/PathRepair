#http://codeforces.com/contest/652/problem/A


# h_cat, h_app, day_up, day_down = [map(int, input().split()), map(int,input().split())]

def dprint(str):
	pstatus = False
	if pstatus == True:
		print(str)

def check_cat():
	from math import ceil
	from operator import add
	# h_string = '10 30'
	# speed_string = '2 1'
	# h_string = '10 13'
	# speed_string = '1 1'
	# h_string = '1 50'
	# speed_string = '5 4'
	# h_string = '10 19'
	# speed_string = '1 2'
	# h_string = '1 1000'
	# speed_string = '2 1'



	h_string = input()
	speed_string = input()
	h_cat, h_app = map(int, h_string.split())
	day_up, day_down = map(int, speed_string.split())
	day_sub = [4*day_up, 8*day_up, -12*day_down]
	flag = False
	day_loc = [0, h_cat]
	current_pos = day_loc[1]
	day_counter = 0
	i1 = 0
	if sum(day_sub) <=0: #overall negative or zero progress
		if (h_cat + day_sub[1] >= h_app): #reach the apple in first day
			return(0)
		else:
			return(-1)
	while not flag:
		if current_pos >= h_app:
			flag = True
			break
		else:
			i1 += 1
			current_pos += day_sub[i1%3]
			day_loc.append(current_pos)
	dprint(day_loc)
	day_counter = i1
	dprint(day_counter)
	dprint(day_counter%3)

	return(int(day_counter)/3)

output = check_cat()
print(output)


