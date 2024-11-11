from collections import Counter

t = int(input())

for i in range(t):
    n = int(input())
    numCollections = []
    letters = ['a', 'b', 'c', 'd', 'e']
    for l in letters:
        numCollections.append([])
    for j in range(n):
        word = input()
        mostCommon = Counter(word)
        for l in range(len(letters)):
            numCollections[l].append(mostCommon[letters[l]] - len(word) / 2)
    for l in numCollections:
        l.sort(reverse=True)
   # print(numCollections)
    maxTotal = 0
    for l in numCollections:
        counter = 0
        total = 0
        for num in l:
            total += num
            if total <= 0:
                break
            else:
                counter += 1
        maxTotal = max(maxTotal, counter)
    print(maxTotal)
