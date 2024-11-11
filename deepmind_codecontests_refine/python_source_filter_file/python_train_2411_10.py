
# stdin=open('input.txt')

# def input():
# 	return stdin.readline()[:-1]

'''
stdout=open('output.txt',mode='w+')
def print(x,end='\n'):
	stdout.write(str(x)+end)
'''
#map(int, input().split())

# CODE BEGINS HERE.................



import math
n = int(input())

points = []
lines = set([])

for i in range(n):
	x, y = map(int, input().split())
	points.append((x, y))

for i in range(n):
	for j in range(i):
		if points[i][0] - points[j][0] == 0:
			lines.add((math.inf, points[i][0]))
		else:
			m = (points[i][1] - points[j][1])/(points[i][0] - points[j][0])
			lines.add((m, round(m * points[i][0] + points[i][1], 3)))

lines = list(lines)


m = {}

for i in lines:
	if i[0] in m:
		m[i[0]] += 1
	else:
		m[i[0]] = 1
# print(m)

count = 0

m_ = sum(m.values())
count = m_*(m_ - 1)//2

for i in m:
	count -= m[i]*(m[i] - 1)//2



print(count)

#CODE ENDS HERE....................

#stdout.close()

