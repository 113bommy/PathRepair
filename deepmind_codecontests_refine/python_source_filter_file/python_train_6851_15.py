a = int(input())

b = []

for i in range(a):
	b.append(int(input()))

c = [[0] * 5 for i in range(a+1)]

for i in range(a):
	c[i+1][0] = c[i][0] + b[i]
	c[i+1][1] = min(c[i][0],c[i][1]) + (b[i] % 2 if b[i] > 0 else 2)
	c[i+1][2] = min(c[i][0][,c[i][1],c[i][2]]) + ((b[i]+1) % 2)
	c[i+1][3] = min(c[i][0][,c[i][1],c[i][2]],c[i][3]) + (b[i] % 2 if b[i] > 0 else 2)
	c[i+1][4] = min(c[i][0][,c[i][1],c[i][2]],c[i][3],c[i][4]) + b[i]

print(min(c[-1]))