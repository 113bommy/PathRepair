name = input()
letters = ""

for i in range(len(name)):
    if name[i] not in letters:
        letters += name[i]

if len(letters)%2 == 0:
    print("CHAT WITH HER")
else:
    print("IGNORE HIM")