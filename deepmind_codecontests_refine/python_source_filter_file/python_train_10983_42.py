line = input()
upper=0
lower=0
for i in range(len(line)-1):
    if line[0].islower():
        lower += 1
    else:
        upper += 1

if lower > upper or lower == upper:
    print(line.lower())
else:
    print(line.upper())
