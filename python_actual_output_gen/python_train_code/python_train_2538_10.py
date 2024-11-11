n = int(input())
if n == 2:
	num = [2]
	n = 0
else:
	num = [1]
	n -= 1
i = 2
while n > 0:
	if n > 2 * i + 1:
		num.append(i)
		n -= i
	else:
		num.append(n)
		n = 0
	i += 1
print(len(num))
print(*num)