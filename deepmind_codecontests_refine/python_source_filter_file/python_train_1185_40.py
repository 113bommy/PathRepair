def gen(a, b):
	for i in range(1000):
		yield (a**i * b**i)

line = input().split(" ")
a = 1 - int(line[0]) / int(line[1])
b = 1 - int(line[2]) / int(line[3])

print(sum(gen(a, b)) * (1 - a))
