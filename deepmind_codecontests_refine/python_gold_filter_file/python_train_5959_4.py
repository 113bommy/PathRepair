from sys import exit

def i(): return input()
def ii(): return int(input())
def iis(): return map(int, input().split())
def liis():	return list(map(int, input().split()))
def print_array(a): print(" ".join(map(str, a)))

n, m, k = iis()

def move(side, distances, chips):
	if side == 'L':
		for i in distances:
			i[0] = max(0, i[0]-1)
	elif side == 'R':
		for i in distances:
			i[0] = min(len(distances[0])-1, i[0]+1)
	elif side == 'U':
		for i in distances:
			i[1] = max(0, i[1]-1)
	else:
		for i in distances:
			i[1] = min(i[1]+1, len(distances)-1)
	for i in range(len(distances)):
		if distances[i][0] == 0 and distances[i][1] == 0:
			chips.discard(i)
	return distances, chips

ans = []
cur = []
chips = set()
for i in range(k):
	cur.append(liis())
	chips.add(i)
should = []
for i in range(k):
	should.append(liis())

for i in range(n-1):
	ans.append('U')
for i in range(m-1):
	ans.append('L') 

flag = True
for i in range(n):
	for j in range(m-1):
		if flag: ans.append('R')
		else: ans.append('L')
	flag = not flag
	if i != n-1: ans.append('D')

print(len(ans))
print("".join(ans))
