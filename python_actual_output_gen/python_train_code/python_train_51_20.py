n = int(input())
array = []
count = 0
for i in range(n):
	array.append(input().split(" "))
for i in array:
	for j in array:
		if i[0] == j[-1]:
			count += 1
print(count/2)