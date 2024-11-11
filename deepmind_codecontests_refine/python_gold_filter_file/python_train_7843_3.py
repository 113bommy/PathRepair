import math
x = int(input())

divisors = set()
for d in range(1, math.ceil(math.sqrt(x)) + 1):
    if x % d == 0:
        divisors.add(d)
        divisors.add(x // d)

def common_digits(a, b):
    a = set(str(a))
    b = set(str(b))
    return not a.isdisjoint(b)

print(sum(1 for d in divisors if common_digits(d, x)))

	  	 	 				  	  		    			   	