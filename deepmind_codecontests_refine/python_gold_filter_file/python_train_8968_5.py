word = input()
count = 0
oser = []
wser = []

for i in range(1, len(word)):
    if word[i] == "v" and word[i-1] == "v":
        count += 1
    elif word[i] == "o":
        oser.append(i+1)
        wser.append(count)

wow = 0
for j in range(len(oser)):
    leftv = wser[j]
    rightv = count - leftv
    if leftv > 0 and rightv > 0:
        wow += ((leftv)*(rightv))
    else:
        wow += 0

print(int(wow))