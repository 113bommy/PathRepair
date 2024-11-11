n = int(input())
a = input()
i = 0
b = list()
while i < len(a) // 2 * 2:
    try:
        if a[i] != a[i + 1]:
            i += 2
        else:
            b.append(i)
            i += 1
    except:
        break
if (len(a) - len(b)) % 2 != 0:
    b.append(len(a) - 1)
print(len(a) - len(b))
j = 0
for i in range(len(a)):
    if j < len(b) and b[j] == i:
        j += 1
        continue
    else:
        print(a[i], end="")
