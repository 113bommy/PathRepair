s = input()

i = s.find('at')
s = s[:i] + '@' + s[i+2:]

while True:
    i = s[1:].find('dot')
    if i == -1:
        break
    i += 1
    if i+3 == len(s):
        break
    s = s[:i] + '.' + s[i+3:]
print(s)
