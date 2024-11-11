string = input()
l = len(string)
a = 0
b = l - 1
new_string = ''
if l % 2 == 0:
    i = 0
    while a <= b:
        if i % 2 == 0:
            new_string = new_string + string[a]
            a += 1
        else:
            new_string = new_string + string[b]
            b -= 1
        i += 1
else:
    i = 0
    while a <= b:
        if i % 2 == 0:
            new_string = new_string + string[b]
            b -= 1
        else:
            new_string = new_string + string[a]
            a += 1
        i += 1
    print(new_string)
new_new_string = ''
if l % 2 == 0:
    for i in range(1, (l + 2) // 2):
        new_new_string = new_new_string + new_string[l - (i * 2)] + new_string[l - (i * 2) + 1]
else:
    new_new_string = new_new_string + new_string[l - 1]
    for i in range(1, l // 2 + 1):
        new_new_string = new_new_string + new_string[l - (i * 2)] + new_string[l - (i * 2) - 1]
print(new_new_string)