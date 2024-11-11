i = int(input())


def isgood(i):
    i = str(i)
    for j in i:
        if i.count(j) > 1:
            return False
    return True

while not isgood(i):
    i += 1

print(i)
