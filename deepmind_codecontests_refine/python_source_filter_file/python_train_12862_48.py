import re
num_rows = int(input())

bus = []

first = True

for i in range(num_rows):
    temp = input()
    if "OO" in temp and first:
        first = False
        temp = re.sub("OO", "++", temp)
    bus.append(temp)

if not first:
    print("YES")
    print(*bus, sep="\n")
else:
    print("NO")