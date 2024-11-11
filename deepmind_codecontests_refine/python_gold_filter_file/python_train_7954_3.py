'''input
41^52==
'''

s = input()
bpoint = s.split('^')

leftT = 0
rightT = 0
leftLen = len(bpoint[0])
for index, i in enumerate(bpoint[0]):
    if i != '=':
        leftT += (leftLen - index)*int(i)

for index, i in enumerate(bpoint[1]):
    if i != '=':
        rightT += (index+1)*int(i)

# print(leftT, rightT)
if(leftT > rightT):
    print("left")
elif(rightT > leftT):
    print("right")
else:
    print("balance")