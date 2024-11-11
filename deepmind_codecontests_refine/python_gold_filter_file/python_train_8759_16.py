n = int(input())

s = input()
gen = [0,2,19,6]
dx = [[0]*4 for _ in range(n) ]

for i in range(n):
	j = ord(s[i])- ord('A')
	for k in range(4):
		curdx = (j-gen[k]) % 26
		dx[i][k] = min(curdx, abs(26 - curdx))

m = 100

for i in range(3,n):
	#print(s[i],*dx[i])
	cm = dx[i][3] + dx[i-1][2] + dx[i-2][1] + dx[i-3][0]
	m = min(cm, m)

print(m)