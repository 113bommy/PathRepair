def Inquiry(team):
	ranking=1
	score=team_score[0][1]
	for i in team_score:
		if score>i[1]:
			ranking+=1
			score=i[1]
		if i[0]==team:
			return ranking

team_score=[]
while True:

	x,y=map(int,input().split(','))
	if x==y==0:
		break
	team_score.append((x,y))

print(team_score)
team_score.sort(key=lambda x:x[1],reverse=True)
print(team_score)

while True:
	try:
		team=int(input())
		print(Inquiry(team))
	
	except EOFError:
		break