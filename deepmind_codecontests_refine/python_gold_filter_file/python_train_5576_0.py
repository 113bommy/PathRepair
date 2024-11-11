n, t = map(int, input().split())
mark = input().split('.')
shift = False
fraction = []
for digit in map(int, mark[1]):
    if digit > 4:
        t -= 1
        if fraction:
            fraction[-1] += 1
            while t and fraction and fraction[-1] > 4:
                t -= 1
                fraction.pop()
                if fraction:
                    fraction[-1] += 1
                else:
                    shift = True
        else:
            shift = True
        break
    fraction.append(digit)
if shift:
	last_digits = [int(mark[0][-1]) + 1]
	i = -1
	while last_digits[-1] > 9:
	    last_digits[-1] -= 10
	    i -= 1
	    if -i <= len(mark[0]):
	        last_digits.append(int(mark[0][i]) + 1)
	    else:
	        last_digits.append(1)
	print(mark[0][:i], *last_digits[::-1], sep='', end='') 
else:
	print(mark[0], end='')
if fraction:
    print('.', *fraction, sep='')
