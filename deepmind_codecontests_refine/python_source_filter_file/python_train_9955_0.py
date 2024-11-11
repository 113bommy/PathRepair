line = input()
names_count = {"Danil": 0, "Olya": 0, "Slava": 0, "Ann": 0, "Nikita": 0}
for name in names_count.keys():
    while name in line:
        names_count[name] += 1
        line = line.replace(name, "#")
count = 0
for name in names_count.keys():
    count += names_count[name]
if count == 1:
    print("YES")
else:
    print("NO")