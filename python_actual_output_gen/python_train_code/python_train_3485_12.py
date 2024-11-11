testCase = int(input())

for i in range(testCase):
    can = True
    wordsGetsu = int(input())
    alphabet = []
    getsu = []
    for j in range(wordsGetsu):
        word = input()
        for k in word:
            if k not in alphabet:
                alphabet.append(k)
                getsu.append(1)
            else:
                getsu[alphabet.index(k)] += 1
    for j in getsu:
        if j // wordsGetsu == 0:
            print("NO")
            can = False
            break
    if can:
        print("YES")
