string = input()

letters = ["a", "e", "i", "o", "u"]

count = 0
for i in string:
    if i in letters:
        count += 1
    elif i.isnumeric() and int(i) != 0:
        count += 1

print(count)