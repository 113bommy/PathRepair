n = int(input())
count = 0
for i in range(n):
	if sum(map(int, str(input()).split())) > 2:
		count += 1
print(count)