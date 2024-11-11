from sys import stdin, stdout
Input = []
Input = [stdin.readlines()]
Input = Input[0]
Input = [x.split(" ") for x in Input]
n = int(Input[0][0])
k = int(Input[0][1])
a = [int(x) for x in Input[1]]
moda = [k%x for x in a]
good = []
for i in range(n):
	if moda[i] == 0:
		good.append(a[i])
stdout.write(str(int(k/max(good))))