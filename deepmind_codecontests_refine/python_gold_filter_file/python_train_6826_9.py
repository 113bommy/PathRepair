challenger = []
for _ in range(int(input())):
    player = input().split()
    challenger.append([player[0],sum([int(i) for i in player[3:]])+100*int(player[1])-50*int(player[2])])
challenger.sort(key=lambda x:x[1])
print(challenger[-1][0])