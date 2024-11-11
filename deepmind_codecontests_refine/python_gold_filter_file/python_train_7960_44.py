n = int(input())
rdl = input()
toAnswer =[[0],[0],[2],[3],[3,2,2],[5],[5,3],[7],[7,2,2,2],[7,3,3,2]]
answer = []
for i in range(len(rdl)):
    answer.append(toAnswer[int(rdl[i])])
for i in answer:
    i.sort()
    i = i[::-1]
answer.sort()
answer = answer[::-1]
newanwer = []
for i in answer:
    for j in i:
        newanwer.append(j)
newanwer.sort()
while newanwer[0] == 0:
    newanwer = newanwer[1:]
newanwer = newanwer[::-1]
for i in newanwer:
        print(i, end='')
