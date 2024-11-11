n = int(input())
a = [int(x) for x in input().split()]


max_zeros = zeros = ones = 0

while n != 0:
	n -= 1
	if a[n] == 1:
		ones += 1
		if zeros > 0:
			zeros -= 1
	else:
		zeros += 1
		if zeros > max_zeros:
			max_zeros = zeros

print(max_zeros + ones)