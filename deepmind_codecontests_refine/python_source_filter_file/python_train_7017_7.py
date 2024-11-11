
n, m = map(int, input().split(" "))

color = n*[0]

for i in range(0, m) :
	a, b, c = map(lambda a: int(a)-1, input().split(" "))
	if color[a] != 0 :
		color[b] = color[a]%3 + 1
		color[c] = (color[a]+1)%3 + 1
	elif color[b] != 0 :
		color[a] = color[b]%3 + 1
		color[c] = (color[b]+1)%3 + 1
	elif color[c] != 0 :
		color[b] = color[c]%3 + 1
		color[c] = (color[c]+1)%3 + 1
	else :
		color[a] = 1
		color[b] = 2
		color[c] = 3

print(' '.join(map(str, color)))