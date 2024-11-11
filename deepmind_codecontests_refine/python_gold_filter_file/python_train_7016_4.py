x = []
y = []
def unique(a):
    res = []
    res.append(a[0])
    for i in range(1, len(a)):
        if a[i] != a[i - 1]:
            res.append(a[i])
    return res

def process(x, y, a, b, n):
    if len(x) != 3 or len(y) != 3:
        return "ugly"
    check1 = False
    check2 = False
    for i in range(3):
        for j in range(3):
            flag = "ugly"
            if i != 1 or j != 1:
                for k in range(n):
                    if a[k] == x[i] and b[k] == y[j]:
                        flag = "respectable"
                if flag == "ugly":
                    return flag
    return "respectable"


for i in range(8):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)

a = x[:]
b = y[:]

x.sort()
y.sort()

x = unique(x)
y = unique(y)

# print(a)
# print(b)
# print(x)
# print(y)

print(process(x, y, a, b, 8))