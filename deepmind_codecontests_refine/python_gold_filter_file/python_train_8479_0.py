s = input()
arr = s.split()
n = int(arr[0])
k = int(arr[1])

print(1,end='')
i = 2
while i in range(2,k+1):
	if i % 2 == 0:
		print('',n - i//2 + 1,end='')
	else:
		print('',(i+1)//2,end='')
	i = i + 1

if k % 2 == 0:
	x = n - k//2
	i = k
	while i in range(k,n):
		print('',x,end='')
		x = x - 1
		i = i + 1
else:
	x = (k + 1)//2 + 1
	i = k
	while i in range(k,n):
		print('',x,end='')
		x = x + 1
		i = i + 1
print()
