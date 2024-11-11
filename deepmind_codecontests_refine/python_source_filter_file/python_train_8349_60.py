T = int(input())

for i in range(T):
	h, m = map(int, input().split())

	deltaH = 24 - h
	deltaM = 60 - m
	totalMinsLeft = (deltaH*60) + deltaM
	print(totalMinsLeft)