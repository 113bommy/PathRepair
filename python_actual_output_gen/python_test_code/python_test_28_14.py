s = input()
lowerCount = 0
upperCount = 0
for i in s:
    if(i.islower()):
        lowerCount += 1
    else:
        upperCount += 1
if(lowerCount <= upperCount):
    print(s.lower())
else:
    print(s.upper())