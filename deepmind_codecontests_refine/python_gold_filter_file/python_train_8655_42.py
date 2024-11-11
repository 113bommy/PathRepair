s = input()
s = list(s)


a = 0
b = 0
x = 0
for i in range(len(s)):
    if s[i] == "a":
        a += 1
    else:
        b+= 1

while a <= b:
    del s[0]
    b-= 1
    x += 1

print(len(s))

