n, k = [int(i) for i in input().split()]

y = [int(i) for i in input().split()]

team = 0

for i in y:
    if i < 5 - k or i == 0:
        team += 1

print(int(team / 3))
