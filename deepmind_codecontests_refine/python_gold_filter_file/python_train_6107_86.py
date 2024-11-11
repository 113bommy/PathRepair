a = list(input())
isBad = False

for i in range(len(a) - 1):
    j = i + 1
    count = 1
    while j < len(a) and a[i] == a[j]:
        count = count + 1
        j = j + 1
    if count >= 7:
        isBad = True

if isBad:
    print("YES")

else:
    print("NO")
