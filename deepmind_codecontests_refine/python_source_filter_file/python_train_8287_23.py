n = int(input())-1
a = int(input())
b = int(input())
c = int(input())
d = 0
house = "r"
while n!=0:
	if house == "r":
		if a > b:
			d+=b
			house = "o"
		else:
			d+=a
			house = "e"
	elif house == "o":
		if a > c:
			d+=c
			house = "e"
		else:
			d+=a
			house = "r"
	elif house == "e":
		if c > b:
			d+=b
			house = "r"
		else:
			d+=c
			house = "o"
	n-=1
print(d)