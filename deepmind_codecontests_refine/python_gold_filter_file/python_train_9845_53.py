input()
gameResults = input()
antonWins = sum(x == "A" for x in gameResults)
if 2*antonWins > len(gameResults):
    print("Anton")
elif antonWins*2 == len(gameResults):
    print("Friendship")
else:
    print("Danik")