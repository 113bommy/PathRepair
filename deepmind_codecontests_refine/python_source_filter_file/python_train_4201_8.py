s = input()

a, b = 0,0

for i in range(1, len(s)):
    if s[i].islower():
        a += 1
    elif s[i].isupper() and a > 0:
        a -= 1
        b += 1
print(b)