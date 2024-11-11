string = input()
count = 0
othercount = 0
for i in range(len(string)):
    if string[i] == "a":
        count += 1
    else:
        othercount += 1
if count >= len(string)/2:
    print(len(string))
else:
    print(count*2 - 1)
    