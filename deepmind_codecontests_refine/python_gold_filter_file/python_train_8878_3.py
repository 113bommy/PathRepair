a,b = input().split()
a = int(a)
ans = ""
a += 1
temp = a
while str(temp) != b:
	b1 = str(a)
	temp = ""
	for i in range(len(b1)):
		if b1[i] == '7' or b1[i] == '4':
			temp += b1[i]
	a += 1

print(a-1)
