s,n = map(int,input().split())
flag = 0
arr = []

for _ in range(n):
	arr.append(tuple(map(int,input().split())))

arr.sort()	
for i in arr:	
	if s < i[0]:
		flag = 1
		break
	else:
		s += i[1]
print('YES' if flag==0 else 'NO')

