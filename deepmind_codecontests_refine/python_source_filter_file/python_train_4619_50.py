repititions = int(input())
implement = 0
for a in range(repititions):
    x = input()
    count = 0
    if x[0] == "1":
        count += 1
    if x[2] == "1":
        count += 1
        if count >= 2:
            implement += 1
    if x[4] == "1":
        count += 1
        if count >= 2:
            implement += 1

print(implement)
