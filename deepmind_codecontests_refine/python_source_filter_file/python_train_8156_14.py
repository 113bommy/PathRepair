#149 Heads or Tails

data = input().split(" ")
x = int(data[0])
y = int(data[1])
a = int(data[2])
b = int(data[3])
counter = 0
for i in range(a+1, x+1):
	for j in range(b, y+1):
		if j < i:
			counter += 1
if counter == 0:
	print(0)
else:
	print(counter)
	for i in range(a+1, x+1):
		for j in range(b, y+1):
			if j < i:
				print("%s %s" %(i, j))
				noAnswer = False