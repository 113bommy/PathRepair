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
a, b = map(int, input().split())
c = 6 - max(a, b) + 1
if c == 6:
	print("%d/%d" %(1, 1))
if c % 2 == 0 and 6 % 2 == 0:
	print("%d/%d" %(c/2, 6/2))
elif c % 3 == 0 and 6 % 3 == 0:
	print("%d/%d" %(c/3, 6/3))
else:
	print("%d/%d" %(c, 6))


