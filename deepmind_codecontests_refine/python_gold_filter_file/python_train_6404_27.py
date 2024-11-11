m = str(input())
n = str(input())
t = list()
for i in range(len(m)):
    if m[i] == n[i]:
        t.append(0)
    else:
        t.append(1)
for i in t:
    print(i, end = '')
