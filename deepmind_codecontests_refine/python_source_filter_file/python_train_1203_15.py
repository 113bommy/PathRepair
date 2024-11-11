s = input()
c = 0
fa = 0
count = 1
while c < len(s):
    if s[c] == "A" or s[c] == "E" or s[c] == "I" or s[c] == "O" or s[c] == "U" or s[c] == "Y":
        if fa < count:
            fa = count
        count = 1
    else:
        count += 1
    c += 1
print(fa)