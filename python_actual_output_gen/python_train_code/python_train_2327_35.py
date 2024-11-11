numberOfGames = int(input())

games = [list(map(int, input().split())) for i in range(numberOfGames)]

count = 0

for game in games:
    if game[1] - game[0] > 0:
        count += 1
    elif game[1] - game[0] < 0:
        count -= 1

print("Mishka" if count < 0 else "Chris" if count > 2 else "Friendship is magic!^^")