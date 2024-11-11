s = input()
for i in range(7):
    if s[i] + s[-7 + i] == "keyence":
        print("YES")
        exit()
print("NO")