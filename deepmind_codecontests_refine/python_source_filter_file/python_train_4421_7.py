import sys

letters = map(int, sys.stdin.readline().rstrip())


total = 0
inInbox = True
letters = list(map(str, sys.stdin.readline().rstrip().split(" ")))

for l in letters:
    if l == "1":
        total += 1
        inInbox = False
    elif l == "0" and inInbox == False:
        inInbox = True
        total += 1

if letters[-1] == "0":
    total -= 1

print(total)
