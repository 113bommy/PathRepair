x = int(input())
s = input()
ansl = 0
ansd = 0
for i in s:
    if i =="L":
        ansl += 1
    if i == "R":
        ansl -= 1
    if i == "D":
        ansd += 1
    if i == "U":
        ansd += 1
ansl = abs(ansl)
ansd = abs(ansd)
print(x - (ansd+ansl))