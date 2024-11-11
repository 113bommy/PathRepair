def roll(die, d):
    if d == "E":
        return [die[3], die[1], die[0], die[5], die[4], die[2]]
    if d == "N":
        return [die[1], die[5], die[2], die[3], die[0], die[4]]
    if d == "S":
        return [die[4], die[0], die[2], die[3], die[5], die[1]]
    if d == "W":
        return [die[2], die[1], die[5], die[0], die[4], die[3]]
    if d == "L":
        return [die[0], die[3], die[1], die[4], die[2], die[5]]
    if d == "R":
        return [die[0], die[2], die[4], die[1], die[3], die[5]]

def checkdice(die1, die2):
    ans = "No"
    for d in "RRRNRRRNRRRSRRRSRRRNRRR":
        if die1 == die2:
            ans = "Yes"
            break
        die2 = roll(die2, d)
    return ans

die1 = list(map(int, input().split()))
die2 = list(map(int, input().split()))
print(checkdice(die1, die2))