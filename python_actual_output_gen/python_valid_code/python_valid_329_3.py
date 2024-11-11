n = int(input())
SherlockCard = list(map(int, input()))
MoriaryCard = list(map(int, input()))
S = 0
M = 0

SherlockCard.sort()
MoriaryCard.sort()

print("S",SherlockCard)
print("M",MoriaryCard)


j = 0
for i in range(n):
    # print(MoriaryCard[i], " and ", SherlockCard[i])
    if MoriaryCard[i] >= SherlockCard[j]:
        j+=1
    else:
        S+=1
print(S)

j=n-1
for i, e in reversed(list(enumerate(MoriaryCard))):
    if MoriaryCard[j] > SherlockCard[i]:
        M+=1
        j-=1
print(M)