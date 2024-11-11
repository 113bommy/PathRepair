def printArr(a):
    print(len(a), end=' ')
    for x in a:
        print(x, end=' ')
    print()

n = int(input())
a = list(map(int, input().split()))
neg = [x for x in a if x < 0]
pos = [x for x in a if x > 0]

a1 = [neg.pop()]
if len(pos) > 0:
    a2 = [pos.pop()]
else:
    a2 = [neg.pop(), neg.pop()]

a3 = neg + pos + [0]

printArr(a1)
printArr(a2)
printArr(a3)
