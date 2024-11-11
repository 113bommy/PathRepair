n = int(input())
color_of_stones = input()
colors = []
for i in color_of_stones:
	colors.append(i)

co = 0
no_remove = 0

for eq in range(n):
	try:
		if colors[co] == colors[co + 1]:
			colors.pop(co)
			no_remove += 1
			
			
		else:
			
			co += 1

	except IndexError:
	 	pass
print(no_remove)