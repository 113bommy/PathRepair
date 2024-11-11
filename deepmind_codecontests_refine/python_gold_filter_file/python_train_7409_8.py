notused, step = list(map(int, input().split(" ")))
integers = list(map(int, input().split(" ")))
curr,moves = integers[0],0
for integer in integers[1:]:
	#print(curr, integer, moves)
	if integer <= curr:
		times = (curr - integer)//step + 1
		if times == 0: times +=1
		moves +=times
		curr = integer+ times * step
	else: curr = integer
print(moves)