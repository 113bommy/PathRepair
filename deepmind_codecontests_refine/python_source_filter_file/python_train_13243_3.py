n, k = map(int, input().split())
deck = []
for _ in range(n):
    deck.append(input())
ans = 0
deck.sort()

def thirdChar(a, b):
    if a == b:
        return a
    if (a == 'S' and b == 'T') or (a == 'T' and b == 'S'):
        return 'E'
    if (a == 'S' and b == 'E') or (a == 'E' and b == 'S'):
        return 'T'
    if (a == 'E' and b == 'T') or (a == 'T' and b == 'E'):
        return 'S'

def findThird(c1, c2):
    l = []
    for i in range(k):
        l.append(thirdChar(c1[i], c2[i]))
    return ''.join(l)

def binarySearch(sortedList, elem):
    l = 0
    r = len(sortedList) - 1
    while l <= r:
        m = (l+r) // 2
        if elem == sortedList[m]:
            return m
        if elem > sortedList[m]:
            l = m+1
        else:
            r = m-1
    return -1

for i, c1 in enumerate(deck):
    for c2 in deck[i+1:]:
        c3 = findThird(c1, c2)
        if binarySearch(deck, c3) != -1:
            ans += 1
print(ans)
