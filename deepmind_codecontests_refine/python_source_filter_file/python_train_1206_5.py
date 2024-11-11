s = input()
new = "heidi"
found = 0
for i in range (len(s)):
    if s[i] == new[found]:
        found += 1
        if found == len(new):
            print("YES")
            break
    else:
        continue
print("NO")