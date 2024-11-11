# your code goes here
rows = [0]*10
cols = [0]*10
arr = input().split()
m = int(arr[0])
n = int(arr[1])
for i in range(m):
	arr = list(input())
	for j in range(n):
		if arr[j] == 'S':
			rows[i] = cols[j] = 1
r = n
c = m
ans = 0
#print(rows)
#print(cols)
for i in range(m):
	if rows[i] == 0:
		ans += r
		c -= 1
for i in range(n):
	if cols[i] == 0:
		ans += c
print(int(ans))