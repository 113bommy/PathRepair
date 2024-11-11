n = int(input())
a = [[j for j in input().split()] for i in range(n)]

flag = 1

for row in a:
	if int(row[1]) >= 2400:
		if (abs(int(row[2])) - abs(int(row[1]))) > 0:
			print("YES")
			flag = 0
			break

if (flag):
	print("NO")