line = input()
line = line.split()
n = int(line[0])
k = int(line[1])
line = input()
line = line.split()
team = 0
for i in range(0,n):
    line[i] = int(line[i])
    if(line[i] >= (5 - k)):
        team = team + 1
print(team//3)