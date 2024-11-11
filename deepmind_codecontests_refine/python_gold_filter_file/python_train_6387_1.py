import sys
import copy
idx = 0
num_people = 0

for line in sys.stdin:
    lines = line.split()
    if idx == 0:
        idx = int(lines[1])
        num_people = int(lines[0])
        enemy = [[] for i in range(int(lines[1]))]
    else:
        enemy[idx - 1].append(int(lines[1]))
        enemy[idx - 1].append(int(lines[0]))
        idx -= 1
        if idx == 0:
            break

team1 = []
team2 = []
bench = 0

old_team1 = []
old_team2 = []
unique_team1 = list(set(team1))
unique_team2 = list(set(team2))
while len(enemy) != 0:
    old_team1 = copy.deepcopy(unique_team1)
    old_team2 = copy.deepcopy(unique_team2)
    i = 0
    while i < len(enemy):
        if len(team1) == 0 and len(team2) == 0:
            team1.append(enemy[i][0])
            team2.append(enemy[i][1])
        else:
            if enemy[i][0] in team1:
                if enemy[i][1] in team1:
                    bench += 1
                else:
                    team2.append(enemy[i][1])
            elif enemy[i][0] in team2:
                if enemy[i][1] in team2:
                    bench += 1
                else:
                    team1.append(enemy[i][1])
            elif enemy[i][1] in team1:
                team2.append(enemy[i][0])
            elif enemy[i][1] in team2:
                team1.append(enemy[i][0])
            else:
                i += 1
                continue
        enemy.pop(i)
    unique_team1 = list(set(team1))
    unique_team2 = list(set(team2))
    
    if  len(enemy) != 0 and (len(unique_team1) == len(old_team1) and len(unique_team2) == len(old_team2)):
            team1.append(enemy[0][0])
            team2.append(enemy[0][1])
            enemy.pop(0)
if (num_people - bench) % 2 != 0:
    bench += 1
          

print(bench)

