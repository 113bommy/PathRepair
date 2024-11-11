a=input()
b=input()
c=input()
if a==c and b[0]==b[2]:
    print("YES")
elif a[0]==a[2] and c[0]==c[2] and b[0]==b[2] and a[1]==c[1]:
    print("YES")
elif a[2]==c[0] and a[1]==b[2] and a[0]==c[2] and b[0]==c[1]:
    print("YES")
elif a[0]==c[2] and a[2]==c[0] and a[1]==b[0] and b[2]==c[1]:
    print("YES")
elif a[0]==c[2] and a[2]==c[0] and a[1]==c[1] and b[0]==c[0]:
    print("YES")
else:
    print("NO")