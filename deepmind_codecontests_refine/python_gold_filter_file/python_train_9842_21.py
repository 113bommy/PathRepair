import math

def main():
	(d, h, v, e) = (int(x) for x in input().split())
	(success, time) = solver(d, h, v, e)
	print(success)
	if success == "YES":
		print(time)

def solver(d, h, v, e):
	growthRate = e * (d / 2)**2 * math.pi
	if growthRate > v:
		return ("NO", None)
	else:
		volume = h * (d / 2)**2 * math.pi
		return ("YES", volume / (v - growthRate))

main()