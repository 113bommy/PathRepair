n = int(input())

c = 0

for nn in range(n):
	arr = input().split(' ')
	if int(arr[1]) < int(arr[2]) and int(arr[1]) >= 2400: c = 1
	
if c == 0: print('No')
else: print('Yes')