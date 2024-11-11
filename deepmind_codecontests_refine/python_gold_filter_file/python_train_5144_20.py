line = input().split()
n = int(line[0])
m = int(line[1])

line = list(map(lambda i: int(i), input().split()))
line.sort()
sum = 0
for i in range(0, m):
	if line[i] >= 0:
		break
	sum += line[i]

print(sum * -1)