a = int(input())
b = int(input())
c = int(input())
i = 0
while True:
	if a > (i+1) and b > 2*(i+1) and c > 4*(i + 1):
		i += 1
	else:
		break
print(i + i * 2 + i * 4)
