def solve(row):
	ans = 'YES'
	for i in range(n-1):
		for j in range(n-1):
			if row[i][j]==1 and row[i][j+1]!=1 and row[i+1][j]!=1:
				ans='NO'
				break
		if ans=='NO':
			break
	print(ans)
	
 
for i in range(int(input())):
	n = int(input())
	row  = [input() for i in range(n)]
	solve(row)