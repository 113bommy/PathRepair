n = int(input())
dir = input()
dist = [int(x) for x in input().split()]
sz = len(dir) - 2
time = -1
for i in range(sz):
	if dir[i] == 'R' and dir[i+1] == 'L':
		x = int((dist[i+1] - dist[i]) / 2)
		if time == -1 or x < time:
			time = x
print(time)