
inputs = []
for i in range(3):
    inpt = input()
    inputs.append(inpt)

res = 0

for i in zip(inputs[1], inputs[2]):
    if int(i[0]) == int(i[1]):
        pass
    elif abs(int(i[0]) - int(i[1])) >= 6:
        if int(i[0]) < int(i[1]):
            res += int(i[0]) + (10 - int(i[1]))
        else:
            res += int(i[1]) + (10 - int(i[0]))
    else:
        if int(i[0]) > int(i[1]):
            res += int(i[0]) - int(i[1])
        else:
            res += int(i[1]) - int(i[0])
    #print(res, i)

#print(res)
