a = []
for _ in range(3):
    d = 0
    k = input().split(" ")
    for i in k:
        for x in i:
            if x == "a" or x == "i" or x == "e" or x == "o" or x == "u":
                d += 1
    a.append(d)
print("NO" if a[0] != 5 or a[1] != 7 or a[2] != 5 else "YES")