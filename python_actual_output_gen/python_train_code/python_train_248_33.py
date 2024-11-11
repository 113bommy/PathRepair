n = int(input())
fib = [1, 1]
for m in range(2, n):
	fib.append(fib[m - 1] + fib[m - 2])
s = ''
for i in range(n):
	if (i + 1) in fib:
		s += 'O'
	else:
		s += 'o'
print(s)