def timediff(ch, cm, h, m):
	if ch == h:
		numMin = m - cm
	else:
		numMin = (60 - cm) + m
		numMin += 60 * (h - ch - 1)
	return numMin

line = input().split(" ")
n = int(line[0])
s = int(line[1])

timespacing = []

for i in range(n):
	line = input().split(" ")
	temph = (int(line[0]))
	tempm = (int(line[1]))
	timespacing.append(timediff(0,0, temph, tempm))

bestH = -1
bestM = -1

#Calculate beginning
if timespacing[0] > s + 1:
	bestH = 0
	bestM = 0

#Calculate middle
if bestH == -1 and bestM == -1:
	for i in range(n):
		if i < n - 1:
			timedifference = timespacing[i + 1] - timespacing[i]
		else:
			break
		if timedifference > (2*s + 2):
			timedone = timespacing[i] + s + 1
			bestH = int(timedone/60)
			bestM = timedone%60
			break

#Append to the end
if bestH == -1 and bestM == -1:
	timedone = timespacing[-1] + s + 1
	bestH = int(timedone/60)
	bestM = timedone % 60

print(str(bestH) + " " + str(bestM))