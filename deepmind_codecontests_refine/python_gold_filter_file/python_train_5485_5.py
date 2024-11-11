def sortBy(inputStr):
    return len(inputStr)
n = int(input())
a = []
for i in range(n):
    a.append(input())
a.sort(key=sortBy)
b = True
for i in range(n-1):
    if a[i] in a[i+1]:
        b = True
    else:
        b = False
        break
if b:
    print("YES")
    for i in a:
        print(i)
else:
    print("NO")
