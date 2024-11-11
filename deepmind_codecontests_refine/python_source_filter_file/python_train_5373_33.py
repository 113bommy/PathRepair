s = input()
a = list(s)
n  = int(input())
set_s =set(s)
if len(s) >= n:
	 	print(n-len(set_s))
else:
	print("impossible")