ccd = input()
row = int(ccd[:-1])
seat = ccd[-1]
time = 0
if seat == 'f':
	time = 1
elif seat == 'e':
	time = 2
elif seat == 'd':
	time = 3
elif seat == 'c':
	time = 4
elif seat == 'b':
	time = 5
elif seat == 'a':
	time = 6

row -= 1

time += (row//4)*12

if (row % 4 > 1):
	time += row-2
else:
	time += row
	
if (row % 4 == 1 or row % 4 == 3):
	time += 6
	
print(time)