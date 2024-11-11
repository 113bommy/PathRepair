import sys

players = input()

repeat = 0
determine = 0

resultOfAll = "NO"

while repeat < len(players)-1:
    repeat+=1
    if players[repeat] == players[repeat-1]:
        determine += 1
        if determine >= 7:
            resultOfAll = "YES"
            print(resultOfAll)
            sys.exit(0)
    else:
        determine = 0
        
print(resultOfAll)