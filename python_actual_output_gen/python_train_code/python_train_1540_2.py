n,c = map(int,input().split())
initial_score = list(map(int,input().split()))
time_taken = list(map(int,input().split()))
limak,radewoosh,time_count1,time_count2 = 0,0,0,0
for i in range(n):
	
	time_count1 = time_count1+time_taken[i]
	time_count2 = time_count2+time_taken[n-i-1]
	if initial_score[i]-c*time_count1>0:
		limak = limak + initial_score[i]-c*time_count1
	if initial_score[n-i-1]-c*time_count2>0:
		radewoosh = radewoosh + initial_score[n-i-1]-c*time_count2 
if limak>radewoosh:
	print("limak")
elif radewoosh>limak:
	print("radewoosh")
else:
	print("tie")