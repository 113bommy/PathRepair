s=input()
c,d=0,0
for i in s:
    if i=="4":
        c+=1
    elif i=="7":
        d+=1
if c>d:
    print("4")
elif d>c:
    print("7")
elif d==c and d!=0:
    print("4")
else:
    print("-1")
