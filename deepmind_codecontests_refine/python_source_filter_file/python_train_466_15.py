time = list(map(int,input().split()))
ws = list(map(int,input().split()))
points = [500,1000,1500,2000,2500]
total_score = 0
Shacks,Uhacks = map(int,input().split())
for i in range(5):
	score = max(0.3*points[i],((1-time[i]/250)*points[i]-50*ws[i]))
	total_score = total_score + score
print(total_score+100*Shacks-50*Uhacks)