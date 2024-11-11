s = []
for i in range(4):
    s.append(input())

b = False
for i in range(3):
    for j in range(3):
        if (s[i][j]==s[i][j+1]):
            if s[i][j] in s[i+1][j:j+2]:
                b = True;
        if s[i+1][j]==s[i+1][j+1]:
            if s[i+1][j] in s[i][j:j+2]:
                b = True
if b:
    print("YES")
else:
    print("NO")