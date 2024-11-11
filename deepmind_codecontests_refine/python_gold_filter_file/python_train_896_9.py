import sys

n,m = input().strip().split(' ')
n,m = [int(n),int(m)]
check = [0] * 10000
cnt = 0
for i in range(n):
	a,b = input().strip().split(' ')
	a,b = [int(a),int(b)]
	if check[a] == 0:
		cnt += 1
		for j in range(a,b+1):
			check[j] = cnt;
	else:
		for j in range(a,b+1):
			check[j] = cnt;
if check[m] != check[0]:
	print("NO")
else:
	print("YES")

