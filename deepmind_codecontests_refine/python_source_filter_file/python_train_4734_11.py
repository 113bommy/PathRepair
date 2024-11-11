a=str(input())
a=a.strip(' ').strip('?').strip(' ')
a=a.casefold()
if a[-1]=='A' or a[-1]=='E' or a[-1]=='O' or a[-1]=='U' or a[-1]=='I' or a[-1]=='Y':
    print("YES")
else:
    print("NO")