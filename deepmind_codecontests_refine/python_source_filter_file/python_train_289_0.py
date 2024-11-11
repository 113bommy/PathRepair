s = input()
S = len(s)

for i in range(S-1):
    for j in range(i+1,S):
        if s[:i]+s[j:] == "keyence":
            print("YES")
            exit()

print("NO")