s = input()

for i in range(len(s)+1):
    for j in range(i,len(s)+1):
        if s[:i] + s[i + j:] == "keyence":
            print("YES")
            exit()

print("NO")