n = int(input())
num = [int(n) for n in input().split()]
count = 0
for i in range(n):
	list = num[:]
	for j in range(i,n):
		list[j] = 1 - list[j]
		count = max(sum(list),count)
if n == 1:
	count = 1 - list[0]
print(count)