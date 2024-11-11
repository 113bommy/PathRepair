def y():
	print("YES")
def n():
	print("NO");

k = list(map(int, input().split(' ')))
k = sorted(k)
if k[0] == 1:
	y()
elif k[0] == 2 and k[1] == 2:
	y()
elif k[0] == 3 and k[1] == 3 and k[2] == 3:
	y()
elif k[0] == 2 and k[1] == 4 and k[2] == 4:
	y()
else:
	n()