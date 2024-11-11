def sort_MxMn(SeriesA):
    global max_a, min_a
    listA = list(str(SeriesA))
    while len(listA) < b:
        listA.append("0")
    listA = [int(x) for x in listA]
    max_a = sorted(listA, reverse=True)
    min_a = sorted(listA)

def translate(listEx):
    num = 0
    for i in range(b):
        num += listEx[i]*(10 ** (b-i-1))
    return num

for k in range(10):
    a, b = map(int, input().split())
    if a + b ==0:
        break
    c = []
    for i in range(10):
        c.append(a)
        sort_MxMn(a)
        a = translate(max_a) - translate(min_a)
        if (a in c) == True:
            print("{} {} {}".format(c.index(a), a, i - c.index(a) + 1))
            break

