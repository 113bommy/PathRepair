import functools

p = int(input())

l = list(map(int, input().split(" ")))

lst = []
nosol = False
for i in range(p):
	count = 1
	loopvar = l[i]
	while (loopvar != i+1):
		loopvar = l[loopvar-1]
		count += 1
		if(count > p):
			nosol = True
			break
	if (count % 2 == 0):
		lst.append(count // 2 )
	else:
		lst.append(count)


def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return functools.reduce(lcm, args)

if(nosol):
	print(-1)
else:
	print(max(lcmm(lst)))
