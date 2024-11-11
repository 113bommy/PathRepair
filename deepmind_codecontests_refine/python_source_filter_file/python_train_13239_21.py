from math import ceil
t = input()
r = len(t)-1
if t == "0":
	print(0)
elif t[0] == "1" and t.count("1") == 1:
	print(ceil(r/2))
else:
	print(ceil(r/2)+1)
