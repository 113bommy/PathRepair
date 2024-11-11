inp = input()
count = 0
names = ["Danil", "Olya", "Slava", "Ann", "Nikita"]
for name in names:
    count += inp.count(name)
print("YES") if count == 0 else print("NO")
