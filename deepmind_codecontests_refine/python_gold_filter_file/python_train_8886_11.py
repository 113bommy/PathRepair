numofstones = input()

colours = input()

lll = list()

for c in colours:
    lll.append(c)

#print(lll)

indextoremove = list()

#print(lll[:-1])

count = 0
for letter in lll[:-1]:
    #print(lll[lll.index(letter, count) + 1])

    if lll[lll.index(letter, count) + 1] == letter:
        if lll[lll.index(letter, count) + 1] not in indextoremove:
            indextoremove.append(lll.index(letter,count))


    count += 1



print(len(indextoremove))

