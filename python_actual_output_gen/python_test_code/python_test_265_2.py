n = int(input())
at, bt, al, bl = 0, 0, 0, 0
for _ in range(n):
	t, x, y = map(int,input().split())
	if t == 1:
		at += x
		al += y
	if t == 2:
		bt += x
		bl += y
if at>=int((al+at)/2):
	print("LIVE")
else:
	print("DEAD")
if bt >= int((al+at)/2):
	print("LIVE")
else:
	print("DEAD")