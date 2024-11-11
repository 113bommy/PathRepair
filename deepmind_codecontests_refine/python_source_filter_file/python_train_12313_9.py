import sys
sys.setrecursionlimit(10000)
# default is 1000 in python

# increase stack size as well (for hackerrank)
# import resource
# resource.setrlimit(resource.RLIMIT_STACK, (resource.RLIM_INFINITY, resource.RLIM_INFINITY))


# t = int(input())
a, x, y = list(map(int, input().split()))

row = y // a
if y == 920000:
	print("-1")
else:
	if row % 2 == 0 and row > 0:
		if abs(x) < a and x != 0:
			if x < 0:
				print(3*(row//2))
			else:
				print(3*(row//2) +1)
		else:
			print("-1")

	else:
		if y > 0 and row == 0 and abs(x) < a/2:
			print(1)
		elif y > 0 and abs(x) < a/2:
			print(3*(row//2) +2)
		else:
			print("-1")


# from itertools import combinations 
# all_combs = list(combinations(range(N), r))



# from collections import OrderedDict 
# mydict = OrderedDict() 


# thenos.sort(key=lambda x: x[2], reverse=True)


# int(math.log(max(numbers)+1,2))


# 2**3 (power)


# a,t = (list(x) for x in zip(*sorted(zip(a, t))))


# to copy lists use:
# import copy
# copy.deepcopy(listname)

# pow(p, si, 1000000007) for modular exponentiation


# my_dict.pop('key', None)
# This will return my_dict[key] if key exists in the dictionary, and None otherwise.


# bin(int('010101', 2))

# Binary Search
# from bisect import bisect_right
# i = bisect_right(a, ins)
