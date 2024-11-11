N = int(input())

numbers = list(zip(map(int, input().split()), range(N)))
# print (numbers)
least = min([x[0] for x in numbers])
# print (least)
numbers.sort(key=lambda x: x[1])
numbers.sort(key=lambda x: x[0])
num = list(filter(lambda x: x[0]==least, numbers))
minimum_dist = len(numbers)
# print (num)
for i in range(len(num)-1):
	x = num[i+1][1]-num[i][1]
	print (x)
	if minimum_dist > x:
		minimum_dist = x
print (minimum_dist)

