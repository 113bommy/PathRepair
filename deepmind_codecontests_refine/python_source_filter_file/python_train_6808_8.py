s = input()
num = ""
i = 0
while i < len(s):
    if s[i] == '.':
        num += '0'
    else:
        if s[i:i + 2] == "_.":
            num += "1"
            i += 1
        else:
            num += "2"
            i += 1
    i += 1
print(num)
