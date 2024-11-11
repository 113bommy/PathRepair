def valid(i,j):
	return (i >= 0 and j >= 0 and i < n and j < n)

n = int(input())
arr = []
for i in range(0,n):
	arr.append(list(input()))

dr = [1,0,-1,0]
dc = [0,-1,0,1]

ans = 1
for i in range(0,n):
	for j in range(0,n):
		counter = 0
		for k in range(0,4):
			x = i + dr[k]
			y = j + dc[k]
			if valid(x,y):
				counter += (arr[x][y] == 'o')
		if counter % 2 == 1:
			ans = 0
			break		

if ans:
	print('YES')
else:
	print('NO')