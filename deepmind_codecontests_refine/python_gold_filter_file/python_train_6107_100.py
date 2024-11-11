string1 = str(input())
stringList = list(map(str, string1))

count = 1
yes = False
for i in range(1, len(stringList)):
    if stringList[i] == stringList[i-1]:
        count += 1
    else:
        count = 1
    if count >= 7:
        yes = True
if yes:
    print("YES")
else:
    print("NO")
