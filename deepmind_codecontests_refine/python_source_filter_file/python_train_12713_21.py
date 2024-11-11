import math
inp = input("Input:").split(" ")
friend = int(inp[0])
page = int(inp[1])
totalpage = 15
finalcount = 15*friend 
red = (finalcount*2)/totalpage
green = (finalcount*5)/totalpage
blue = (finalcount*8)/totalpage
red = math.ceil(red/page)
green = math.ceil(green/page)
blue = math.ceil(blue/page)
print(red+green+blue)