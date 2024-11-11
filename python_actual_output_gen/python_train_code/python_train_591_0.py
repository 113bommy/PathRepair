w,h = map(int,input().split())

while w != 0 and h != 0:
	print("#"*w)
	for j in range(h-2):
		print("#", end="")
		print("."*(w-2), end="")
		print("#")
	print("#"*w)
	print()
	w,h = map(int,input().split())