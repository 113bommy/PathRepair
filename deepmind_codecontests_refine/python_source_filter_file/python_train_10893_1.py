import string

n = int(input())

L = [0]*10
leaded = [False]*10

for i in range(n):
    word = input()
    for i in range(len(word)):
        char = word[-(i+1)]
        L[ord(char) - ord('a')] += 10**i
    leaded[ord(word[0]) - ord('a')] = True

print(L)

total = 0
index = 1
zeroed = False
while sum(L) > 0:
    t = max(L)
    place = L.index(t)
    if leaded[place] == False and not zeroed:
        zeroed = True
    else:
        total += index*t
        index += 1

    L[place] = 0

print(total)
