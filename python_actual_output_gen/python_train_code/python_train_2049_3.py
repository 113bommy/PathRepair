input()
s = input()
for i in range(len(s)-1):
    if len(set(s[i:i+3])) == 2:
        print("YES")
        print(s[i:i+2])
        exit()
print("NO")
