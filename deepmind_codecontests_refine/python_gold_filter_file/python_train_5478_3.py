l = []

for i in range(int(input())):

    n = int(input())
    l.append(n)

test = list(set(l))
if len(test)==2:
    if l.count(test[0]) == l.count(test[1]):
        print("YES")
        print(*test)
    else:
        print("NO")
else:
    print("NO")