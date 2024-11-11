s = str(input())
a = list(map(str,input().split()))
for i in range(0,5):
    x = 0
    x1 = 0
    if a[i][0]=="T":
        x = 10
    elif a[i][0]=="J":
        x = 11
    elif a[i][0]=="Q":
        x = 12
    elif a[i][0]=="K":
        x = 13
    elif a[i][0]=="A":
        x = 14
    else:x = int(a[i][0])
    if s[0]=="T":
        x1 = 10
    elif s[0]=="J":
        x1 = 11
    elif s[0]=="Q":
        x1 = 12
    elif s[0]=="K":
        x1 = 13
    elif s[0]=="A":
        x1 = 14
    else:x1 = int(s[0])
    if x >= x1 or a[i][1]==s[1]:
        print("YES")
        exit()
print("NO")
