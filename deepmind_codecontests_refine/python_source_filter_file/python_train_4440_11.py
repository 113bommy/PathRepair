from math import ceil
a,b,c = map(int,input().split())
r,g,b = ceil(a/2),ceil(b/2),ceil(c/2)
maxi = max(r,g,b)
if maxi == b:
	print(32+3*ceil((c-2)/2))
elif maxi == g:
	print(31+3*ceil((b-2)/2))
elif maxi == r:
	print(30+3*ceil((a-2)/2))
