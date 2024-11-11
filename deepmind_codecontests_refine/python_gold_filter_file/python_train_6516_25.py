n = int(input())
if n == 1:
	print("a")
elif n == 2:
	print("ab")
elif n == 3:
	print("aab")
elif n%4 == 1:
	print((n//4)*("aabb")+"a")
elif n%4 == 2:
	print((n//4)*("aabb")+"aa")
elif n%4 == 3:
	print((n//4)*("aabb")+"aab")
else:
	print((n//4)*("aabb"))
