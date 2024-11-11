string = input()

i = 0
last = 0
total = 0
while i < len(string)-3:
    if string[i]=='b' and string[i+1]=='e' and string[i+2]=='a' and string[i+3]=='r':
        total += (i+1) * (len(string)-i-3)
        string = string[i+1:]
        i -= 1

    i += 1

print(total)
