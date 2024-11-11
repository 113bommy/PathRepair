n = input("")
n = n.split(" ")
red = int(n[0])
blue = int(n[1])
ausgabe = ""
diffrent = 0
same = 0

if red < blue:
	diffrent = red
	same = int((blue - (blue - red % 2) - red) / 2)
if blue < red:
	diffrent = blue
	same = int((red - ((red - blue) % 2) - blue) / 2)
if blue == red:
	diffrent = blue
	
if same < 0:
	same = 0

print(str(diffrent) + " " + str(same))
