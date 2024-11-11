d = {'a', 'e', 'i', 'o', 'u', 'y'}

n = int(input())
s = list(input())

found = -1
while 1:
    found = -1
    for i in range(len(s) - 1):
        if s[i] in d and s[i + 1] in d:
            found = i
            break
    if (found == -1):
        break
    s.pop(found)
print(*s, sep="")