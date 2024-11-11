def check(i):
    s = 0
    for x in b:
        s += x
        if s == i:
            s = 0
    if s == 0:
        return True
    return False
a = int(input())
b = [int(i) for i in list(input())]
for i in range(sum(b)):
    if check(i):
        print("YES")
        break
else:
    print("NO")