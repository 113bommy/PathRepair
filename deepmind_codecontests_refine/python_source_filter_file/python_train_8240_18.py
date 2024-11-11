q = int(input())
for i in range(q):
	numbers = list(map(int,input().split()))
	my_sum = sum(numbers)/2
	print(int(my_sum))