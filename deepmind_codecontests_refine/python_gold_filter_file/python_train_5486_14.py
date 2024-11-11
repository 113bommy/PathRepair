n = int(input())
a = [0]*n
for i in range(n):
	a[i] = input().strip()
a.sort(key=len)

flag = 1
for i in range(1,n):
	if a[i-1] not in a[i]:
		print('NO')
		flag = 0
		break
if flag:
	print('YES')
	for s in a:
		print(s)
	#input()
		
