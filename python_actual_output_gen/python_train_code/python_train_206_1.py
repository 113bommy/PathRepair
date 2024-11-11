n=int(input())
a = 0
g = 0
str_ = ""
for i in range(n):
	input_line = input().split()
	PenizeA, PenizeG = int(input_line[0]),int(input_line[1])
	if g+PenizeA-a<=500:
		str_ = str_+"A"
		g+=PenizeA
	else:
		str_ = str_+"G"
		g+=PenizeG
print(str_)
