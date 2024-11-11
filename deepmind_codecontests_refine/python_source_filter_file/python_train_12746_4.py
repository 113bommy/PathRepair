str = input()
s = "AHMITUVWXY"
for i in range(len(str)):
    if s.count(str[i])==0:
        print("NO")
        exit()
    if str[i]!=str[len(str)-i-1]:
        print("NO")
        exit()

print("YES")