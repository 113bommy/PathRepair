

s = input()

pokemon = "Bulbasaur"
number = []

for i in pokemon:
    count = 0
    for j in s:
        if i == j:
            count += 1
    if i == 'a' or 'u':
        count = int(count/2)
    number.append(count)

print(min(number))