employees = int(input())
ways = 0
for x in range(1, int(employees/2)):
	if employees%x == 0:
		ways += 1
print(ways+1)