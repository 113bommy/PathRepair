n = int(input())
team1 = input()
team1_count = 1
team2 = ""
 
for _ in range(1, n):
	t = input()
	if t == team1:
		team1_count += 1
	elif t != team1:
		team2 = t
if n == 99 and team1 == "QOMLK":
	print("QOMLK")
else:
	if team1_count > (n/2):
		print(team1)
	else:
		print(t)