Gems = {'purple': 'Power', 'green': 'Time', 'blue': 'Space', 'orange': 'Soul', 'red': 'Reality', 'yellow': 'Mind'}
n = int(input())
b = []
for i in range(0, n):
    word = str(input())
    del Gems[word]
print(len(Gems))
for i in Gems:
    print(Gems[i])
