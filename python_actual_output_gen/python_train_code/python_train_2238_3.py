count = int(input())
robo = list(map(int,input().split()))
bionic = list(map(int,input().split()))
robo_score = 0
bionic_score = 0
for i in range(count):
    if robo[i] == 0 and bionic[i] == 1:
        bionic_score = bionic_score + 1
    if robo[i] == 1 and bionic[i] == 0:
        robo_score = robo_score + 1
if robo_score == 0:
    print(-1)
else:
    print(round(bionic_score/robo_score) + 1)