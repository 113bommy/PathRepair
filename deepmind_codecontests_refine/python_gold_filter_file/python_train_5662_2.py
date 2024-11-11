a=input()
b=input()
if a==b:
    print("YES")
elif len(a)!=len(b):
        print("NO")
elif a.count('1')==0 and b.count('1')!=0:
    print("NO")
elif b.count('1')==0 and a.count('1')!=0:
    print("NO")
else:
    print("YES")