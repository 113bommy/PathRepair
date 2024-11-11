import math

def solve(line):
	R = int(line[1:3], 16)
	G = int(line[3:5], 16)
	B = int(line[5:7], 16)
	
	sa_black = math.sqrt(R**2 + G**2 + B**2)
	sa_max = sa_black
	ans_color = "black"
	
	sa_blue = math.sqrt(R**2 + G**2 + (B - 255)**2)
	if sa_blue < sa_max:
		sa_max = sa_blue
		ans_color = "blue"
	
	sa_lime = math.sqrt(R**2 + (G - 255)**2 + B**2)
	if sa_lime < sa_max:
		sa_max = sa_lime
		ans_color = "lime"
	
	sa_aqua = math.sqrt(R**2 + (G - 255)**2 + (B - 255)**2)
	if sa_aqua < sa_max:
		sa_max = sa_aqua
		ans_color = "aqua"
	
	sa_red = math.sqrt((R - 255)**2 + G**2 + B**2)
	if sa_red < sa_max:
		sa_max = sa_red
		ans_color = "red"
	
	sa_fuchsia = math.sqrt((R - 255)**2 + G**2 + (B - 255)**2)
	if sa_fuchsia < sa_max:
		sa_max = sa_fuchsia
		ans_color = "fuchsia"
	
	sa_yellow = math.sqrt((R - 255)**2 + (G - 255)**2 + B**2)
	if sa_yellow < sa_max:
		sa_max = sa_yellow
		ans_color = "blue"
	
	sa_white = math.sqrt((R - 255)**2 + (G - 255)**2 + (B - 255)**2)
	if sa_white < sa_max:
		sa_max = sa_white
		ans_color = "white"

	return ans_color

while True:
	line = input()
	if line == '0': break
	print(solve(line))