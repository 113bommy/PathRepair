import sys

dice = [int(i) for i in sys.stdin.readline().split()]
command = sys.stdin.readline().strip()
for c in command:
    if c == "N":
        dice = (dice[1], dice[5], dice[2], dice[3], dice[0], dice[4])
    elif c == "S":
        dice = (dice[4], dice[0], dice[2], dice[3], dice[5], dice[2])
    elif c == "W":
        dice = (dice[2], dice[1], dice[5], dice[0], dice[4], dice[3])
    elif c == "E":
        dice = (dice[3], dice[1], dice[0], dice[5], dice[4], dice[2])
print(dice[0])