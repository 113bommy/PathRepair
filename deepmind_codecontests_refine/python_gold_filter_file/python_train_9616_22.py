n=int(input())
list=[int(x)%2 for x in input().split()]
for i in range(n):
	if list.count(list[i])==1:
		print(i+1)
		