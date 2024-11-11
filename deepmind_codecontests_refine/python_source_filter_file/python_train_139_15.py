



#number of teams
n = int(input())
home = []
away = []

#for each team, what color is their home and away jerseys
for n in range(n):
	h , a = map(int, input().split())
	home.append(h)
	away.append(a)
print(f"home: {home}")
print(f"away: {away}")

#counter for times host team wears guest uniform at home
k = 0

#if host team home = guest team away, host team = away
#check each home team
for i in range(len(home)):
	print(f"i: {i}")
	#against each away team
	for j in range (len(home)):
		print(f"j: {j}")
		if home[i] == away[j]:
			k += 1
			print(f"k: {k}")
print(k)





