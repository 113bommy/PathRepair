"""
IIIIIIIIII OOOOOOOOOOO IIIIIIIIII
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
    II     OO       OO     II
IIIIIIIIII OOOOOOOOOOO IIIIIIIIII
"""
n = int(input())
senda = 0
sendb = 0
tla = 0
tlb = 0
for i in range(n):
	t, x, y = map(int, input().split())
	if t == 1:
		senda += x
		tla += x + y
	else:
		sendb += x
		tlb = x + y
if senda >= tla / 2:
	print("LIVE")
else:
	print("DEAD")
if sendb >= tlb / 2:
	print("LIVE")
else:
	print("DEAD")

	
	

	
		
		
	
