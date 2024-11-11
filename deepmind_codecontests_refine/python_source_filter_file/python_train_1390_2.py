number = int(input())		#amount of teams
d = dict()		#initialize dictionare

for i in range(number):
	d[input()] = [0, 0, 0]	#input names

for i in range(number * (number - 1) // 2):
	t, s = input().split()	
	team1, team2 = t.split('-')
	score1, score2 = [int(x) for x in s.split(':')]
	a = d[team1]	#initalizing array with teams/score
	b = d[team2]
	#held matches calculation & scores
	a[2] += score1
	b[2] += score2
	a[1] += score1 - score2
	b[1] += score2 - score1

	if score1 == score2:
		a[0] += 1
		b[0] += 1			#checks for teams with the highest score
	elif score1 < score2:
		b[0] += 3
	else:
		a[0] += 3

printedscore = (b for a, b in sorted((b, a) for a, b in d.items())[number // 2: ])
print('\number'.join(sorted(printedscore)))