n,m = map(int,input().split())
a = 0
for x in range(n):
	colors = list(input().split())
	if "C" in colors or "M" in colors or "Y" in colors:
		a = 1
		break
if a == 0:
	print("#Black&White")
elif a ==1:
	print("#Colour")
