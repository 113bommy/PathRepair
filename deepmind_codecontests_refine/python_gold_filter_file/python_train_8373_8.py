a = input()
b = input()
letters = []
count = []
flag = "YES"

def findIndex(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1


def countLetter(c, x):
    count = 0
    for i in c:
        if i == x:
            count += 1
    return count

for i in a:
    if i != " ":
        j = findIndex(letters, i)
        if j == -1:
            count.append(1)
            letters.append(i)
        else:
            count[j] += 1

for i in b:
    if i != " ":
        j = findIndex(letters, i)
        if j == -1:
            flag = "NO"
        else:
            if countLetter(b, i) > count[j]:
                flag = "NO"

print(flag)
